#include <string>

using namespace std;

class Solution
{
public:
  string toLowerCase(string s)
  {
    for (int i = 0; i < s.length(); i++)
      if ('A' <= s[i] && s[i] <= 'Z')
        s[i] -= 'A' - 'a';

    return s;
  }
};