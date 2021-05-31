#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
  {
    sort(products.begin(), products.end());
    vector<vector<string>> ans(0);
    for (int i = 0; i < searchWord.length(); i++)
    {
      products = filter(products, searchWord[i], i);
      ans.push_back(getTopThree(products));
    }

    return ans;
  }

private:
  vector<string> filter(vector<string> products, char c, int position)
  {
    vector<string> matches(0);
    for (auto product : products)
      if (position < product.length() && product[position] == c)
        matches.push_back(product);

    return matches;
  }

private:
  vector<string> getTopThree(vector<string> products)
  {
    if (products.size() <= 3)
      return products;

    vector<string> top(3);
    for (int i = 0; i < 3; i++)
      top[i] = products[i];

    return top;
  }
};