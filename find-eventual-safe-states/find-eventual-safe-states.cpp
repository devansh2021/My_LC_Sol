class Solution {
    bool dfs(vector<vector<int>>& g, int i, vector<int> &dp)
    {
        //vis >= 0 ->visited
        //vis = 1 -> cycle
        //vis = 2 -> safe node
        // cout<<i<<endl;
        // for(auto x:dp)
        //     cout<<x<<" ";
        // cout<<endl;
        if(dp[i]==1)
            return false;
        if(dp[i]==2)
            return true;
        if(dp[i]>=0)
            return 0;
        dp[i]=0;
        for(auto neigh:g[i])
            if(!dfs(g, neigh, dp))
                {
                dp[i]=-1;
                return !(dp[i]=1);}
        dp[i]=-1;
        return dp[i]=2;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        vector<int> ans;
        vector<int> dp(g.size(), -1);
        for(int i=0;i<g.size();i++)
            if(dfs(g, i, dp))
                ans.push_back(i);
        return ans;
    }
};