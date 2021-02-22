#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  string findLongestWord(string s, vector<string> &d)
  {
    sort(d.begin(), d.end(), [](const string &s1, const string &s2) { return s1.length() > s2.length(); });
    string ans = "";

    for (string w : d)
    {
      if (ans != "" && w.length() < ans.length())
        return ans;

      if (!match(s, w))
        continue;

      if (ans == "" || ans > w)
        ans = w;
    }

    return ans;
  }

private:
  bool match(string s, string w)
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