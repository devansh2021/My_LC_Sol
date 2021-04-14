class Solution {
public:
    int m, n;
    int dfs (vector<vector<int>>& g, int r, int c)
    {
        if(r<0||c<0||r>=m||c>=n||!g[r][c]||g[r][c]==-1)
            return 0;
        g[r][c]=-1;
        return 1+dfs(g, r,c+1)+dfs(g, r,c-1)+dfs(g, r+1,c)+dfs(g, r-1,c);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& g) {
        m=g.size();
         n=g[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(g[i][j]==1)
                {
                    ans=max(ans, dfs(g, i, j));
                }
            }
        }
        return ans;
    }
};