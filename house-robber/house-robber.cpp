class Solution {
public:
    int rob(vector<int>& v) {
        int a1=0, a2=v[0], temp;
        //a2 is with adjacent element
        //a1 is without adjacent element
        for(int i=1;i<v.size();i++)
        {
            temp=max(a1+v[i], a2);
            a1=a2;
            a2=temp;
        }
        return a2;
    }
};