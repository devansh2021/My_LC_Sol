class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &v)
    {
        vector<int> ans;
        vector<int> idx(v.size());
        iota(begin(idx), end(idx), 0);
        sort(begin(idx), end(idx), [&](int i, int j) { return v[i][0] < v[j][0]; });
       
        long long cur = 1;
        int n = v.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int i = 0;
        for ( ; i < idx.size() || !pq.empty();)
        {
            for (; i < idx.size() && v[idx[i]][0] <= cur; ++i)
                pq.push({v[idx[i]][1], idx[i]});
            if (!pq.empty())
            {
                cur += pq.top().first;
                ans.emplace_back(pq.top().second);
                pq.pop();
            }
            else
                cur = v[idx[i]][0];
        }
       

        return ans;
    }
};