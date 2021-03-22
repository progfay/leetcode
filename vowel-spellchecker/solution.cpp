#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
  {
    unordered_map<string, string> originalMap;
    unordered_map<string, int> lowerMap;
    unordered_map<string, int> maskedMap;
    vector<string> ans;

    for (int i = 0; i < wordlist.size(); i++)
    {
      originalMap[wordlist[i]] = "";
      string lowerStr = lower(wordlist[i]);
      if (!lowerMap.count(lowerStr))
        lowerMap[lowerStr] = i;

      string masked = masking(lowerStr);
      if (!maskedMap.count(masked))
        maskedMap[masked] = i;
    }

    for (auto s : queries)
    {
      if (originalMap.count(s))
      {
        ans.push_back(s);
        continue;
      }

      string lowerStr = lower(s);
      if (lowerMap.count(lowerStr))
      {
        ans.push_back(wordlist[lowerMap[lowerStr]]);
        continue;
      }

      string masked = masking(lowerStr);
      if (maskedMap.count(masked))
      {
        ans.push_back(wordlist[maskedMap[masked]]);
        continue;
      }

      ans.push_back("");
    }
    return ans;
  }

private:
  string lower(string str)
  {
    string lowerStr = "";
    for (auto c : str)
      lowerStr += tolower(c);

    return lowerStr;
  }

private:
  string masking(string str)
  {
    string masked = "";
    for (auto c : str)
      masked += (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') ? '?' : c;

    return masked;
  }
};