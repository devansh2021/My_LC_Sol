class Solution {
public:
    int dfs(vector<vector<int>>& v, int i, int j)
    {
        if(i>=v.size()||j>=v[0].size()||i<0||j<0||v[i][j]<=0)
            return 0;
        v[i][j]=-v[i][j];
        int ans=0;
        ans=max({dfs(v, i+1, j),dfs(v, i, j+1),dfs(v, i-1, j),dfs(v, i, j-1)});
        v[i][j]=-v[i][j];
        return v[i][j]+ans;
    }
    int getMaximumGold(vector<vector<int>>& v) {
        int m=v.size();
        int n=v[0].size();
        int ans=INT_MIN;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=max(ans, dfs(v, i, j));
            }
        }
        return ans;
    }
};