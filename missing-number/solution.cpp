#include <vector>
#include <bitset>

using namespace std;

class Solution
{
public:
  int missingNumber(vector<int> &nums)
  {
    bitset<10001> bits(0);
    for (int num : nums)
    {
      bits.set(num);
    }

    for (int i = 0; i < nums.size(); i++)
    {
      if (!bits.test(i))
      {
        return i;
      }
    }

    return nums.size();
  }
};