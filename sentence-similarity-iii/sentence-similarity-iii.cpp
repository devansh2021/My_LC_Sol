class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.size()<s2.size())
            swap(s1, s2);
        stringstream ss(s1);
        multimap<string, int> m;
       
        int i=0;
        string token;
        while(getline(ss, token, ' '))
           m.emplace(token, i++);
        stringstream s(s2);
        int cur=-1;
        int f=1;
        while(getline(s, token, ' '))
        {
            if(m.count(token)>0)
            {
                int ocur=cur;
                
                auto it=m.equal_range(token);
                auto itr=it.first;
                for(;itr!=it.second;itr++)
                {
                    if(itr->second>cur){
                       
                        cur=itr->second;
                        break;
                    }
                }
                
                if(cur>ocur+1&&f)
                    f=0;
                else if(cur==ocur+1)
                    continue;
                else 
                    return 0;
                
            }
            else 
            return 0;
        }
      
        if(cur+1==i)
        return 1;
        else if(f)
            return 1;
        else
            return 0;
    }
};