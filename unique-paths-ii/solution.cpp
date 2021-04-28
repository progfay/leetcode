#include <vector>

using namespace std;

class Solution
{
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
  {
    int m = obstacleGrid.size();
    int n = obstacleGrid.front().size();

    vector<vector<int>> grid(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
      if (obstacleGrid[i][0] == 1)
        break;
      grid[i][0] = 1;
    }

    for (int i = 0; i < n; i++)
    {
      if (obstacleGrid[0][i] == 1)
        break;
      grid[0][i] = 1;
    }

    for (int i = 1; i < m; i++)
      for (int j = 1; j < n; j++)
        grid[i][j] = obstacleGrid[i][j] == 0 ? grid[i - 1][j] + grid[i][j - 1] : 0;

    return grid[m - 1][n - 1];
  }
};