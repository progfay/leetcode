#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix)
  {
    int len = matrix.size();
    int head = 0, tail = len - 1;
    int y = 0;
    int tmp1, tmp2;

    while (tail - head > 0)
    {
      for (int x = head; x < tail; x++)
      {
        tmp1 = matrix[y][len - x - 1];
        matrix[y][len - x - 1] = matrix[x][y];
        tmp2 = matrix[len - x - 1][len - y - 1];
        matrix[len - x - 1][len - y - 1] = tmp1;
        tmp1 = matrix[len - y - 1][x];
        matrix[len - y - 1][x] = tmp2;
        matrix[x][y] = tmp1;
      }

      head++;
      tail--;
      y++;
    }
  }
};
