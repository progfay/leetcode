#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class FreqStack
{
  priority_queue<vector<int>> q;
  unordered_map<int, int> m;
  int i = 0;

public:
  FreqStack()
  {
  }

  void push(int x)
  {
    ++m[x];
    q.push({m[x], i++, x});
  }

  int pop()
  {
    vector<int> p = q.top();
    q.pop();

    --m[p[2]];

    return p[2];
  }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */