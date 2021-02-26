#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
  {
    stack<int> s;
    int cursor = 0;

    for (int v : pushed)
    {
      s.push(v);
      while (!s.empty() && s.top() == popped[cursor])
      {
        cursor++;
        s.pop();
      }
    }
    return s.empty();
  }
};