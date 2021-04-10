#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int longestIncreasingPath(vector<vector<int>> &matrix)
  {
    priority_queue<pair<int, pair<int, int>>> q;
    int m = matrix.size();
    int n = matrix.front().size();

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        q.push(make_pair(matrix[i][j], make_pair(i, j)));

    vector<vector<int>> lengthMap(m, vector<int>(n));
    int ans = 0;

    while (!q.empty())
    {
      auto v = q.top();
      q.pop();

      int len = 1;
      int c = v.first;
      int x = v.second.first;
      int y = v.second.second;
      if (x - 1 >= 0 && matrix[x - 1][y] > c)
        len = max(len, 1 + lengthMap[x - 1][y]);
      if (y - 1 >= 0 && matrix[x][y - 1] > c)
        len = max(len, 1 + lengthMap[x][y - 1]);
      if (x + 1 < m && matrix[x + 1][y] > c)
        len = max(len, 1 + lengthMap[x + 1][y]);
      if (y + 1 < n && matrix[x][y + 1] > c)
        len = max(len, 1 + lengthMap[x][y + 1]);

      ans = max(ans, len);
      lengthMap[x][y] = len;
    }

    return ans;
  }
};