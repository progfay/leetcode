#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
private:
  static bool cmp(vector<int> &a, vector<int> &b)
  {
    return a[1] < b[1];
  }

public:
  int scheduleCourse(vector<vector<int>> &courses)
  {
    sort(courses.begin(), courses.end(), cmp);
    priority_queue<int> pq;
    int time_taken = 0;
    for (auto c : courses)
    {
      if (time_taken + c[0] <= c[1])
      {
        time_taken += c[0];
        pq.push(c[0]);
      }
      else
      {
        if (!pq.empty() && pq.top() > c[0])
        {
          int top = pq.top();
          pq.pop();
          time_taken -= top;
          pq.push(c[0]);
          time_taken += c[0];
        }
      }
    }
    return pq.size();
  }
};