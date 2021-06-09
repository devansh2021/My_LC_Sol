
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        vector<int> ans;
        deque<int> q;
        q.push_back(0);
        for(int i=1;i<k;i++)
        {
            while(!q.empty()&&v[q.back()]<v[i])
                q.pop_back();
            q.push_back(i);
        }
        for(int i=k;i<v.size();i++)
        {
            ans.emplace_back(v[q.front()]);
            while(!q.empty() && q.front()<=i-k)
                q.pop_front();
            while(!q.empty()&&v[q.back()]<v[i])
                q.pop_back();
            q.push_back(i);                
        }
        ans.emplace_back(v[q.front()]);
        return ans;
    }
};