#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  int m, n;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  queue<pair<int, int>> pacific;
  queue<pair<int, int>> atlantic;

  inline bool isValid(int x, int y)
  {
    return x >= 0 && x < m && y >= 0 && y < n;
  }

  void bfs(queue<pair<int, int>> &q, vector<vector<bool>> &visited, vector<vector<int>> &matrix)
  {
    while (!q.empty())
    {
      int x = q.front().first;
      int y = q.front().second;
      visited[x][y] = true;
      q.pop();
      for (int k = 0; k < 4; k++)
      {
        int xx = x + dx[k];
        int yy = y + dy[k];
        if (isValid(xx, yy) && matrix[x][y] <= matrix[xx][yy] && !visited[xx][yy])
        {
          q.push({xx, yy});
        }
      }
    }
  }

  vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
  {
    vector<vector<int>> ans;
    m = matrix.size();
    if (m == 0)
      return ans;
    n = matrix.front().size();
    if (n == 0)
      return ans;

    vector<vector<bool>> visited_pacific(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
      pacific.push({i, 0});
    for (int i = 0; i < n; i++)
      pacific.push({0, i});
    bfs(pacific, visited_pacific, matrix);

    vector<vector<bool>> visited_atlantic(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
      atlantic.push({i, n - 1});
    for (int i = 0; i < n; i++)
      atlantic.push({m - 1, i});
    bfs(atlantic, visited_atlantic, matrix);

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (visited_pacific[i][j] && visited_atlantic[i][j])
          ans.push_back({i, j});

    return ans;
  }
};
