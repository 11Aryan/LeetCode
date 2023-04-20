//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i,int j,int di[],int dj[],vector<vector<int>> &m,vector<vector<int>>&visited,vector<string>&ans,int n,string s)
    {
        if(i==n-1&&j==n-1)
         {ans.push_back(s);
          return;
         }
        string dir="DLRU";
        for(int ind=0;ind<4;ind++)
        {
            int nexti=i+di[ind];
            int nextj=j+dj[ind];
            if(nexti<n && nexti>=0 && nextj<n && nextj>=0 && !visited[nexti][nextj] && m[nexti][nextj]==1)
            {
                visited[i][j]=1;
                solve(nexti,nextj,di,dj,m,visited,ans,n,s+dir[ind]);
                visited[i][j]=0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>>visited(n,vector<int>(n,0));
        vector<string>ans;
        string s="";
        int di[]={1,0,0,-1}; //D,L,R,U (di+dj)
        int dj[]={0,-1,1,0};
        if(m[0][0]==1)
          solve(0,0,di,dj,m,visited,ans,n,s);
        return ans;
        
    }
};

/*
bool isSafe(int newx,int newy,vector<vector<bool>>&visited,vector<vector<int>> &m,int n)
    {
        if((newx>=0&&newx<n)&&(newy>=0&&newy<n)&&(visited[newx][newy]!=1)&&(m[newx][newy]==1))
          return true;
        else
          return false;
    }
    
    void solve(int x,int y,vector<vector<int>> &m,int n,vector<string>&ans,vector<vector<bool>>&visited,string path )
    {
        if(x==n-1&&y==n-1)
        {
            ans.push_back(path);
            return;
        }
        visited[x][y]=1;
        //4 movements
        if(isSafe(x+1,y,visited,m,n))
        {
           solve(x+1,y,m,n,ans,visited,path+'D');
        }
        if(isSafe(x-1,y,visited,m,n))
        {
           solve(x-1,y,m,n,ans,visited,path+'U');
        }
        if(isSafe(x,y+1,visited,m,n))
        {
           solve(x,y+1,m,n,ans,visited,path+'R');
        }
        if(isSafe(x,y-1,visited,m,n))
        {
           solve(x,y-1,m,n,ans,visited,path+'L');
        }
        visited[x][y]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<bool>>visited(n,vector<bool>(n,0));
        vector<string>ans;
        string path="";
        if(m[0][0]==0)
         return ans;
        solve(0,0,m,n,ans,visited,path);
        return ans;
    }



*/


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends