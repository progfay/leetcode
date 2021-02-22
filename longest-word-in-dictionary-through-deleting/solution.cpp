#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
  string findLongestWord(string s, vector<string> &d)
  {
    ios_base::sync_with_stdio(0), cin.tie(0);
    sort(d.begin(), d.end(), [](const string &s1, const string &s2) { return s1.length() != s2.length() ? s1.length() > s2.length() : s1 < s2; });

    for (string w : d)
    {
      if (match(s, w))
        return w;
    }

    return "";
  }

private:
  inline bool match(string &s, string &w)
  {
    int cursor = 0;
    int length = w.length();

    for (char c : s)
    {
      if (c != w[cursor])
        continue;

      if (++cursor == length)
        return true;
    }

    return false;
  }
};