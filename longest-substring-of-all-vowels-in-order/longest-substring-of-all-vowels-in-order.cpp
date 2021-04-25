class Solution
{
    bool isvowel(char c)
    {
        string s = "aeiou";
        for (auto x : s)
            if (x == c)
                return 1;
        return 0;
    }
    bool check(vector<int> &f)
    {
        string s = "aeiou";
        for (auto x : s)
        {
            if (f[x - 'a'] < 1)
                return 0;
        }
        return 1;
    }

public:
    int longestBeautifulSubstring(string w)
    {
        int s = 0, e = 0, n = w.size();
        vector<int> f(26);
        char lastv = 'a';
        int lastp = -1;
        int ans = 0;
        while (s <= e && e < n)
        {
            if (isvowel(w[e]))
            {
                if (w[e] < lastv)
                {
                    if (lastp != -1)
                        s = lastp + 1;
                    else
                        s = e;
                    f = vector<int>(26, 0);
                    if (isvowel(w[e]))
                    {
                        f[w[e] - 'a']++;
                        lastv = w[e];
                        lastp = e;
                    }
                    else
                    {
                        lastv = 'a';
                        lastp = -1;
                    }
                }
                else
                {
                    f[w[e] - 'a']++;
                    lastv = w[e];
                    lastp = e;
                }
            }
            e++;
            if (check(f) && ans < e - s)
                ans = e - s;
        }
        return ans;
    }
};