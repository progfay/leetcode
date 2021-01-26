#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
  int minimumEffortPath(vector<vector<int>> &heights)
  {
    int rows = heights.size();
    int columns = heights.at(0).size();

    if (canReach(heights, rows, columns, 0))
    {
      return 0;
    }

    int left = 0;
    int right = 10e6;

    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      if (canReach(heights, rows, columns, mid))
      {
        right = mid;
      }
      else
      {
        left = mid;
      }

      if (right - left == 1)
      {
        break;
      }
    }

    return right;
  }

private:
  bool canReach(vector<vector<int>> &heights, int rows, int columns, int effort)
  {
    vector<vector<bool>> map(rows, vector<bool>(columns, false));
    fill(heights, map, rows, columns, 0, 0, heights.at(0).at(0), effort);
    return map.back().back();
  }

  void fill(vector<vector<int>> &heights, vector<vector<bool>> &map, int rows, int columns, int x, int y, int beforeHeight, int effort)
  {
    if (map.at(y).at(x))
    {
      return;
    }

    int height = heights.at(y).at(x);
    int step = abs(beforeHeight - height);
    if (step > effort)
    {
      return;
    }

    map.at(y)[x] = true;

    if (x > 0)
    {
      fill(heights, map, rows, columns, x - 1, y, height, effort);
    }

    if (x < columns - 1)
    {
      fill(heights, map, rows, columns, x + 1, y, height, effort);
    }

    if (y > 0)
    {
      fill(heights, map, rows, columns, x, y - 1, height, effort);
    }

    if (y < rows - 1)
    {
      fill(heights, map, rows, columns, x, y + 1, height, effort);
    }
  }
};
