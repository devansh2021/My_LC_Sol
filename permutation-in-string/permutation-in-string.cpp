class Solution {
public:
    bool checkInclusion(string s1, string s) {
      unordered_map<char, int> m;
        int n=s1.size();
        for(auto c:s1)
            m[c]++;
        int counter=m.size(), matched=0;
        int b=0, e=0;
        while(e<s.size())
        {
             
            if(m.find(s[e])!=m.end()){
                m[s[e]]--;
                if(m[s[e]]==0)
                    matched++;
            }
            e++;
            if(e-b>n)
            {
                if(m.find(s[b])!=m.end())
                {
                    if(m[s[b]]==0)
                    matched--;
                    m[s[b]]++;
            
                }
                b++;
            }
            if(matched==counter)
                return true;
            
            
        }
        return false;
    }
};