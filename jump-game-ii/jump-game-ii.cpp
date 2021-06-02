class Solution {
public:
    int jump(vector<int>& v) {
     int far=0, i=0, curfar=0, ans=0, n=v.size();
        for(;i<n&&i<=far;i++)
        {
            if(i>curfar)
            {
                curfar=far;
                ans++;
            }
            far=max(far, i+v[i]);
        }
        return ans;
    }
};