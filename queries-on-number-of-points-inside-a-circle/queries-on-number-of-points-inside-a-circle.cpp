class Solution
{
public:
    vector<int> countPoints(vector<vector<int>> &p, vector<vector<int>> &q)
    {
        vector<int> res;
        for (auto v : q)
        {
            int cur = 0;
            for (auto v1 : p)
            {
                int x = v1[0], y = v1[1], cx = v[0], cy = v[1], r = v[2], d = (x - cx) * (x - cx) + (y - cy) * (y - cy);
                if (d <= r * r)
                    cur++;
            }
            res.push_back(cur);
        }
        return res;
    }
};