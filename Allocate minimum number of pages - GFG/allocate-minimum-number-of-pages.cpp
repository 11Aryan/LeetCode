//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{  
    
    bool isPossible(int A[],int N,int M,int mid)
     {     
          int sum=0;
          int count=1;
          for(int i=0;i<N;i++)
          {  
              if(sum+A[i]<=mid)
                 {sum+=A[i];}
                
              else
              {
                  count++;
                  
                  if(count>M||A[i]>mid)
                    return false;
                  
                  sum=A[i];
                      
              }
          
          }
          
          return true;
    
     }
    
    
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
        }
        
        int s=0;
        int e=sum;
        int ans=-1;
        if(M>N)
          return ans;
        
        int mid=s+(e-s)/2;
        while(s<=e)
        {
            if(isPossible(A,N,M,mid))
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends