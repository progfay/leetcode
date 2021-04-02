#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  int findMaxForm(vector<string> &strs, int m, int n)
  {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (string str : strs)
    {
      int zeroes = 0;
      int ones = 0;
      for (char c : str)
        if (c == '0')
          zeroes++;
        else
          ones++;

      for (int i = n; i >= ones; i--)
        for (int j = m; j >= zeroes; j--)
          dp[i][j] = max(dp[i][j], dp[i - ones][j - zeroes] + 1);
    }

    return dp[n][m];
  }
};