#include <vector>

using namespace std;

class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int row = matrix.size();
    int i = 0;
    int j = matrix[0].size() - 1;

    while (true)
    {
      if (matrix[i][j] == target)
        return true;

      if (matrix[i][j] > target)
        j--;
      else if (matrix[i][j] < target)
        i++;

      if (i >= row || j < 0)
        break;
    }

    return false;
  }
};