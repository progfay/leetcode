#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  string simplifyPath(string path)
  {
    vector<string> s;
    string dir = "";
    for (int i = 0; i < path.length(); i++)
    {
      char c = path[i];
      if (c != '/')
      {
        dir += c;
        continue;
      }

      if (dir == "")
      {
      }
      else if (dir == ".")
      {
      }
      else if (dir == "..")
      {
        if (s.size() > 0)
          s.pop_back();
      }
      else
      {
        s.push_back(dir);
      }
      dir = "";
    };

    if (dir == "")
    {
    }
    else if (dir == ".")
    {
    }
    else if (dir == "..")
    {
      if (s.size() > 0)
        s.pop_back();
    }
    else
    {
      s.push_back(dir);
    }

    string simplifiedPath = "";
    for (string d : s)
    {
      simplifiedPath += "/" + d;
    }
    return simplifiedPath != "" ? simplifiedPath : "/";
  }
};