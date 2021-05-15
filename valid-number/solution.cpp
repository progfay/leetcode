#include <string>
#include <regex>

using namespace std;

class Solution
{
public:
  bool isNumber(string s)
  {
    if (s[0] == '+' || s[0] == '-')
      s = s.substr(1);

    string s1 = "", s2 = "";
    auto pos = s.find("e");
    if (pos == string::npos)
      pos = s.find("E");
    if (pos == string::npos)
      s1 = s;
    else if (pos == 0 || pos == s.length() - 1)
      return false;
    else
    {
      s1 = s.substr(0, pos);
      s2 = s.substr(pos + 1);
    }

    if (s1 == ".")
      return false;

    int dotCount = 0;

    for (auto c : s1)
    {
      if ('0' <= c && c <= '9')
        continue;

      if (c == '.')
        if (dotCount++ == 1)
          return false;
        else
          continue;

      return false;
    }

    if (s2 == "")
      return true;

    if (s2[0] == '+' || s2[0] == '-')
      s2 = s2.substr(1);

    if (s2 == "")
      return false;

    for (auto c : s2)
    {
      if ('0' <= c && c <= '9')
        continue;
      else
        return false;
    }

    return true;
  }
};
