//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        vector<int>ans;
        int result=0;
        unordered_map<int,int>count;
        for(int i=0;i<k;i++)
        {
            count[A[i]]++;
            if(count[A[i]]==1)
              result++;
              
        }
        ans.push_back(result);
        
        for(int i=k;i<n;i++)
        {   
            count[A[i-k]]--;
            if(count[A[i-k]]==0)
              result--;
            
             
            count[A[i]]++;
            if(count[A[i]]==1)
              result++;
            
             ans.push_back(result);  
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends