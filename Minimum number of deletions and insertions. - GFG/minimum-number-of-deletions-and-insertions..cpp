//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	private:
	int longestCommonSubsequence(string text1, string text2) {
         int n=text1.size(); 
         int m=text2.size();
         vector<vector<int>>dp(n+1,vector<int>(m+1,0));
         for(int i=0;i<=n;i++) dp[i][0]=0;
         for(int j=0;j<=m;j++) dp[0][j]=0;
         for(int i=1;i<=n;i++)
         {
             for(int j=1;j<=m;j++)
             { 
            //match     
            if(text1[i-1]==text2[j-1])  
                dp[i][j]=1+dp[i-1][j-1];
           //not match
           else
              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
             }
         }
         return dp[n][m];
    }
	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    return str1.size()+str2.size()-2*longestCommonSubsequence(str1,str2);
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends