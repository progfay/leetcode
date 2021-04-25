#include <vector>

using namespace std;

class Solution
{
public:
  void rotate(vector<vector<int>> &matrix)
  {
    int i, j;
    const int n = matrix.size();
    for (i = 0; i < n; ++i)
      for (j = 0; j < n / 2; ++j)
        swap(matrix[j][i], matrix[n - j - 1][i]);

    for (i = 0; i < n; ++i)
      for (j = i + 1; j < n; ++j)
        swap(matrix[j][i], matrix[i][j]);
  }
};