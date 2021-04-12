class Solution {
public:
vector<vector<int>> dp;
int helper(string &a, string &b, int i, int j) {
    // cout<<i<<" "<<j<<endl;
    if (i == a.size()) return 0;
    if (j == b.size()) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (a[i] == b[j]) {
        // cout<<"yes";
        return dp[i][j] = 1 + helper(a, b, i + 1, j + 1);
    }

    return dp[i][j] = max(helper(a, b, i + 1, j), helper(a, b, i, j + 1));
}
int minDistance(string a, string b) {
    dp.resize(a.size(), vector<int>(b.size(), -1));
    return a.size()+b.size()-2*helper(a, b, 0, 0);
}
};
