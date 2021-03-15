class Solution
{
public:
  bool check(vector<vector<char>> &v, int i, int j, char val)
  {
    int row = i - i % 3, col = j - j % 3;
    for (int x = 0; x < 9; x++)
      if (v[x][j] == val)
        return false;
    for (int y = 0; y < 9; y++)
      if (v[i][y] == val)
        return false;
    for (int x = 0; x < 3; x++)
      for (int y = 0; y < 3; y++)
        if (v[row + x][col + y] == val)
          return false;
    return true;
  }
  bool solve(vector<vector<char>> &v, int i = 0, int j = 0)
  {
    if (i == 9)
      return true;
    if (j == 9)
      return solve(v, i + 1, 0);
    if (v[i][j] != '.')
      return solve(v, i, j + 1);

    for (char c = '1'; c <= '9'; c++)
    {
      if (check(v, i, j, c))
      {
        v[i][j] = c;
        if (solve(v, i, j + 1))
          return true;
        v[i][j] = '.';
      }
    }
    return false;
  }
  void solveSudoku(vector<vector<char>> &board)
  {
    solve(board);
  }
};