class Solution {
public:
    bool terminal=0;
    void dfs(vector<vector<int>> &g, int r, int c)
    {
        int dr[4]={1,0,0,-1};
        int dc[4]={0,1,-1,0};
        int m=g.size();
        int n=g[0].size();
        if(r<0 ||c<0 ||c>=n||r>=m)
        {
            terminal=true;
            return;
        }
        if(g[r][c])
            return ;
        else
            g[r][c]=1;
        for(int i=0;i<4;i++)
        {
            dfs(g,r+dr[i],c+dc[i]);
        }
         return;  
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!grid[i][j]){
                    terminal=0;
                dfs(grid, i, j);
                if(!terminal)
                    ans++;
            
                }
            }
        }
        return ans;
    }
};