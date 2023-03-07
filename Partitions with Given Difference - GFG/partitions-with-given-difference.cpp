//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    int f(int i,vector<int>& arr,int sum,int n,vector<vector<int>>&dp,int m)
    {  
    
        if(i==0)
        {
            if(sum==0&&arr[0]==0) return 2;
            if(sum==0||arr[0]==sum) return 1;
            return 0;
        }
          
        if(dp[i][sum]!=-1) return dp[i][sum];
        int take=0;
        
        if(arr[i]<=sum) 
        take=f(i-1,arr,sum-arr[i],n,dp,m);
        
        int notTake=f(i-1,arr,sum,n,dp,m);
        
        return dp[i][sum]=(take+notTake)%m;
          
    }
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int m=1e9+7;
        int sum=0;
        for(int i=0;i<n;i++)
         sum+=arr[i]%m;
        
        if((sum-d)%2||sum-d<0)
          return 0;
        vector<vector<int>>dp(n,vector<int>((sum-d)/2+1,-1));
        return f(n-1,arr,(sum-d)/2,n,dp,m);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends