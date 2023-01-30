//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSatisfy(int r,int c,vector<string>&board,int n)
    {
        int x=r;
        int y=c;
        
        while(y>=0)
        {
        if(board[x][y]=='Q')
           return false;
         y--;
        }
         
        x=r;
        y=c;
        
        
        while(y>=0&&x>=0)
        {
        if(board[x][y]=='Q')
           return false;
         y--;
         x--;
        }
           
           
        x=r;
        y=c;
        
        while(y>=0&&x<n)
        {
        if(board[x][y]=='Q')
           return false;
         y--;
         x++;
        }
    
    return true;        
              
    }
    void solve(int c,vector<vector<int>>&ans, vector<string>&board,int n,vector<int>&result)
    {
        if(c==n)
        {
            ans.push_back(result);
            return;
        }
        for(int r=0;r<n;r++)
        {
          if(isSatisfy(r,c,board,n))
          {
              board[r][c]='Q';
              result.push_back(r+1);
              solve(c+1,ans,board,n,result);
              board[r][c]='.';
              result.pop_back();
          }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<string> board(n,string(n,'.'));
        vector<vector<int>>ans;
        vector<int>result;
        solve(0,ans,board,n,result);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends