#include <vector>

using namespace std;

class Solution
{
public:
  int numberOfArithmeticSlices(vector<int> &A)
  {
    int size = A.size();
    if (size < 3)
    {
      return 0;
    }

    int diff = A[1] - A[0];
    int count = 2;
    int ans = 0;

    for (int i = 1; i < size - 1; i++)
    {
      int d = A[i + 1] - A[i];
      if (diff == d)
      {
        count++;
        continue;
      }

      diff = d;
      ans += (count - 2) * (count - 1) / 2;
      count = 2;
    }

    ans += (count - 2) * (count - 1) / 2;
    return ans;
  }
};