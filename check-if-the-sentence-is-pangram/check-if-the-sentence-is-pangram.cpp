class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        vector<bool> f(26, 0);
        for (auto c : sentence)
        {
            f[c - 'a'] = 1;
        }
        for (auto x : f)
        {
            if (!x)
                return false;
        }
        return 1;
    }
};

