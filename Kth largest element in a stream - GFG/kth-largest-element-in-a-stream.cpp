//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
        priority_queue<int,vector<int>,greater<int>>m;
        vector<int>v;
        for(int i=0;i<n;i++)
        {   
            m.push(arr[i]);
            if(m.size()<k)
             {
              v.push_back(-1);
             }
             else if(m.size()==k)
             {
                 v.push_back(m.top());
             }
             else
             {   
                 m.pop();
                 v.push_back(m.top());
             }
              
        }
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends