class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        stack<int> s;
        int n=v.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            while(s.size()&&v[s.top()]<v[i])
            {
                ans[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};