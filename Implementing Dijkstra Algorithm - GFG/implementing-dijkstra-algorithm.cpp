//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>ans(V,INT_MAX);
        
        set<pair<int,int>>a;
        a.insert({0,S});
        ans[S]=0;
        while(!a.empty())
        {   
            // to get top from set
            auto top=*(a.begin());
            
            int d=top.first;
            int node=top.second;
            
            a.erase(a.begin());
            
            for(auto neighbour:adj[node])
            {
                if(d+neighbour[1]<ans[neighbour[0]])
                {
                    auto record=a.find(make_pair(ans[neighbour[0]],neighbour[0]));
                    
                    if(record!=a.end())
                    {
                        a.erase(record);
                    }
                
                ans[neighbour[0]]=d+neighbour[1];
                a.insert(make_pair(ans[neighbour[0]],neighbour[0]));
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends