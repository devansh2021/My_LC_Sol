class Solution {
    bool dfs(vector<vector<int>>& g,vector<vector<bool>>& vis,  int t, int m, int n, int i, int j){
        if(i<0||j<0||i>=m||j>=m||vis[i][j]||g[i][j]>t)
            return 0;
        vis[i][j]=1;
        if(i==m-1&&j==n-1)
            return 1;
        return dfs(g, vis, t, m, n, i+1, j)||
            dfs(g, vis, t, m, n, i-1, j)||
            dfs(g, vis, t, m, n, i, j+1)||
            dfs(g, vis, t, m, n, i, j-1);
    }
    bool check(vector<vector<int>>& g, int t){
        int m=g.size(), n=g[0].size();
        vector<vector<bool>> vis(m,  vector<bool>(n, false));
       return dfs(g, vis, t, m, n, 0, 0);
    }
public:
    int swimInWater(vector<vector<int>>& g) {
        int l=0, r=INT_MAX, ans=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            
            if(check(g, mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};