#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<string> ambiguousCoordinates(string s)
  {
    vector<string> ans(0);
    s = s.substr(1, s.length() - 2);

    for (int i = 1; i < s.length(); i++)
    {
      auto left = calcCandidates(s.substr(0, i));
      auto right = calcCandidates(s.substr(i));
      for (auto l : left)
        for (auto r : right)
          ans.push_back("(" + l + ", " + r + ")");
    }

    return ans;
  }

  vector<string> calcCandidates(string s)
  {
    if (s.length() == 1)
      return {s};

    if (s.front() == '0' && s.back() == '0')
      return {};

    if (s.back() == '0')
      return {s};

    if (s.front() == '0')
      return {"0." + s.substr(1)};

    vector<string> candidates(0);
    for (int i = 1; i < s.length(); i++)
      candidates.push_back(s.substr(0, i) + "." + s.substr(i));
    candidates.push_back(s);
    return candidates;
  }
};