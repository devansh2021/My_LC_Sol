class Solution
{
    void bfs(vector<vector<int>> &ans, vector<int> &v, int i)
    {
        queue<vector<int>> q;
        q.push(vector<int>());
        for (auto x : v)
        {
            cout << x << "val" << endl;
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                vector<int> cur = q.front();
                q.pop();
                for (int j = 0; j <= cur.size(); j++)
                {
                    bool shouldBreak = (j == cur.size() || x == cur[j]);
                    vector<int> newv = cur;
                    newv.insert(newv.begin() + j, x);
                    q.push(newv);
                    if (shouldBreak)
                        break;
                }
            }
        }
        while (!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &v)
    {
        vector<vector<int>> ans;
        bfs(ans, v, 0);
        return ans;
    }
};