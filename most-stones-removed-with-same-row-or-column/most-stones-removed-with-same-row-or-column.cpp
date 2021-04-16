
class Solution {
public:
    vector<int> id;
    int find(int c)
    {
        int root=id[c];
        while(id[root]!=root)
        {
            root=id[root];
        }
      /*  while(c!=root)
        {
            int next=id[c];
            id[c]=root;
            c=next;
        }
        */
        return root;
    }
    int removeStones(vector<vector<int>>& s) {
        int n=s.size();
        id.resize(n);
        iota(id.begin(), id.end(),0);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i][0]==s[j][0] || s[i][1]==s[j][1] )
                {
                    id[find(j)]=find(i);
                 
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(id[i]==i)
                ans++;
        }
        return n-ans;
    }
};