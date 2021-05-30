class Solution {
    int dfs1(vector<vector<int>>& v,int i, int j, int sum, int len, int mod )
{
        int l=len, m=v.size(), n=v[0].size();
        if( mod<0)
        return sum;
        while(l>1)
        {
            if(i>=m||j>=n||j<0||i<0)
                return 0;
            if(mod==3)
            sum+=v[i++][j++];
            else if(mod==2)
            sum+=v[i++][j--];
            else if(mod==1)
            sum+=v[i--][j--];
            else sum+=v[i--][j++]; 
            l--;
        }
       return dfs1(v , i, j,sum, len, mod-1);
}
  int dfs2(vector<vector<int>>& v,int i, int j, int sum, int len, int mod )
{
    int l=len,  m=v.size(), n=v[0].size();
        if(l==1)
            return v[i][j];
        if(mod<0)
        return sum;
        while(l>1)
        {
            if(i>=m||j>=n||j<0||i<0)
                return 0;
            if(mod==3)
            sum+=v[i++][j--];
            else if(mod==2)
            sum+=v[i++][j++];
            else if(mod==1)
            sum+=v[i--][j++];
            else sum+=v[i--][j--];
            l--;
        }
        return dfs2(v,i, j,  sum, len, mod-1);
}
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int len=min(m, n)-1;
        priority_queue<int> pq;
        for(int l=1;l<=len+1;l++)
        {
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    pq.push(dfs1(grid,i, j, 0, l, 3));
                    pq.push(dfs2(grid, i, j, 0, l, 3));
                }
            }
        }
        vector<int> ans;
        while(ans.size()<3&&!pq.empty())
        {
            int cur=pq.top();
            if(cur!=0&&ans.size()==0)
                ans.push_back(cur);
            if(cur!=0&&ans.back()!=cur)
                ans.push_back(cur);
            pq.pop();
        }
        return ans;
    }
};