#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
  const int MOD = 1000000007;
  int maxCut(int length, vector<int> &cuts)
  {
    if (cuts.size() == 0)
      return length;

    sort(cuts.begin(), cuts.end());
    int maximum = max(cuts.front(), length - cuts.back());
    for (int i = 1; i < cuts.size(); i++)
      maximum = max(maximum, cuts[i] - cuts[i - 1]);

    return maximum;
  }

public:
  long maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
  {
    return long(maxCut(h, horizontalCuts)) * maxCut(w, verticalCuts) % MOD;
  }
};