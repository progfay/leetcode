#include <vector>

using namespace std;

class Solution
{
public:
  int coinChange(vector<int> &coins, int amount)
  {
    vector<long int> dp(amount + 1, __INT_MAX__);
    dp[0] = 0;

    for (int i = 0; i <= amount; i++)
    {
      for (auto coin : coins)
      {
        if (coin <= i)
          dp[i] = min(dp[i], dp[i - coin] + 1);
      }
    }

    return dp.back() == __INT_MAX__ ? -1 : dp.back();
  }
};