#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  int furthestBuilding(vector<int> &heights, int bricks, int ladders)
  {
    priority_queue<int> q;

    for (int i = 0; i < heights.size() - 1; i++)
    {
      int diff = heights[i + 1] - heights[i];
      if (diff <= 0)
        continue;

      q.push(diff);
      bricks -= diff;

      if (bricks >= 0)
        continue;

      if (ladders == 0)
        return i;

      ladders--;
      bricks += q.top();
      q.pop();
    }

    return heights.size() - 1;
  }
};