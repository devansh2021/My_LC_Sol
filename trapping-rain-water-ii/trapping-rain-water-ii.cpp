class Solution
{
public:
  int trapRainWater(vector<vector<int>> &h)
  {
    int m = h.size(), n = h[0].size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<vector<int>> vis(m, vector<int>(n, 0));
    int ans = 0, maxh = INT_MIN;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (!(i == 0 || i == m - 1 || j == 0 || j == n - 1))
          continue;
        pq.push(make_pair(h[i][j], i * n + j));
        vis[i][j] = 1;
      }
    }
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!pq.empty())
    {
      auto val = pq.top();
      pq.pop();
      int curh = val.first, x = val.second / n, y = val.second % n;
      maxh = max(maxh, curh);
      for (auto d : dir)
      {
        int x2 = x + d[0], y2 = y + d[1];
        if (x2 >= m || x2 < 0 || y2 < 0 || y2 >= n || vis[x2][y2])
          continue;
        vis[x2][y2] = 1;
        if (h[x2][y2] < maxh)
          ans += maxh - h[x2][y2];
        pq.push(make_pair(h[x2][y2], x2 * n + y2));
      }
    }
    return ans;
  }
};