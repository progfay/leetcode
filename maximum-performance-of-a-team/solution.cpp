#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

class Solution
{
public:
  int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
  {
    vector<pair<int, int>> perf(n);
    for (int i = 0; i < n; i++)
      perf[i] = make_pair(efficiency[i], speed[i]);

    sort(perf.rbegin(), perf.rend());

    priority_queue<int, vector<int>, greater<int>> q;
    long long sumSpeed = 0, ans = 0;
    for (auto p : perf)
    {
      q.push(p.second);
      sumSpeed += p.second;
      if (q.size() > k)
      {
        sumSpeed -= q.top();
        q.pop();
      }
      ans = max(ans, sumSpeed * p.first);
    }
    return ans % 1000000007;
  }
};