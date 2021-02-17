#include <vector>

using namespace std;

class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int leftIndex = 0;
    int rightIndex = height.size() - 1;
    int maxArea = 0;

    while (leftIndex < rightIndex)
    {
      int left = height.at(leftIndex);
      int right = height.at(rightIndex);
      int area = min(left, right) * (rightIndex - leftIndex);
      maxArea = max(maxArea, area);
      left < right ? leftIndex++ : rightIndex--;
    }

    return maxArea;
  }
};