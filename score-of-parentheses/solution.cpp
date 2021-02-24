#include <string>

using namespace std;

class Solution
{
public:
  int scoreOfParentheses(string S)
  {
    int score = 0;
    int bracket = 0;
    string s = "";

    for (char c : S)
    {
      bracket += c == '(' ? 1 : -1;
      s += c;
      if (bracket == 0)
      {
        score += scoreOfUnit(s);
        s = "";
      }
    }

    return score;
  }

private:
  int scoreOfUnit(string S)
  {
    if (S == "()")
      return 1;

    return scoreOfParentheses(S.substr(1, S.length() - 2)) * 2;
  }
};