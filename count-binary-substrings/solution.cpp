#include <string>

using namespace std;

class Solution
{
public:
  int countBinarySubstrings(string s)
  {
    char bc = ' ';
    int prevCount = 0, count = 0;
    int ans = 0;

    for (auto c : s)
    {
      if (c == bc)
      {
        count++;
        continue;
      }

      bc = c;
      ans += min(prevCount, count);
      prevCount = count;
      count = 1;
    }

    ans += min(prevCount, count);
    return ans;
  }
};