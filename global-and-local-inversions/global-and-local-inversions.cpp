class Solution {
    
public:
    bool isIdealPermutation(vector<int>& v) {
        int loc=0, global=0;
        for(int i=0;i<v.size();)
        {
            if(v[i]!=i)
            {
                 if(v[i]==i+1||v[i]==i-1)
                    loc++;
                else
                    global++;
                swap(v[i], v[v[i]]);
            }
            else
                i++;
        }
        if(global==0)
            return 1;
        return 0;
    }
};