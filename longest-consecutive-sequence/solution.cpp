#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    unordered_set<int> s(nums.begin(), nums.end());
    int ans = 0;

    for (auto num : nums)
    {
      if (s.count(num - 1))
        continue;

      int size = 1;
      while (s.count(++num))
        size++;

      ans = max(ans, size);
    }

    return ans;
  }
};