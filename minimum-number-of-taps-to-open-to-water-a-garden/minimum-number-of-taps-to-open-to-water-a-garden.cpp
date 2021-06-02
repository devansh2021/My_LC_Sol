class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> jumps(n+1);
        for(int i=0;i<ranges.size();i++)
        {
            int l=max(0, i-ranges[i]);
            int r=min(n,i+ranges[i] );
            jumps[l]=max(jumps[l], r-l);
        }
        int far=0, curfar=0, ans=0;
        for(int i=0;i<jumps.size()-1;i++)
        {
            if(i>far)
                return -1;
            far=max(far, i+jumps[i]);
            if(i==curfar)
            {
                ans++;
                curfar=far;
            }
        }
        return curfar>=n?ans:-1;
    }
};