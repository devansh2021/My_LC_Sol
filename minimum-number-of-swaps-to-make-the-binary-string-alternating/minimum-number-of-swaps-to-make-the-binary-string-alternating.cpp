class Solution
{
public:
    int minSwaps(string s)
    {
        int n = s.size();
        int req = n / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '1')
                cnt++;
        if (cnt >= req && n - cnt >= req)
        {
            int ans = 0;
            if (cnt == n - cnt)
            {
                int cur = 0;
                for (int i = 0; i < n; i += 2)
                    if (s[i] != '1')
                        cur++;
                for (int i = 0; i < n; i += 2)
                    if (s[i] != '0')
                        ans++;
                return min(ans, cur);
            }
            else
            {
                if (cnt > n - cnt)
                {
                    for (int i = 0; i < n; i += 2)
                        if (s[i] != '1')
                            ans++;
                    return ans;
                }
                else
                {
                    for (int i = 0; i < n; i += 2)
                        if (s[i] != '0')
                            ans++;
                    return ans;
                }
            }
        }
        return -1;
    }
};