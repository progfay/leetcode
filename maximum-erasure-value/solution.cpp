#include <vector>

using namespace std;

class Solution
{
public:
  int maximumUniqueSubarray(vector<int> &nums)
  {
    vector<int> indices(10001, -1);
    int left = 0, right = 0, sum = 0, ans = 0;

    for (; right < nums.size(); right++)
    {
      sum += nums[right];

      while (left <= indices[nums[right]])
        sum -= nums[left++];

      indices[nums[right]] = right;
      ans = max(ans, sum);
    }

    return ans;
  }
};