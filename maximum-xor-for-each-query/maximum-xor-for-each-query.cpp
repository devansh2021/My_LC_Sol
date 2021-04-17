class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &v, int maximumBit)
    {
        vector<int> ans;
        vector<int> sum(maximumBit);
        for (int i = 0; i < v.size(); i++)
        {
            int cans = 0;
            int cur = v[i];
            for (int i = 0; i < maximumBit; i++)
            {
                sum[i] += ((cur >> i) & 1);
                sum[i] = sum[i] % 2;
                if (!sum[i])
                    cans += (1 << i);
            }
            ans.push_back(cans);
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};