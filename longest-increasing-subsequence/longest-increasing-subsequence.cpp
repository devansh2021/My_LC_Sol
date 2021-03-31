class Solution
{
public:
  int lengthOfLIS(vector<int> &nums)
  {
    int i, j, n = nums.size(), ans = 0;
    if (nums.size() == 0)
      return 0;
    vector<int> dp(n, 1);
    for (i = 1; i < n; i++)
      for (j = 0; j < i; j++)
        if (nums[i] > nums[j])
          dp[i] = max(dp[i], dp[j] + 1);

    for (i = 0; i < n; i++)
      ans = ans > dp[i] ? ans : dp[i];
    return ans;
  }
};