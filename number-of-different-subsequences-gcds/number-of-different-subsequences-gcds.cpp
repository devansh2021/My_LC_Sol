class Solution
{
public:
  int countDifferentSubsequenceGCDs(vector<int> &nums)
  {
    int maxi = *max_element(nums.begin(), nums.end());
   
    vector<int> divisors(maxi + 1);
    for (int i = 0; i < nums.size(); i++)
    {

      for (int j = 1; j <= sqrt(nums[i]); j++)
      {

        if (nums[i] % j == 0)
        {
          int d1 = j;
          int d2 = nums[i] / j;

          if (divisors[d1] == 0)
          {
            divisors[d1] = nums[i];
          }
          else
          {

            divisors[d1] = gcd(divisors[d1], nums[i]);
          }

          if (divisors[d2] == 0)
          {
            
            divisors[d2] = nums[i];
          }
          else
          {
            divisors[d2] = gcd(divisors[d2], nums[i]);
          }
        }
      }
    }
    int ans = 0;
    for (int i = 1; i <= maxi; ++i)
      if (divisors[i] == i)
        ++ans;
    return ans;
  }
     int gcd(int a, int b) {

        while (b != 0) {
            int t = a;
            a = b;
            b = t % b;
        }
        return a;
    }
};