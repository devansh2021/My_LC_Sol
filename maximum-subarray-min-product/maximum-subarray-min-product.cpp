class Solution {
    const int mod=1e9+7;
public:
    int maxSumMinProduct(vector<int>& v) {
        int n=v.size();
        vector<long long> preSum(n+1);
        for(int i=1;i<=n;i++)
        {
            preSum[i]=v[i-1]+preSum[i-1];
        }
        stack<int> st;
        long long ans=0;
        for(int i=0;i<=n;i++)
        {
            while(!st.empty()&&(i==n||v[st.top()]>v[i]))
            {
                int topIdx=st.top();
                st.pop();
                if(!st.empty())
                ans=max(ans, v[topIdx]*(preSum[i]-preSum[st.top()+1]));
                else
                ans=max(ans, v[topIdx]*(preSum[i]-preSum[0]));
    
            }
            st.push(i);
        }
        return ans%mod;
    }
};
// 1 2 3 2
//     st: 1 2 2
// ans: 2*(3+2) = 10
//     (2 +3 +2)*2=14
//     (1+2)*2;
// (1)*1