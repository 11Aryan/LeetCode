//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    {   
        // Complete the function
        int len=0;
        unordered_map<int,int>m;
        int sum=0;
        for(int i=0;i<N;i++)
        {   
            sum+=A[i];
            
            if(sum==K) len=i+1;
            
            if(m.find(sum-K)!=m.end())
            {
                len=max(len,i-m[sum-K]);
            }
            if(m.find(sum)==m.end()) m[sum]=i;
        }
        return len;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends