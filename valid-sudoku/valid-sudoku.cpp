class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& v) {
        unordered_set <string> s;
        int m=v.size();
        int n=v[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]!='.')
                {
                    string s1='r'+to_string(i)+v[i][j];
                    string s2=v[i][j]+to_string(j)+'c';
                    string s3 = 'r'+to_string(i/3)+v[i][j]+'c'+to_string(j/3);
                    
                    if(s.find(s1)==s.end())
                    {
                        s.insert(s1);
                    }
                    else
                    {   cout<<s1<<endl;
                        return false;
                    }
                    
                    if(s.find(s2)==s.end())
                    {
                        s.insert(s2);
                    }
                    else
                       {   cout<<s2<<endl;
                        return false;
                    }
                    
                    if(s.find(s3)==s.end())
                    {
                        s.insert(s3);
                    }
                    else
                    {   cout<<s3<<endl;
                     cout<<i<<j;
                        return false;
                    }
                    
                
                }
            }
        }
        return true;
    }
};