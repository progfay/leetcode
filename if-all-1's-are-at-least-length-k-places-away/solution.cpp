#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  bool kLengthApart(vector<int> &nums, int k)
  {
    int space = k + 1;
    for (int i = 0; i < nums.size(); i++)
    {
      switch (nums.at(i))
      {
      case 0:
        space++;
        continue;

      case 1:
        if (space < k)
        {
          return false;
        }
        space = 0;
        continue;
      }
    }

    return true;
  }
};
