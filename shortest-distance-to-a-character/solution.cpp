#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> shortestToChar(string s, char c)
  {
    vector<int> answer(s.length());

    int distance = 1e5;
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == c)
      {
        distance = 0;
      }
      answer.at(i) = distance++;
    }

    distance = 1e5;
    for (int i = s.length() - 1; i >= 0; i--)
    {
      int a = answer.at(i);
      if (a == 0)
      {
        distance = 0;
      }
      answer.at(i) = min(a, distance++);
    }

    return answer;
  }
};