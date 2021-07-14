class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int val=1;
        int cnt=0;
        int i=0, j=0;
        vector<vector<int>> g(n, vector<int>(n));
        while(val<=n*n)
        {
            while(j+cnt<n)
                g[i][j++]=val++;
            j--;
            i++;
            while(i+cnt<n)
                g[i++][j]=val++;
            i--;
            j--;
            while(j-cnt>=0)
                 g[i][j--]=val++;
            cnt++;
            j++;
            i--;
             while(i-cnt>=0)
                 g[i--][j]=val++;
            i++;
            j++;
        }
        return g;
    }
};