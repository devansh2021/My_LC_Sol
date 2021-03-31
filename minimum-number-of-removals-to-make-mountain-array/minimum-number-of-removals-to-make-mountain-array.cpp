class Solution
{
public:
  int minimumMountainRemovals(vector<int> &nums)
  {
    int n = nums.size();

    //lis[i] stores the longest increasing subsequences ending at i
    vector<int> lis(n, 1);

    for (int i = 0; i < n; i++)
    {
      int maxi = 1;
      for (int j = 0; j < i; j++)
      {
        if (nums[j] < nums[i])
        {
          maxi = max(maxi, lis[j] + 1);
        }
      }
      lis[i] = maxi;
    }

    // now apply above algorithm in reverse
    //lds[i] stores the longest increasing subsequences till i in the reverse of array nums
    //OR
    //lds[i] stores longest decreasing subsequence starting from i
    vector<int> lds(n, 1);
    for (int i = n - 1; i >= 0; i--)
    {
      int maxi = 1;
      for (int j = i + 1; j < n; j++)
      {
        if (nums[i] > nums[j])
        {
          maxi = max(maxi, lds[j] + 1);
        }
      }
      lds[i] = maxi;
    }

    /*Add lds[i] and lis[i] but nums[i] is counted twice so longest bitonic subsequence lis[i] + lds[i] - 1
		*/
    int lbs = 0;
    for (int i = 0; i < n; i++)
    {
      if (lis[i] > 1 && lds[i] > 1)
        lbs = max(lis[i] + lds[i] - 1, lbs);
    }
    //remove other elements which are not in subsequence
    return n - lbs;
  }
};