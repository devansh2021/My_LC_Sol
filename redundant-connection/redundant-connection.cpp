/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start
class Solution
{
public:
    vector<int> id;
    int find(int c)
    {
        int root = id[c];
        while(id[root]!=root)
        {
            root=id[root];
        }
        return root;
    }
    vector<int> findRedundantConnection(vector<vector<int>> &e)
    {
        int n = e.size();
        id.resize(n);
        vector<int> ans;
        iota(id.begin(), id.end(), 0);
        for (int i = 0; i < n; i++)
        {
            int x = find(e[i][0] - 1);
            int y = find(e[i][1] - 1);
            if (x != y)
            {
                id[y] = x;
            }
            else
            {
                ans.emplace_back(e[i][0]);
                ans.emplace_back(e[i][1]);
            }
        }
        return ans;
    }
};
// @lc code=end
