#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<string> wordSubsets(vector<string> &A, vector<string> &B)
  {
    vector<int> right(26, 0);
    for (string b : B)
    {
      auto count = charcount(b);
      for (int i = 0; i < 26; i++)
        right[i] = max(right[i], count[i]);
    }

    vector<string> ans(0);
    for (string a : A)
    {
      auto left = charcount(a);
      if (subset(left, right))
        ans.push_back(a);
    }

    return ans;
  }

private:
  inline vector<int> charcount(string S)
  {
    vector<int> count(26, 0);
    for (char c : S)
      count[c - 'a']++;
    return count;
  }

private:
  inline bool subset(vector<int> &A, vector<int> &B)
  {
    for (int i = 0; i < 26; i++)
      if (A[i] < B[i])
        return false;
    return true;
  }
};