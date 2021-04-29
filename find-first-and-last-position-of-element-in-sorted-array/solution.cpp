#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<int> searchRange(vector<int> &nums, int target)
  {
    vector<int> ans(2, -1);
    auto lower = lower_bound(nums.begin(), nums.end(), target);
    if (lower == nums.end() || *lower != target) {
      return ans;
    }

    auto upper = upper_bound(nums.begin(), nums.end(), target);
    ans[0] = distance(nums.begin(), lower);
    ans[1] = distance(nums.begin(), upper) - 1;
    return ans;
  }
};