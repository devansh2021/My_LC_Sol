class Solution {
public:
    vector<vector<int>> ans;
    queue<vector<int>> q;
    void bfs(vector<int>& v)
    {
        q.push(vector<int>());
       for(auto x: v)
        {
           int cur_size=q.size();
           for(int j=0;j<cur_size;j++){
               vector<int> cur=q.front();
               q.pop();
            for(int i=0;i<=cur.size();i++)
            {
                vector<int> newv(cur);
                newv.insert(newv.begin()+i, x);
                if(newv.size()==v.size())
                    ans.push_back(newv);
                else
                    q.push(newv);
            }   
           }
        }
    }
    vector<vector<int>> permute(vector<int>& v) {
        bfs(v);
        return ans;
    }
};