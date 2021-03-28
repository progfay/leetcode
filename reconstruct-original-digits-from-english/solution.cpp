#include <string>
#include <vector>

using namespace std;

class Solution
{

public:
  string originalDigits(string s)
  {
    vector<int> chars(26, 0);
    for (char c : s)
      chars[c - 'a']++;

    int num = 0;
    vector<int> count(10, 0);

    num = chars['z' - 'a'];
    count[0] = num;
    chars['z' - 'a'] -= num;
    chars['e' - 'a'] -= num;
    chars['r' - 'a'] -= num;
    chars['o' - 'a'] -= num;

    num = chars['x' - 'a'];
    count[6] = num;
    chars['s' - 'a'] -= num;
    chars['i' - 'a'] -= num;
    chars['x' - 'a'] -= num;

    num = chars['w' - 'a'];
    count[2] = num;
    chars['t' - 'a'] -= num;
    chars['w' - 'a'] -= num;
    chars['o' - 'a'] -= num;

    num = chars['s' - 'a'];
    count[7] = num;
    chars['s' - 'a'] -= num;
    chars['e' - 'a'] -= num;
    chars['v' - 'a'] -= num;
    chars['e' - 'a'] -= num;
    chars['n' - 'a'] -= num;

    num = chars['v' - 'a'];
    count[5] = num;
    chars['f' - 'a'] -= num;
    chars['i' - 'a'] -= num;
    chars['v' - 'a'] -= num;
    chars['e' - 'a'] -= num;

    num = chars['f' - 'a'];
    count[4] = num;
    chars['f' - 'a'] -= num;
    chars['o' - 'a'] -= num;
    chars['u' - 'a'] -= num;
    chars['r' - 'a'] -= num;

    num = chars['g' - 'a'];
    count[8] = num;
    chars['e' - 'a'] -= num;
    chars['i' - 'a'] -= num;
    chars['g' - 'a'] -= num;
    chars['h' - 'a'] -= num;
    chars['t' - 'a'] -= num;

    num = chars['h' - 'a'];
    count[3] = num;
    chars['t' - 'a'] -= num;
    chars['h' - 'a'] -= num;
    chars['r' - 'a'] -= num;
    chars['e' - 'a'] -= num;
    chars['e' - 'a'] -= num;

    num = chars['i' - 'a'];
    count[9] = num;
    chars['n' - 'a'] -= num;
    chars['i' - 'a'] -= num;
    chars['n' - 'a'] -= num;
    chars['e' - 'a'] -= num;

    num = chars['o' - 'a'];
    count[1] = num;
    chars['o' - 'a'] -= num;
    chars['n' - 'a'] -= num;
    chars['e' - 'a'] -= num;

    string ans = "";
    for (int i = 0; i < 10; i++)
      for (int j = 0; j < count[i]; j++)
        ans += to_string(i);

    return ans;
  }
};