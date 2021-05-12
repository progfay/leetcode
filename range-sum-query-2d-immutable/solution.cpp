#include <vector>

using namespace std;

class NumMatrix
{
private:
  vector<vector<int>> mat;

public:
  NumMatrix(vector<vector<int>> &matrix)
  {
    mat = matrix;
    for (int i = 0; i < mat.size(); i++)
      for (int j = 1; j < mat.front().size(); j++)
        mat[i][j] += mat[i][j - 1];

    for (int i = 1; i < mat.size(); i++)
      for (int j = 0; j < mat.front().size(); j++)
        mat[i][j] += mat[i - 1][j];
  }

  int sumRegion(int row1, int col1, int row2, int col2)
  {
    int a = row1 > 0 && col1 > 0 ? mat[row1 - 1][col1 - 1] : 0;
    int b = mat[row2][col2];
    int c = row1 > 0 ? mat[row1 - 1][col2] : 0;
    int d = col1 > 0 ? mat[row2][col1 - 1] : 0;
    return a + b - c - d;
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */