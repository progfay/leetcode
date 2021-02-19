#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  string minRemoveToMakeValid(string s)
  {
    string t;
    int nestCount = 0;
    for (char c : s)
    {
      if (c == '(')
      {
        nestCount++;
      }
      else if (c == ')')
      {
        if (nestCount <= 0)
        {
          continue;
        }
        nestCount--;
      }
      t += c;
    }

    reverse(t.begin(), t.end());

    string u;
    nestCount = 0;
    for (char c : t)
    {
      if (c == ')')
      {
        nestCount++;
      }
      else if (c == '(')
      {
        if (nestCount <= 0)
        {
          continue;
        }
        nestCount--;
      }
      u += c;
    }

    reverse(u.begin(), u.end());
    return u;
  }
};