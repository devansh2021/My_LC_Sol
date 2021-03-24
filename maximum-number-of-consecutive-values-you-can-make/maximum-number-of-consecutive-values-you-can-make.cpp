class Solution {
public:
    int getMaximumConsecutive(vector<int>& c) {
    sort(c.begin(), c.end());
    int max_reach = 1;
    for (auto i = 0; i < c.size() && c[i] <= max_reach; ++i)
        max_reach += c[i];
    return max_reach;
}  
};