#include <string>

using namespace std;

class Solution
{
public:
  int romanToInt(string s)
  {
    int ans = 0;
    int before = 0;
    bool negative = false;
    for (int i = s.length(); i >= 0; i--)
    {
      int current = 0;
      char c = s[i];
      if (c == 'I')
      {
        current = 1;
      }
      else if (c == 'V')
      {

        current = 5;
      }
      else if (c == 'X')
      {

        current = 10;
      }
      else if (c == 'L')
      {

        current = 50;
      }
      else if (c == 'C')
      {

        current = 100;
      }
      else if (c == 'D')
      {

        current = 500;
      }
      else if (c == 'M')
      {

        current = 1000;
      }

      if (current != before)
      {
        negative = current < before;
        before = current;
      }

      ans += (negative ? -1 : 1) * current;
    }

    return ans;
  }
};