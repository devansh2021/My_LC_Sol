class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
       
        vector<string> ans;
        for(auto w:words)
        {
            bool flg=1;
             vector<char> m(26, '0');
            vector<bool> f(26);
            for(int i=0;w[i];i++)
            {
                if(m[w[i]-'a']=='0'&&!f[pattern[i]-'a']){
                    m[w[i]-'a']=pattern[i];
                    f[pattern[i]-'a']=1;
                }
                    
                    if(pattern[i]!=m[w[i]-'a']){
                        
                        flg=0;
                        break;
                    }
            }
            if(flg)
                ans.emplace_back(w);
        }
        return ans;
    }
};