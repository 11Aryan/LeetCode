//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        // code here
       priority_queue<int>q;
       for(int i=0;i<N;i++)
       {
           q.push(-arr[i]);
       }
       int ans=0;
       while(q.size()>1)
       {   
           int sum=0;
           int t1=-q.top();
           q.pop();
           int t2=-q.top();
           q.pop();
            sum=t1+t2;
           q.push(-sum);
           ans+=sum;
           
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends