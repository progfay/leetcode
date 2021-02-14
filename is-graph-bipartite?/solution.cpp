#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  bool isBipartite(vector<vector<int>> &graph)
  {
    if (graph.size() == 0)
    {
      return true;
    }

    vector<int> colors(graph.size(), 0);
    queue<int> que;

    for (int i = 0; i < colors.size(); i++)
    {
      if (colors.at(i) != 0)
      {
        continue;
      }

      colors.at(i) = 1;
      que.push(i);

      while (!que.empty())
      {
        int curr = que.front();
        que.pop();

        for (int next : graph.at(curr))
        {
          if (colors.at(curr) == colors.at(next))
          {
            return false;
          }

          if (colors.at(next) == 0)
          {
            colors.at(next) = -colors.at(curr);
            que.push(next);
          }
        }
      }
    }
    return true;
  }
};