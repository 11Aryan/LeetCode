//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool isPossible(int n, int k, vector<int> &stalls, int mid)
    {
        int count=1;
        int pos=stalls[0];
        for(int i=0;i<n;i++)
        {
            if(stalls[i]-pos>=mid)
            {
                count++;
                if(count==k)
                 return true;
                pos=stalls[i];
            }
        }
        return false;
    }
    
    
public:

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        
        sort(stalls.begin(),stalls.end());
        int s=0;
        int e=stalls[n-1];
        int ans=-1;
        int m=s+(e-s)/2;
        while(s<=e)
        {
            if(isPossible(n,k,stalls,m))
            {
                ans=m;
                s=m+1;
            }
            else
            {
                e=m-1;
            }
            m=s+(e-s)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends