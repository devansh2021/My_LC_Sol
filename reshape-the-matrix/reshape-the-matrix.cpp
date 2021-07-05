class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size();
        int n=mat[0].size();
        if(r*c!=m*n)
            return mat;
        vector<vector<int>> ans(r, vector<int>(c));
        int j=0;
        for(int i=0;i<m*n;i++)
        {
            ans[j/c][j%c]=mat[i/n][i%n];
            j++;
        }
      
        return ans;
    }
};