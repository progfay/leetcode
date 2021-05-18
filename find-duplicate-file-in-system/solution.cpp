#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<vector<string>> findDuplicate(vector<string> &paths)
  {
    unordered_map<string, vector<string>> m;

    for (auto path : paths)
    {
      stringstream ss(path);
      string dir, s;
      ss >> dir;
      while (ss >> s)
      {
        auto i = s.find('(');
        string file = s.substr(0, i);
        string content = s.substr(i);
        m[content].push_back(dir + "/" + file);
      }
    }

    vector<vector<string>> ans;
    for (auto kv : m)
      if (kv.second.size() > 1)
        ans.push_back(kv.second);

    return ans;
  }
};
