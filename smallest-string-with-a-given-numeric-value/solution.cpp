#include <string>

using namespace std;

class Solution
{
public:
  string getSmallestString(int n, int k)
  {
    int l = k - n;
    int zCount = l / 25;
    int middleChar = l % 25;
    int aCount = n - zCount - 1;
    string ans = "";
    if (aCount > 0)
    {
      ans += string(aCount, 'a');
    }
    if (aCount != -1)
    {
      ans += (char)(97 + middleChar);
    }
    if (zCount > 0)
    {
      ans += string(zCount, 'z');
    }
    return ans;
  }
};