#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
  int evalRPN(vector<string> &tokens)
  {
    stack<int> s;

    for (auto token : tokens)
    {
      if (token == "+")
      {
        int right = s.top();
        s.pop();
        int left = s.top();
        s.pop();
        s.push(left + right);
        continue;
      }

      if (token == "-")
      {
        int right = s.top();
        s.pop();
        int left = s.top();
        s.pop();
        s.push(left - right);
        continue;
      }

      if (token == "*")
      {
        int right = s.top();
        s.pop();
        int left = s.top();
        s.pop();
        s.push(left * right);
        continue;
      }

      if (token == "/")
      {
        int right = s.top();
        s.pop();
        int left = s.top();
        s.pop();
        s.push(left / right);
        continue;
      }

      s.push(parseInt(token));
    }

    return s.top();
  }

private:
  int parseInt(string s)
  {
    bool isPositive = s[0] != '-';
    int cursor = s[0] != '-' ? 0 : 1;
    int value = 0;
    for (; cursor < s.length(); cursor++)
    {
      value *= 10;
      value += s[cursor] - '0';
    }

    return value * (isPositive ? 1 : -1);
  }
};