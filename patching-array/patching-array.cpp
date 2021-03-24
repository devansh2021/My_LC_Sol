class Solution {
public:
    int minPatches(vector<int>& v, int n) {
        long long max_val=0, ans=0;
        int i=0;
        while(max_val<n)
        {
            if(max_val>=n)
                break;
            if(i<v.size()&&max_val+1>=v[i])
                max_val+=v[i++];            
            
            else{
               ans++;
                max_val=2*(max_val)+1;
            }
        }
        return ans;
    }
};