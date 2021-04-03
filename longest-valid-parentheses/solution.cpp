#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int longestValidParentheses(string s)
  {
    int l2r = exploreFromLeftToRight(s, '(');
    reverse(s.begin(), s.end());
    int r2l = exploreFromLeftToRight(s, ')');

    return max(l2r, r2l);
  }

private:
  inline int exploreFromLeftToRight(string s, char open)
  {
    int left = 0, right = 0, len = 0;
    for (auto c : s)
    {
      if (c == open)
        left++;
      else
        right++;

      if (left == right)
        len = max(len, left + right);
      else if (left < right)
      {
        left = 0;
        right = 0;
      }
    }

    return len;
  }
};
