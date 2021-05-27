#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  int maxProduct(vector<string> &words)
  {
    vector<pair<int, int>> pairs(0);
    for (auto word : words)
    {
      int bits = 0;
      for (auto c : word)
        bits |= 1 << (c - 'a');
      pairs.push_back(make_pair(bits, word.length()));
    }

    int ans = 0;
    for (int i = 0; i < pairs.size(); i++)
      for (int j = i + 1; j < pairs.size(); j++)
        if ((pairs[i].first & pairs[j].first) == 0)
          ans = max(ans, pairs[i].second * pairs[j].second);

    return ans;
  }
};