class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &b)
    {
        int m = b.size(), n = b[0].size();
        for (int j = n - 2; j >= 0; j--)
        {
            for (int i = 0; i < m; i++)
            {

                if (b[i][j] == '#')
                {
                    int chk = j + 1;

                    while (chk < n && b[i][chk] == '.')
                    {
                        chk++;
                    }
                    if (chk - 1 != j)
                    {
                        b[i][chk - 1] = b[i][j];
                        b[i][j] = '.';
                    }
                }
            }
        }
        vector<vector<char>> v(n, vector<char>(m));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                v[j][m - i - 1] = b[i][j];
            }
        }
        return v;
    }
};