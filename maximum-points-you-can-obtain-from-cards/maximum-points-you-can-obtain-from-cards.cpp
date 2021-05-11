class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int st= v.size()-k;
        int n=v.size();
        int end=v.size()-1;
        int ans=0;
        int csum=0;
        for(int i=st;i<=end;i++)
        {
           csum+=v[i];
        }
        ans=max(csum, ans);
        while(st<n){
            csum-=v[st];
            csum+=v[(end+1)%n];
            ans=max(csum, ans);
            st++;
            end++;
        }
        return ans;
    }
};