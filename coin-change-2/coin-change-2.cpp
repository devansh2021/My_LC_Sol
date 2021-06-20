class Solution {
public:
    int change(int t, vector<int>& c) {
        int n=c.size();
        vector<int> dp(t+1);
        dp[0]=1; 
        for(auto x:c)
        {
            for(int i=x;i<=t;i++)
             {
                if(i-x>=0)
                    dp[i]+=dp[i-x];
            }
        }
        return dp[t];
    }
};