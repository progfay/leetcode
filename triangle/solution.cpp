#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int minimumTotal(vector<vector<int>> &triangle)
  {
    vector<int> prev = triangle.front();

    for (int i = 1; i < triangle.size(); i++)
    {
      vector<int> dp(triangle[i].size(), __INT_MAX__);
      for (int j = 0; j < prev.size(); j++)
      {
        dp[j] = min(dp[j], prev[j] + triangle[i][j]);
        dp[j + 1] = min(dp[j + 1], prev[j] + triangle[i][j + 1]);
      }
      prev = dp;
    }

    return *min_element(prev.begin(), prev.end());
  }
};