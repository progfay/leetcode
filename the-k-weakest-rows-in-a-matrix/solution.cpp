#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
  {
    int m = mat.size();
    int n = mat.at(0).size();

    vector<int> ans;
    int cursor = 0;
    while (cursor < n)
    {
      for (int i = 0; i < m; i++)
      {
        if (mat.at(i).at(cursor) == 0)
        {
          ans.push_back(i);
          mat.at(i) = vector<int>(n, 2);
          if (--k == 0)
          {
            return ans;
          }
        }
      }
      cursor++;
    }

    for (int i = 0; i < m; i++)
    {
      if (mat.at(i).at(0) == 2)
      {
        continue;
      }

      ans.push_back(i);

      if (--k == 0)
      {
        return ans;
      }
    }

    return ans;
  }
};