class Solution
{
public:
    vector<vector<int>> g;
    int dfs(int i, vector<int> &informTime)
    {
        int mxtime = 0;
        for (auto neigh : g[i])
            mxtime = max(mxtime, dfs(neigh, informTime));
        return informTime[i] + mxtime;
    }
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        g.resize(n);
        for (int i = 0; i < manager.size(); i++) //Create Adjacency list
            if (manager[i] != -1)
                g[manager[i]].push_back(i);
        return dfs(headID, informTime);
    }
};