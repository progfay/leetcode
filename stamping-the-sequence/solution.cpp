#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<int> movesToStamp(string stamp, string target)
  {
    string seq(target.length(), '?');
    vector<int> res(0);
    while (target != seq)
    {
      int index = isMatching(target, stamp);
      if (index == -1)
        return {};
      res.push_back(index);
    }

    reverse(res.begin(), res.end());
    return res;
  }

private:
  inline int isMatching(string &target, string stamp)
  {
    for (int i = 0; i < target.length(); i++)
    {
      int j = 0;
      int matches = 0;
      for (j = 0; j < stamp.length(); j++)
      {
        if (target[i + j] == stamp[j])
          matches++;
        else if (target[i + j] == '?')
          continue;
        else
          break;
      }
      if (j == stamp.length() && matches != 0)
      {
        for (j = 0; j < stamp.length(); j++)
          target[i + j] = '?';
        return i;
      }
    }
    return -1;
  }
};