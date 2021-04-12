#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> constructArray(int n, int k)
  {
    vector<int> ans(n);
    int head = 1, tail = n;
    int reversed = false;

    for (int i = 0; i < n; i++)
    {
      ans[i] = reversed ? tail-- : head++;
      if (k == 1)
        continue;
      reversed = !reversed;
      k--;
    }

    return ans;
  }
};