#include <vector>

using namespace std;

class Solution
{
public:
  int maxScore(vector<int> &cardPoints, int k)
  {
    unsigned int sum = 0;
    unsigned int window = 0;
    unsigned int minWindow = __INT_MAX__;
    unsigned int windowSize = cardPoints.size() - k;

    for (int i = 0; i < cardPoints.size(); i++)
    {
      sum += cardPoints[i];
      window += cardPoints[i];

      if (i < windowSize)
      {
        if (i == windowSize - 1)
          minWindow = window;
        continue;
      }

      window -= cardPoints[i - windowSize];
      minWindow = min(minWindow, window);
    }

    return sum - minWindow;
  }
};