#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int leastBricks(vector<vector<int>> &wall)
  {
    int width = 0;
    for (auto w : wall.front())
      width += w;

    unordered_map<int, int> m;

    for (auto row : wall)
    {
      int width = 0;
      for (int i = 0; i < row.size() - 1; i++)
      {
        width += row[i];
        m[width - 1]++;
      }
    }

    int ans = 0;
    for (auto p : m)
      ans = max(ans, p.second);

    return wall.size() - ans;
  }
};