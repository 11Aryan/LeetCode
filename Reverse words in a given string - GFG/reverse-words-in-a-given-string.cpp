//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        stack<char>s;
        string a="";
        vector<string>ans;
        string f="";
        for(int i=0;i<S.length();i++)
        {
            s.push(S[i]);
        }
        while(!s.empty())
        {
            int c=s.top();
            
            if(c=='.')
             {   
                 reverse(a.begin(),a.end());
                 ans.push_back(a);
                 ans.push_back(".");
                 a="";
             }
            else
            {
               a+=c;
                
            }
            s.pop();
        }
        reverse(a.begin(),a.end());
        ans.push_back(a);
        for(int i=0;i<ans.size();i++)
         f+=ans[i];
        return f; 
        
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends