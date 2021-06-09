class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &a, vector<vector<int>> &b)
    {
        int i = 0;
        int j = 0;
        int m = a.size();
        int n = b.size();
        vector<vector<int>> ans;
        if (m == 0 && n == 0)
            return ans;
        while (i < m && j < n)
        {
            vector<int> v;
            int b1 = a[i][0];
            int e1 = a[i][1];
            int b2 = b[j][0];
            int e2 = b[j][1];
            if (b2 > e1)
            {
                i++; 
            }
            else if (b1 > e2)
            {
                j++;
            }
            else
            {
                v.emplace_back(max(b1, b2));
                v.emplace_back(min(e1, e2));
                ans.emplace_back(v);
                if (e2 > e1)
                    i++;
                else
                    j++;
            }
        }
        return ans;
    }
};