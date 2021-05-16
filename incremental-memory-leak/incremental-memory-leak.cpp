class Solution {
public:
    vector<int> memLeak(int m1, int m2) {
        int cur=max(m1, m2);
        int cm1=m1, cm2=m2,  i=1;
        for(;cur-i>=0;i++)
        {
            if(cm1>=cm2)
                cm1-=i;
            else
                cm2-=i;
            
            cur=max(cm1, cm2);
        }
        vector<int> v={i, cm1, cm2};
        return v;
    }
};