class Solution {
public:
    bool canJump(vector<int>&A) {
        int n=A.size();
    int i = 0, far=0;
    for (; i < n && i <= far; ++i)
        far = max(i + A[i], far);
    return i == n;
}
};