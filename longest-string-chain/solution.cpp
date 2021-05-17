#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int longestStrChain(vector<string> &words)
  {
    sort(words.begin(), words.end(), [](const string &s1, const string &s2)
         { return s1.length() > s2.length(); });

    unordered_map<string, int> m;
    int n = words.size();

    for (int i = 0; i < n; i++)
      m[words[i]] = i;

    int ans = 1;
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < words[i].length(); j++)
      {
        string new_string = words[i].substr(0, j) + words[i].substr(j + 1);
        if (m.count(new_string))
        {
          dp[m[new_string]] = max(dp[m[new_string]], 1 + dp[i]);
          ans = max(ans, dp[m[new_string]]);
        }
      }
    }
    return ans;
  }
};