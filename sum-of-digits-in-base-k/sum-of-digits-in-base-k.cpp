class Solution
{
    int ans = 0;

public:
    void calSum(int N, int b)
    {
        if (N == 0)
            return;
        int x = N % b;
        N /= b;
        ans += x;
        calSum(N, b);
        return;
    }
    int sumBase(int n, int k)
    {
        calSum(n, k);
        return ans;
    }
};