#include <vector>

using namespace std;

class Solution
{
public:
  bool isIdealPermutation(vector<int> &A)
  {
    int n = A.size();
    if (n < 3)
      return true;

    int a = A[0];
    for (int i = 2; i < n; i++)
    {
      if (A[i] < a)
        return false;
      a = max(a, A[i - 1]);
    }
    return true;
  }
};