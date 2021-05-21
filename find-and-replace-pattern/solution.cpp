#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
  vector<string> findAndReplacePattern(vector<string> &words, string pattern)
  {
    string p = normalize(pattern);
    vector<string> ans(0);

    for (auto word : words)
      if (normalize(word) == p)
        ans.push_back(word);

    return ans;
  }

private:
  string normalize(string word)
  {
    map<char, char> m;
    string normalized(' ', word.length());
    int cursor = 0;
    for (int i = 0; i < word.length(); i++)
    {
      auto c = word[i];
      if (m.count(c) == 0)
        m[c] = 'a' + cursor++;
      normalized[i] = m[c];
    }

    return normalized;
  }
};