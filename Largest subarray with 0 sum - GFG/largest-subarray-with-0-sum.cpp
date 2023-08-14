//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int>m;
        int sum=0;
        int len=0;
        for(int i=0;i<A.size();i++)
        {
            sum+=A[i];
            
            if(sum==0) len=i+1;
            if(m.find(sum-0)!=m.end()) len=max(len,i-m[sum]);
            
            if(m.find(sum)==m.end()) m[sum]=i;
        }
        return len;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends