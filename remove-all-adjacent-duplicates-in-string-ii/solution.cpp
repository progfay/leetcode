#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
  string removeDuplicates(string s, int k)
  {
    stack<pair<char, int>> s1;
    char character = ' ';
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
      char c = s[i];
      if (character == c)
        count++;
      else
      {
        count %= k;
        if (count > 0)
          s1.push(make_pair(character, count));
        character = c;
        count = 1;
      }
    }
    s1.push(make_pair(character, count % k));

    stack<pair<char, int>> s2;
    while (!s1.empty())
    {
      auto p1 = s1.top();
      s1.pop();
      p1.second %= k;

      if (s2.empty())
      {
        if (p1.second > 0)
          s2.push(p1);
        continue;
      }

      auto p2 = s2.top();
      if (p1.first != p2.first)
      {
        s2.push(p1);
        continue;
      }

      s2.pop();
      p1.second = (p1.second + p2.second) % k;
      if (p1.second > 0)
        s2.push(p1);
    }

    string ans = "";
    while (!s2.empty())
    {
      auto p = s2.top();
      ans += string(p.second, p.first);
      s2.pop();
    }

    return ans;
  }
};