#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  bool isPossible(vector<int> &target)
  {
    priority_queue<int> q;
    long sum = 0;
    for (auto v : target)
    {
      sum += v;
      q.push(v);
    }

    while (!q.empty())
    {
      auto v = q.top();
      q.pop();

      if (v == 1)
        return true;

      auto rest = sum - v;
      if (rest <= 0)
        return false;
      if (rest == 1)
        return true;
      if (rest >= v)
        return false;

      rest = v % rest;
      if (rest == 0)
        return false;

      sum -= (v - rest);
      q.push(rest);
    }

    return true;
  }
};