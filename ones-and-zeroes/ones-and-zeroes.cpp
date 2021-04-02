class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz=strs.size();
        vector<vector<int>> cnt(sz, vector<int>(2));
        for(int i=0;i<sz;i++)
        {
            for(auto c:strs[i])
            if(c=='0')
            cnt[i][0]++;
            else
                cnt[i][1]++;
        }
        vector<vector<vector<int>>> dp(sz+1, vector<vector<int>>(m+1, vector<int>(n+1, 0))); 
        for(int i=1;i<=sz;i++)
        {
            int zeros=cnt[i-1][0];
            int ones=cnt[i-1][1];
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=n;k++)
                {
                   if (j>=zeros && k>=ones) {
                    dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-zeros][k-ones]+1);
                } else {
                    dp[i][j][k] = dp[i-1][j][k];
                }     
                }
            }
        }
        return dp[sz][m][n];
    }
};