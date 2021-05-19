#include <vector>;
#include <algorithm>;

using namespace std;

class Solution
{
public:
  int minMoves2(vector<int> &nums)
  {
    int ans = 0;
    int median = calcMedian(nums);
    for (auto num : nums)
      ans += abs(median - num);
    return ans;
  }

private:
  int calcMedian(vector<int> nums)
  {
    int n = nums.size();
    nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
    if (n % 2 == 1)
      return nums[n / 2];

    nth_element(nums.begin(), nums.begin() + (n - 1) / 2, nums.end());
    return (nums[(n - 1) / 2] + nums[n / 2]) / 2;
  }
};
