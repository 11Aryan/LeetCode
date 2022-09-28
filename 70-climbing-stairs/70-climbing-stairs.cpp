class Solution {
public:
    int climbStairs(int n) {
    
        int a=1,b=0,ans;
        for(int i=0;i<n;i++)
        {
            ans=a+b;
            b=a;
            a=ans;
        }

       return ans;
    }
};