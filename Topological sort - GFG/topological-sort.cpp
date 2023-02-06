//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	//Using kahns algorithm(bfs)
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    queue<int>q;
	    vector<int>indegree(V);
	    for(int i=0;i<V;i++)
	    {
	        for(auto j:adj[i])
	        {
	            indegree[j]++;
	        }
	    }
	    vector<int>ans;
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	          q.push(i);
	    }
	    
	    while(!q.empty())
	    {
	        int front=q.front();
	        q.pop();
	        ans.push_back(front);
             
            for(auto neighbour:adj[front])
            {
                indegree[neighbour]--;
                if(indegree[neighbour]==0)
                   q.push(neighbour);
            }
	    }
	    return ans;
	}
	
	
	/* 
	                        USING DFS
	void toposort(int node,unordered_map<int,bool>&visited,stack<int>&s,vector<int>adj[])
	{
	    visited[node]=true;
	    for(auto neighbour:adj[node])
	    {
	        if(!visited[neighbour])
	          toposort(neighbour,visited,s,adj);
	    }
	    s.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    unordered_map<int,bool>visited;
	    stack<int>s;
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        {
	            toposort(i,visited,s,adj);
	        }
	    }
	    vector<int>ans;
	    while(!s.empty())
	    {
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}*/
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends