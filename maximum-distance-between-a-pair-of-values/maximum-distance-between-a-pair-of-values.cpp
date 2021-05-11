class Solution {
public:
    int maxDistance(vector<int>& v1, vector<int>& v2) {
        int n=v1.size(), m=v2.size();
        int i=0, j=0;
        int ans=0;
        while(i<n&&j<m)
        {
            if(v2[j]<v1[i])
                i++;
            else
            {
                ans=max(ans, j-i);
                j++;
            }
        }
        return ans;
    }
};