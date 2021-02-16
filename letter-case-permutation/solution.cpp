#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<string> letterCasePermutation(string S)
  {
    int count = 0;
    for (auto c : S)
    {
      if ('A' <= c && c <= 'z')
      {
        count++;
      }
    }

    transform(S.begin(), S.end(), S.begin(), ::tolower);
    int length = 1 << count;
    vector<string> ans(length);
    for (int i = 0; i < length; i++)
    {
      ans.at(i) = calculate(S, i);
    }

    return ans;
  }

private:
  string calculate(string s, int index)
  {
    string result;
    for (auto c : s)
    {
      if ('a' <= c && c <= 'z')
      {
        c -= ('a' - 'A') * (index % 2);
        index >>= 1;
      }
      result += c;
    }

    return result;
  }
};