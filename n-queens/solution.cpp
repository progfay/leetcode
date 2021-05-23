#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<string>> solveNQueens(int n)
  {
    vector<vector<string>> vec;
    vector<string> board(n, string(n, '.'));
    recurse(vec, board, 0, n);
    return vec;
  }

private:
  void recurse(vector<vector<string>> &vec, vector<string> &board, int row, int &n)
  {
    if (row == n)
    {
      vec.push_back(board);
      return;
    }

    for (int col = 0; col < n; ++col)
    {
      if (isValid(board, row, col, n))
      {
        board[row][col] = 'Q';
        recurse(vec, board, row + 1, n);
        board[row][col] = '.';
      }
    }
  }

  inline bool isValid(vector<string> &board, int row, int col, int n)
  {
    for (int i = 0; i < row; ++i)
      if (board[i][col] == 'Q')
        return false;

    for (int i = 1; row - i >= 0 && col - i >= 0; ++i)
      if (board[row - i][col - i] == 'Q')
        return false;

    for (int i = 1; row - i >= 0 && col + i < n; ++i)
      if (board[row - i][col + i] == 'Q')
        return false;

    return true;
  }
};