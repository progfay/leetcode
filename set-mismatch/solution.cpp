#include <vector>
#include <bitset>

using namespace std;

class Solution
{
public:
  vector<int> findErrorNums(vector<int> &nums)
  {
    bitset<10001> bits(0);
    vector<int> ans(2, 0);

    for (int num : nums)
    {
      if (bits.test(num))
        ans[0] = num;
      bits.set(num);
    }

    for (int i = 1; i <= nums.size(); i++)
    {
      if (!bits.test(i))
      {
        ans[1] = i;
        break;
      }
    }

    return ans;
  }
};