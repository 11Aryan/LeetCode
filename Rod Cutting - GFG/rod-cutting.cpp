//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    int f(int i,int price[],int n,vector<vector<int>>&dp)
    {
        if(i==0)
        {
            return n*price[0];
        }
        if(dp[i][n]!=-1) return dp[i][n];
        int notTake=0+f(i-1,price,n,dp);
        int take=INT_MIN;
        int rodLength=i+1;
        if(rodLength<=n)
           take=price[i]+f(i,price,n-rodLength,dp);
        return dp[i][n]=max(take,notTake);   
    }
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(n-1,price,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends