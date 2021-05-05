class Solution {
public:
    int jump(vector<int>& v) {
        vector<int> dp(v.size(), INT_MAX);
        dp[0]=0;
        for(int i=0;i<v.size();i++)
        {
            if(dp[i]!=INT_MAX)
            {
                for(int j=1;j<=v[i]&&i+j<v.size();j++)
                {
                    dp[i+j]=min(dp[i]+1, dp[i+j]);
                }
            }
        }
        return dp[v.size()-1];
    }
};