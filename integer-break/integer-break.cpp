class Solution {
public:
 int helper( int curSize, vector<int>& dp)
{
    int ans=1;
    if(curSize==0)
    return 1;
    if(dp[curSize]!=-1)
    return dp[curSize];
    for(int i=0;curSize-(i+1)>=0;i++)
    {
        ans=max(ans,(i+1)*helper( curSize-(i+1), dp));
    }
    return dp[curSize]=ans;
}
int integerBreak( int n) {
    vector<int> dp(n+1, -1);
    int curSize=n, ans=1;
     for(int i=0;curSize-(i+1)>0;i++)
    {
        ans=max(ans,(i+1)*helper( curSize-(i+1), dp));
    }
    return dp[curSize]=ans;
}
};
