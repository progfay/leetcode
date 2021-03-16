#include <vector>

using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices, int fee)
  {
    int bestProfitOnSell = 0;
    int bestProfitOnBuy = -prices[0];

    for (int price : prices)
    {
      bestProfitOnSell = max(bestProfitOnSell, bestProfitOnBuy + price - fee);
      bestProfitOnBuy = max(bestProfitOnBuy, bestProfitOnSell - price);
    }

    return bestProfitOnSell;
  }
};