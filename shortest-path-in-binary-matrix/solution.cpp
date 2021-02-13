#include <vector>
#include <queue>

using namespace std;

class Solution
{
private:
  pair<int, int> direction[8] = {{1, 1}, {1, 0}, {0, 1}, {1, -1}, {-1, 1}, {0, -1}, {-1, 0}, {-1, -1}};

public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid)
  {
    int size = grid.size();
    if (grid[0][0] == 1 || grid[size - 1][size - 1] == -1)
    {
      return -1;
    }

    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});

    while (!q.empty())
    {
      pair<pair<int, int>, int> entry = q.front();
      q.pop();
      int x = entry.first.first;
      int y = entry.first.second;
      int c = entry.second;
      if (x == size - 1 && y == size - 1)
      {
        return c;
      }

      for (pair<int, int> dir : direction)
      {
        int nx = x + dir.first;
        int ny = y + dir.second;
        int nc = c + 1;
        if (nx < 0 || size <= nx || ny < 0 || size <= ny || grid[nx][ny] == 1)
        {
          continue;
        }

        grid[nx][ny] = 1;
        q.push({{nx, ny}, nc});
      }
    }

    return -1;
  }
};