#include <bitset>

using namespace std;

class Solution
{
public:
  int countPrimes(int n)
  {
    bitset<5000000> bits(0);
    bits.flip();

    for (int i = 2; i * i < n; i++)
    {
      if (!bits.test(i))
        continue;

      for (int j = i * i; j < n; j += i)
        bits.set(j, false);
    }

    int count = 0;
    for (int i = 2; i < n; i++)
      if (bits.test(i))
        count++;

    return count;
  }
};