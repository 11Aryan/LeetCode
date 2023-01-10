//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{   
    vector<string> solve(string s)
    { 
         vector<string>ans;
         sort(s.begin(),s.end());
         do
         {
             ans.push_back(s);
         }while(next_permutation(s.begin(),s.end()));
         return ans;
       
    }
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    return solve(S);
		    
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends