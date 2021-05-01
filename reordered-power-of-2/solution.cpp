#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  bool reorderedPowerOf2(int N)
  {
    auto str = to_string(N);
    vector<int> counts(10, 0);
    for (auto c : str)
      counts[c - '0']++;

    string id = "";
    for (auto c : counts)
      id += to_string(c);

    for (auto allow : allowList)
      if (id == allow)
        return true;
    return false;
  }

private:
  vector<string> allowList = {
      "0100000000",
      "0010000000",
      "0000100000",
      "0000000010",
      "0100001000",
      "0011000000",
      "0000101000",
      "0110000010",
      "0010011000",
      "0110010000",
      "1110100000",
      "1010100010",
      "1000101001",
      "0110000011",
      "0101101010",
      "0011001110",
      "0001022000",
      "1211000100",
      "0120201000",
      "0020110020",
      "1100111110",
      "1120010101",
      "1101300001",
      "1001001040",
      "0210002300",
      "0013220000",
      "1100102120",
      "0221100210",
      "0011222010",
      "1111011111",
  };
};
