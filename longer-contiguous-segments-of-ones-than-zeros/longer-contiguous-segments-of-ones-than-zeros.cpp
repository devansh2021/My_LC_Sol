class Solution
{
public:
    bool checkZeroOnes(string s)
    {
        int i = 0, j = 1, n = s.size();
        int cons1 = 0, cons0 = 0;
        if (s[i] == '1')
            cons1++;
        else
            cons0++;
        while (j < n)
        {
            while (s[i] == s[j])
            {
                j++;
            }
            if (s[i] == '1')
                cons1 = max(cons1, j - i);
            else
                cons0 = max(cons0, j - i);
            i = j;
            j++;
        }
        return cons1 > cons0;
    }
};