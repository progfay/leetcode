#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
public:
  vector<int> advantageCount(vector<int> &A, vector<int> &B)
  {
    int size = A.size();
    vector<int> a = sorted(A);
    vector<int> b = sorted(B);

    map<int, vector<int>> m;
    vector<int> rest(0);
    int cursor = 0;
  loop:
    for (int v : b)
    {
      while (cursor < size && a[cursor] <= v)
      {
        rest.push_back(a[cursor++]);
      }

      if (cursor == size)
        break;

      m[v].push_back(a[cursor++]);
    }

    vector<int> ans(0);
    for (int v : B)
    {
      if (!m[v].empty())
      {
        ans.push_back(m[v].back());
        m[v].pop_back();
      }
      else
      {
        ans.push_back(rest.back());
        rest.pop_back();
      }
    }

    return ans;
  }

private:
  vector<int> sorted(vector<int> &vec)
  {
    vector<int> cp(vec.size());
    copy(vec.begin(), vec.end(), cp.begin());
    sort(cp.begin(), cp.end());
    return cp;
  }
};