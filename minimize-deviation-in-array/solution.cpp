#include <set>
#include <vector>

using namespace std;

class Solution
{
public:
  int minimumDeviation(vector<int> &nums)
  {
    multiset<int, greater<int>> numSet;
    for (auto num : nums)
    {
      numSet.insert(num % 2 == 1 ? num << 1 : num);
    }

    int deviation = *numSet.begin() - *numSet.rbegin();

    while (true)
    {
      int num = *numSet.begin();
      if (num % 2 == 1)
      {
        break;
      }

      numSet.erase(num);
      numSet.insert(num >> 1);
      deviation = min(deviation, *numSet.begin() - *numSet.rbegin());
    }

    return deviation;
  }
};