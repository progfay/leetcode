#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int maxEnvelopes(vector<vector<int>> &envelopes)
  {
    sort(envelopes.begin(), envelopes.end(), [](const vector<int> &e1, const vector<int> &e2) {
      return e1[0] == e2[0] ? e1[1] < e2[1] : e1[0] < e2[0];
    });

    vector<int> dp(envelopes.size());
    for (int i = 0; i < envelopes.size(); i++)
      for (int j = 0; j < i; j++)
        if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
          dp[i] = max(dp[i], dp[j] + 1);

    return *max_element(dp.begin(), dp.end()) + 1;
  }
};
