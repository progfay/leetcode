#include <string>

using namespace std;

class Solution
{
public:
  int countSubstrings(string s)
  {
    int ans = 0;
    int length = s.length();
    for (int i = 0; i < length; i++)
    {
      int left = i, right = i;
      while (left >= 0 && right < length)
        if (s[left--] == s[right++])
          ans++;
        else
          break;
    }

    for (int i = 0; i < length - 1; i++)
    {
      int left = i, right = i + 1;
      while (left >= 0 && right < length)
      {
        if (s[left--] == s[right++])
          ans++;
        else
          break;
      }
    }

    return ans;
  }
};