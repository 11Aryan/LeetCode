//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        stack<char>ans;
        for(int i=0;i<s.length();i++)
        {   
            if(ans.size()>0&&ans.top()==s[i])
               ans.pop();
            else
               ans.push(s[i]);
            
        }
        string aa="";
        string a="-1";
        if(ans.size()==0)
          return a;
        while(ans.size()>0)
        {
            aa+=ans.top();
            ans.pop();
        }
        reverse(aa.begin(),aa.end());
        return aa;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends