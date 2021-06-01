#include <vector>

using namespace std;

class Solution
{
public:
  int maxAreaOfIsland(vector<vector<int>> &grid)
  {
    int ans = 0;
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[i].size(); j++)
      {
        int count = 0;
        fill(grid, i, j, count);
        if (ans < count)
          ans = count;
      }
    }

    return ans;
  }

private:
  inline void fill(vector<vector<int>> &grid, int i, int j, int &count)
  {
    if (i < 0 || grid.size() <= i)
      return;
    if (j < 0 || grid.front().size() <= j)
      return;

    if (grid[i][j] != 1)
      return;

    count++;
    grid[i][j] = 2;
    fill(grid, i - 1, j, count);
    fill(grid, i + 1, j, count);
    fill(grid, i, j - 1, count);
    fill(grid, i, j + 1, count);
  }
};