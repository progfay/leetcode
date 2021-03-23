#include <vector>

using namespace std;

class Solution
{
private:
  const int MOD = 1e9 + 7;

public:
  int threeSumMulti(vector<int> &arr, int target)
  {
    int size = arr.size();
    int ans = 0;
    for (int i = 0; i < size - 2; i++)
    {
      int t = target - arr[i];
      int m[301] = {0};

      for (int j = i + 1; j < size; j++)
      {
        int e = arr[j];
        if (t >= e)
          ans = (ans + m[t - e]) % MOD;
        m[e] = (m[e] + 1) % MOD;
      }
    }

    return ans;
  }
};