class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        int ans = 0;
        int sum = 0;
        sort(costs.begin(), costs.end());
        for (auto x : costs)
        {
            sum += x;
            if (sum <= coins)
                ans++;
            else
                return ans;
        }
        return ans;
    }
};