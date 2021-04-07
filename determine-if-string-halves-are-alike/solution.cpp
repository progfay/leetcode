#include <string>

using namespace std;

class Solution
{
public:
  bool halvesAreAlike(string s)
  {
    int length = s.length();
    int left = 0, right = 0;

    for (int i = 0; i < length / 2; i++)
      if (isVowel(s[i]))
        left++;

    for (int i = length / 2; i < length; i++)
      if (isVowel(s[i]))
        right++;

    return left == right;
  }

private:
  inline bool isVowel(char c)
  {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
  }
};