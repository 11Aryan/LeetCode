//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    unordered_map<char,int>m;
    int l=0,r=0,length=-1;
    while(l<s.length()&&r<s.length())
    {
        m[s[r]]++;
        if(m.size()>k)
        {
            while(m.size()>k&&!m.empty())
            {
                m[s[l]]--;
                
                if(m[s[l]]==0)
                {
                    m.erase(s[l]);
                }
               l++;
            }
        }    
            
        if(m.size()==k)
          length=max(length,r-l+1);
        r++;
    }
    return length;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends