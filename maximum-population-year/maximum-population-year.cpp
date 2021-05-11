class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> p(101);
        for(auto x:logs)
        {
            for(int i=x[0];i<x[1];i++)
                p[i-1950]++;
        }
        int ans=1950;
        int maxp=INT_MIN;
        for(int i=0;i<p.size();i++)
        {
            if(p[i]>maxp){
                ans=i;
                maxp=p[i];
            }
        }
        return 1950+ans;
    }
};

// 1 2 3 4  5 6 1 1 2 3 4 5 6 1
// 1 2 3 
//     1 1 6
//     1 2 1
    
// 9 7 7 9 7 7 9 9 7 7 9 7 7 9
//     27+28
//     55