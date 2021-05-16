class Solution {
public:
    string sortSentence(string s) {
        stringstream ss(s);
        unordered_map<int, string> m;
        string token;
        while(getline(ss, token, ' '))
        {
            int n=token.size();
            m[token[n-1]-'0']=token.substr(0, n-1);
        }
        string ans;
        for(int i=1;i<10;i++)
        {
            if(m.find(i)!=m.end()){
                ans.append(m[i]);
                ans.append(1,' ');
            }
        }
        int z=ans.size();
        ans.erase(z-1);
        return ans;
    }
};