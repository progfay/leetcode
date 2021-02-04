#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int findLHS(vector<int> &nums)
  {
    if (nums.size() == 0)
    {
      return 0;
    }

    sort(nums.begin(), nums.end());

    int subsequence = 0;
    int before = nums.at(0);
    int leftCount = 0;
    int rightCount = 1;
    bool harmonious = false;

    for (int i = 1; i < nums.size(); i++)
    {
      int current = nums.at(i);
      if (current == before)
      {
        rightCount++;
        continue;
      }

      if (harmonious)
      {
        subsequence = max(subsequence, leftCount + rightCount);
      }

      harmonious = current - before == 1;
      leftCount = rightCount;
      rightCount = 1;
      before = current;
    }

    if (harmonious)
    {
      subsequence = max(subsequence, leftCount + rightCount);
    }

    return subsequence;
  }
};