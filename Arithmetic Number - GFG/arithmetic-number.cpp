//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int A, int B, int C){
        // code here
        if(A==B)
          return 1;
        if(C==0&&A!=B)
          return 0;
        int a=A;
        int d=C;
        int r,n;
        n=(B-a)/d;
        r=(B-a)%d;
        if(n>=0&&r==0)
          return 1;
        return 0;  
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
// } Driver Code Ends