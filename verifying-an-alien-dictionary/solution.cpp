#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
  int dict[26];

public:
  bool isAlienSorted(vector<string> &words, string order)
  {
    for (int i = 0; i < 26; i++)
      dict[order[i] - 'a'] = i;

    for (int i = 1; i < words.size(); i++)
      if (!greater(words[i - 1], words[i]))
        return false;

    return true;
  }

private:
  bool greater(string A, string B)
  {
    int cursor = 0;
    while (true)
    {
      if (A.size() == cursor)
        return B.size() >= cursor;

      if (B.size() == cursor)
        return false;

      int a = dict[A[cursor] - 'a'], b = dict[B[cursor] - 'a'];
      if (a == b)
      {
        cursor++;
        continue;
      }

      return a < b;
    }
  }
};