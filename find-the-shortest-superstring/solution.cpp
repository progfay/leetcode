#include <string.h>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
  string shortestSuperstring(vector<string> &words)
  {
    map<pair<int, int>, int> trace;
    vector<int> len(0);
    for (auto word : words)
      len.push_back(word.size());

    for (int i = 0; i < words.size(); i++)
      for (int j = 0; j < words.size(); j++)
        if (i != j)
          cost[i][j] = match(words[i], words[j]);

    memset(dp, -1, sizeof dp);
    int min_ = 1e9, best = 0;
    for (int i = 0; i < words.size(); i++)
    {
      int temp = words[i].size() + solve(i, (1 << i), trace, len, words.size());
      if (temp < min_)
      {
        min_ = temp;
        best = i;
      }
    }

    string ans = words[best];
    int mask = (1 << best);
    for (int i = 1; i < words.size(); i++)
    {
      int prev = best;
      best = trace[{best, mask}];
      ans += words[best].substr(cost[prev][best], words[best].size() - cost[prev][best]);
      mask |= (1 << best);
    }

    return ans;
  }

private:
  int dp[12][(1 << 12)], cost[12][12];

  int match(string &s1, string &s2)
  {
    for (int i = 0; i < s1.size(); i++)
    {
      int j = i, k = 0;
      while (j < s1.size() && k < s2.size())
      {
        if (s1[j] != s2[k])
          break;
        j++;
        k++;
      }
      if (j >= s1.size())
        return s1.size() - i;
    }
    return 0;
  }

  int solve(int index, int mask, map<pair<int, int>, int> &trace, vector<int> len, int n)
  {
    if (mask == (1 << n) - 1)
      return 0;
    if (dp[index][mask] != -1)
      return dp[index][mask];
    dp[index][mask] = 1e9;

    for (int i = 0; i < n; i++)
    {
      if ((mask & (1 << i)) == 0)
      {
        int temp = len[i] - cost[index][i] + solve(i, mask | (1 << i), trace, len, n);
        if (temp < dp[index][mask])
        {
          dp[index][mask] = temp;
          trace[{index, mask}] = i;
        }
      }
    }
    return dp[index][mask];
  }
};