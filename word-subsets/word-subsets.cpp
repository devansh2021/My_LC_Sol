class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> ans;
        vector<int> f(26);
        for(auto b:B)
        {
            vector<int> f1(26);
            for(auto c:b)
            {
                f1[c-'a']++;
            }
            for(int i=0;i<26;i++)
                if(f1[i]>f[i])
                    f[i]=f1[i];     
        }
        for(auto a: A)
        {
            vector<int> f1=f;
            for(auto c:a){
                if(f1[c-'a']>0)
                f1[c-'a']--;
            }
            
            bool flg=1;
            for(int i=0;i<26;i++)
                if(f1[i]!=0)
                    flg=0;
            if(flg)
                ans.emplace_back(a);
        }
        return ans;
    }
};