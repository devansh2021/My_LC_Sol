class Solution {
public:
    int lastStoneWeightII(vector<int>& v) {
        int n=v.size();
        int sum=accumulate(v.begin(), v.end(), 0);
        int osum=sum;
        sum=sum>>1;
        // cout<<sum<<endl;
        vector<vector<bool>> dp(n, vector<bool>(sum+1,0));
        for(int i=0;i<n;i++)
            dp[i][0]=1;
        for(int s=1;s<=sum;s++)
            dp[0][s]=(v[0]==s)?1:0;
        for(int i=1;i<n;i++)
        {
            for(int s=1;s<=sum;s++)
            {
                
                if(dp[i-1][s])
                    dp[i][s]=dp[i-1][s];
                else if(s-v[i]>=0){
                    dp[i][s]=dp[i-1][s]||dp[i-1][s-v[i]];
                // if(i==n-1&&dp[i][s]==1)
                //     cout<<dp[i-1][s]<<" "<<dp[i-1][s-v[i]]<<" "<<v[i]<<endl;
                     }
            }
        }
        
        // for(auto x:dp)
        // {
        //     for(auto y:x)
        //         cout<<y<<" ";
        //     cout<<endl;
        // }
        
        for(int j=sum;j>=0;j--)
        {
            if(dp[n-1][j]){
                // cout<<j<<endl;
                return abs(osum-2*j);
            }
        }
        return 0;
    }
};