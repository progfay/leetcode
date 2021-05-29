class Solution
{
public:
  int totalNQueens(int n)
  {
    return count(n, 0, 0, 0, 0);
  }

private:
  int count(int n, int row, int col, int l, int r)
  {
    if (row == n)
      return 1;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      int colMask = 1 << i, lMask = 1 << row + i, rMask = 1 << row - i + n - 1;
      if (!(col & colMask) && !(l & lMask) && !(r & rMask))
        ans += count(n, row + 1, col | colMask, l | lMask, r | rMask);
    }
    return ans;
  }
};
