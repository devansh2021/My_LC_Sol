class Solution {
public:
    vector<int> advantageCount(vector<int>& a, vector<int>& b) {
  multiset<int> s(begin(a), end(a));
  for (auto i = 0; i < b.size(); ++i) {
    auto p = *s.rbegin() <= b[i] ? s.begin() : s.upper_bound(b[i]);
    a[i] = *p;
    s.erase(p);
  }
  return a;
}
    
};