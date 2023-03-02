//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{   
    private:
    int f(int r,int c,vector<vector<int>>&dp)
    {
        if(r==0&&c==0)
          return 1;
        if(r<0||c<0)
          return 0;
        if(dp[r][c]!=-1)return dp[r][c];
        int up=f(r-1,c,dp);
        int left=f(r,c-1,dp);
        return dp[r][c]=up+left;    
    }
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int m, int n)
    {
        //code here
         vector<vector<int>>dp(m,vector<int>(n,-1));
         return f(m-1,n-1,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends