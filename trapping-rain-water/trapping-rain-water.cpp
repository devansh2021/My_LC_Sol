class Solution {
public:
    int trap(vector<int>& h)
{
    if(h.size()<1)
        return 0;
    int ans = 0;
    int n= h.size();
    vector<int> left_max(n), right_max(n);
    left_max[0] = h[0];
    for (int i = 1; i < n; i++) {
        left_max[i] = max(h[i], left_max[i - 1]);
    }
    right_max[n- 1] = h[n- 1];
    for (int i = n- 2; i >= 0; i--) {
        right_max[i] = max(h[i], right_max[i + 1]);
    }
    for (int i = 1; i < n- 1; i++) {
        ans += min(left_max[i], right_max[i]) - h[i];
    }
    return ans;
}
};