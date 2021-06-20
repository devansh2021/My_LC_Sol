class Solution {
    int query(int l, int r,vector<int>& v,  vector<vector<int>>&cnt)
    {
         vector<int> f(101);
         for(int j=1;j<=100;j++)
            f[j]=cnt[r+1][j]-cnt[l][j];
        int ans=INT_MAX, prev=-1;
        for (int j = 1; j < 101; ++j) {
                if (f[j] == 0) continue;
                if (prev != -1 && j - prev < ans) ans = j - prev;
                prev = j;
            }
           return ans == INT_MAX ? -1 : ans;
    }
public:
    vector<int> minDifference(vector<int>& v, vector<vector<int>>& queries) {
        vector<int> ans;
        int n=v.size();
        vector<vector<int>> cnt(n+1, vector<int>(101));
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=100;j++)
                cnt[i+1][j]=cnt[i][j];
             cnt[i+1][v[i]]=cnt[i][v[i]]+1;
        }
        
        for(auto q:queries)
        {
            ans.emplace_back(query(q[0], q[1], v, cnt));
        }
        return ans;
    }
};