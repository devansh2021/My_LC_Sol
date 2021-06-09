class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& ins) {
         if (ins.empty()) return vector<vector<int>>{};
    vector<vector<int>> res;
    sort(ins.begin(), ins.end(), [](vector<int> a, vector<int> b){return a[0] < b[0];});
    res.push_back(ins[0]);
    for (int i = 1; i < ins.size(); i++) {
        if (res.back()[1]< ins[i][0]) res.push_back(ins[i]);
        else
            res.back()[1] = max(res.back()[1], ins[i][1]);
    }
    return res;
    }
};