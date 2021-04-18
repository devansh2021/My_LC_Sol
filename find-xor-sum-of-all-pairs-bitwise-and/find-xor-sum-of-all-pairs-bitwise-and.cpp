class Solution
{
public:
    int getXORSum(vector<int> &a, vector<int> &b)
    {
        int ans = 0;
        int xora = 0;
        for (auto x : a)
            xora ^= x;
        for (auto x : b)
            ans = ans ^ (xora & x);
        return ans;
    }
};
