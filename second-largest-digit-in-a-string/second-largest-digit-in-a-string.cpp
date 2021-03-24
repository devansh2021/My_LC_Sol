class Solution {
public:
    int secondHighest(string s) {
        set<int> v;
        v.insert(-1);
        for(int i=0;s[i];i++)
        {
            if(s[i]-'0'>=0&&s[i]-'0'<=9)
            {
                int t=s[i]-'0';
                v.insert(t);
            }
        }
        if(v.size()==1)
            return -1;
        auto it=v.rbegin();
        it++;
        return *(it);
    }
};