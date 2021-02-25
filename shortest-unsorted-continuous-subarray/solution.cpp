#include <vector>

using namespace std;

class Solution
{
public:
  int findUnsortedSubarray(vector<int> &nums)
  {
    int right = -2;
    int num_max = -1e6;

    for (int i = 0; i < nums.size(); i++)
    {
      if (num_max < nums[i])
        num_max = nums[i];

      if (num_max > nums[i])
        right = i;
    }

    int left = -1;
    int num_min = 1e6;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
      if (num_min > nums[i])
        num_min = nums[i];

      if (num_min < nums[i])
        left = i;
    }

    return right - left + 1;
  }
};