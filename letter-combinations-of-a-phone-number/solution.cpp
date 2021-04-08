#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<string> letterCombinations(string digits)
  {
    vector<string> ans(0);
    if (digits == "")
      return ans;

    vector<string> letters = getLetters(digits.substr(0, 1));

    if (digits.length() == 1)
    {
      for (string letter : letters)
        ans.push_back(string(letter));
      return ans;
    }

    vector<string> followerList = letterCombinations(digits.substr(1));

    for (string letter : letters)
      for (string follower : followerList)
        ans.push_back(letter + follower);

    return ans;
  }

  vector<string> getLetters(string digit)
  {
    if (digit == "2")
      return {"a", "b", "c"};
    if (digit == "3")
      return {"d", "e", "f"};
    if (digit == "4")
      return {"g", "h", "i"};
    if (digit == "5")
      return {"j", "k", "l"};
    if (digit == "6")
      return {"m", "n", "o"};
    if (digit == "7")
      return {"p", "q", "r", "s"};
    if (digit == "8")
      return {"t", "u", "v"};
    if (digit == "9")
      return {"w", "x", "y", "z"};
    return {};
  }
};