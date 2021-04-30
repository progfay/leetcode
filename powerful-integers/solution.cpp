#include <vector>
#include <bitset>

using namespace std;

class Solution
{
public:
  vector<int> powerfulIntegers(int x, int y, int bound)
  {
    vector<int> ans(0);

    if (x == 1 || y == 1)
    {
      int v = x == 1 ? y : x;
      if (v == 1)
      {
        if (bound >= 2)
          ans.push_back(2);
        return ans;
      }

      for (int i = 1; i < bound; i *= v)
        ans.push_back(i + 1);

      return ans;
    }

    vector<int> xs(0);
    for (int i = 1; i <= bound; i *= x)
      xs.push_back(i);

    vector<int> ys(0);
    for (int i = 1; i <= bound; i *= y)
      ys.push_back(i);

    bitset<1000001> bits;
    for (int i : xs)
    {
      for (int j : ys)
      {
        if (i + j > bound)
          break;
        bits.set(i + j);
      }
    }

    for (int i = 2; i <= bound; i++)
      if (bits[i])
        ans.push_back(i);

    return ans;
  }
};