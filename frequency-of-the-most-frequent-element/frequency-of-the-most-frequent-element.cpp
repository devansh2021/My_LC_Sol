class Solution
{
public:
    int maxFrequency(vector<int> &v, int k)
    {
        int n = v.size();
        vector<long long> preSum(n + 1);
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
            preSum[i + 1] = preSum[i] + v[i];
        int l = 0, r = n - 1, ans = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            l=0;
            r = i;
            int res = i;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                sum = preSum[i] - preSum[mid];
                if (sum + k >= (long long)(i - mid) * v[i])
                {
                    res = mid;
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            ans = max(ans, i - res + 1);
        }

        return ans;
    }
};