class Solution {
    const int mod=1e9+7;
public:
    int rev(int n)
    {
       
    int ans=0;
        while(n>0)
        {
             ans*=10;
            int cur=n%10;
            ans+=cur;
            n/=10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& v) {
        for(auto &x:v)
        {
           
            x-=rev(x);
             
        }
        int cnt=0;
        long ans=0;
        sort(v.begin(), v.end());
        for(int i=1;i<v.size();i++)
        {
            if(v[i]==v[i-1]){
                cnt++;
                ans=(ans+cnt)%mod;
            }
            else
                cnt=0;
        }
       
        return ans;
    }
};