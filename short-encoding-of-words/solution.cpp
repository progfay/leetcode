#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int minimumLengthEncoding(vector<string> &words)
  {
    ios_base::sync_with_stdio(0), cin.tie(0);

    for (int i = 0; i < words.size(); i++)
    {
      reverse(words[i].begin(), words[i].end());
    }

    sort(words.begin(), words.end(), std::greater<string>{});

    string before = "";
    int ans = 0;

    for (string word : words)
    {
      if (word.length() > before.length())
      {
        before = word;
        ans += word.length() + 1;
        continue;
      }

      for (int i = 0; i < word.length(); i++)
      {
        if (word[i] != before[i])
        {
          before = word;
          ans += word.length() + 1;
          break;
        }
      }
    }

    return ans;
  }
};