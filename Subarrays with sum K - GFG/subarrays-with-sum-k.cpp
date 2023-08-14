//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        // code here
        
        //https://www.youtube.com/watch?v=xvNwoz-ufXA
        unordered_map<int,int>m;
        int sum=0;
        int count=0;
        m[0]=1;
        for(int i=0;i<N;i++)
        {
            sum+=Arr[i];
            count+=m[sum-k];
            m[sum]+=1;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends