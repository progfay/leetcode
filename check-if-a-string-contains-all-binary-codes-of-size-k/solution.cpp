#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  bool hasAllCodes(string s, int k)
  {
    vector<bool> bits(1 << k, false);

    int v = 0;
    for (int i = 0; i < k; i++)
    {
      v <<= 1;
      v += s[i] == '1' ? 1 : 0;
    }
    bits[v] = true;

    int mask = (1 << (k - 1)) - 1;
    for (int i = k; i < s.length(); i++)
    {
      v &= mask;
      v <<= 1;
      v += s[i] == '1' ? 1 : 0;
      bits[v] = true;
    }

    for (bool found : bits)
    {
      if (!found)
        return false;
    }

    return true;
  }
};