class Solution {
public:
    bool isPalindrome(int x) {
            long long d,n,ans=0;
            n=x;
            while(n>0)
             {
              d=n%10;
             ans=ans*10+d;
             n=n/10;
             }
            if(n<0)
                return false;
             return (ans==x);
                 
                 
        
}};