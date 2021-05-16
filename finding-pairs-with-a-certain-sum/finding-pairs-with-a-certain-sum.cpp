class FindSumPairs
{
    vector<int> v1, v2;
    unordered_map<int, int> m;

public:
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        v1 = nums1;
        v2 = nums2;
        for (auto x : nums2)
            m[x]++;
    }
    void add(int index, int val)
    {
        m[v2[index]]--;
        v2[index] += val;
        m[v2[index]]++;
    }

    int count(int tot)
    {
        int ans = 0;
        for (auto x : v1)
        {

            if (tot - x > 0)
                ans += m[tot - x];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */