#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  int maxResult(vector<int> &nums, int k)
  {
    int size = nums.size();
    if (size == 1)
      return nums.front();
    priority_queue<pair<int, int>> q;
    q.push(make_pair(nums[size - 1], size - 1));

    for (int i = size - 2; i >= 0; --i)
    {
      auto top = q.top();
      while (top.second - i > k)
      {
        q.pop();
        top = q.top();
      }
      q.push(make_pair(top.first + nums[i], i));

      if (i == 0)
        return top.first + nums[i];
    }
    return -1;
  }
};