class Solution {
public:
    int maximumUniqueSubarray(vector<int>& v) {
        unordered_set<int> s;
        int sum=0;
        int ans=0;
        for(int b=0, e=0;e<v.size();e++)
        {
            if(s.find(v[e])==s.end()){
            s.insert(v[e]);
            sum+=v[e];
            }
            else
            {
                while(s.find(v[e])!=s.end()){
                    s.erase(v[b]);
                    sum-=v[b++];
                }
            s.insert(v[e]);
            sum+=v[e];
            }
            
            ans=max(sum, ans);
        }
        return ans;
    }
};