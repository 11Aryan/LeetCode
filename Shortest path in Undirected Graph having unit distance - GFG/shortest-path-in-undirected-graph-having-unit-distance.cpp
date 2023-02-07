//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        
        unordered_map<int,list<int>>adj;
        for(int i=0;i<M;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        unordered_map<int,bool>visited;
        vector<int>distance(N,-1);
        
        queue<int>q;
        q.push(src);
        visited[src]=1;
        distance[src]=0;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            for(auto neighbour:adj[front])
            {
                if(!visited[neighbour])
                {
                    visited[neighbour]=true;
                    q.push(neighbour);
                    distance[neighbour]=distance[front]+1;
                }
            }
            
        }
        
        return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends