#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  bool isInterleave(string s1, string s2, string s3)
  {
    int n = s1.length(), m = s2.length(), k = s3.length();
    if (n + m != k)
      return false;

    vector<bool> dp(m + 1, 0);
    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= m; j++)
      {
        if (i == 0 && j == 0)
          dp[j] = true;
        else if (i == 0)
          dp[j] = dp[j - 1] && s2[j - 1] == s3[i + j - 1];
        else if (j == 0)
          dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1];
        else
          dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
      }
    }

    return dp[m];
  }
};