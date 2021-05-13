class Solution {
public:
    int largestRectangleArea(vector<int>& he) {
        stack<int> s;
        int n=he.size();
        int ans=0;
        for(int i=0;i<=n;i++)
        {
            while(s.size()&&(i==n||he[s.top()]>he[i]))
            {
                int topIdx=s.top();
                s.pop();
                // int lastIdx=s.empty()?0:s.top()+1;
                ans=max(ans, he[topIdx]*(i-(s.empty()?0:s.top()+1)));
            }
            s.push(i);
        }
       
        return ans;
    }
};