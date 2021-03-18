#include <vector>

using namespace std;

class Solution
{
public:
  int wiggleMaxLength(vector<int> &nums)
  {
    if (nums.size() <= 1)
      return nums.size();

    int ans = 1;
    int direction = 0;
    int before = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
      int num = nums[i];
      int diff = num - before;

      if (direction == 0 && diff != 0)
      {
        ans++;
        before = num;
        direction = diff > 0 ? 1 : -1;
        continue;
      }

      before = num;
      if (diff * direction < 0)
      {
        direction *= -1;
        ans++;
      }
    }

    return ans;
  }
};