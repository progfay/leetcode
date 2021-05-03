#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> runningSum(vector<int> &nums)
  {
    int sum = 0;
    vector<int> ans(nums.size(), 0);

    for (int i = 0; i < nums.size(); i++)
      ans[i] = sum += nums[i];

    return ans;
  }
};