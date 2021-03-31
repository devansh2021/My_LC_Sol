class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        if(v.size()<=1)
            return 0;
        sort(v.begin(), v.end(), [](vector<int> a, vector<int> b){
           return a[1]<=b[1]; 
        });
        int cnt=1;
        int cur=v[0][1];
        for(int i=1;i<v.size();i++)
        {
            if(v[i][0]>=cur)
            {
                cnt++;
                cur=v[i][1];
            }
        }
        return v.size()-cnt;
    }
};