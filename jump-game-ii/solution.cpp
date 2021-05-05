#include <vector>

using namespace std;

class Solution
{
public:
  int jump(vector<int> &nums)
  {
    int size = nums.size();
    vector<int> dp(size, __INT_MAX__);
    dp[0] = 0;

    for (int i = 0; i < size; i++)
    {
      int num = nums[i];
      for (int j = 1; j <= num; j++)
      {
        if (i + j >= size)
          break;

        dp[i + j] = min(dp[i + j], dp[i] + 1);
      }
    }

    return dp.back();
  }
};