#include <vector>

using namespace std;

class Solution
{
private:
  int time;
  vector<int> disc, lowlink, parent;
  vector<vector<int>> g, answer;

private:
  void dfs(int node)
  {
    disc[node] = time;
    lowlink[node] = time++;

    int count = 0;
    for (auto &nei : g[node])
    {
      if (disc[nei] == -1)
      {
        parent[nei] = node;
        count++;

        dfs(nei);
        lowlink[node] = min(lowlink[node], lowlink[nei]);

        if (lowlink[nei] > disc[node])
          answer.push_back({nei, node});
      }
      else if (nei != parent[node])
        lowlink[node] = min(lowlink[node], disc[nei]);
    }
  }

public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
  {
    time = 0;
    disc.resize(n, -1);
    lowlink.resize(n, -1);
    parent.resize(n, -1);
    g.resize(n, vector<int>());

    for (auto &it : connections)
      g[it[0]].push_back(it[1]), g[it[1]].push_back(it[0]);

    for (int i = 0; i != n; i++)
      if (disc[i] == -1)
        dfs(i);

    return answer;
  }
};
