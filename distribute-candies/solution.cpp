#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
      ios_base::sync_with_stdio(0), cin.tie(0);

      int limit = candyType.size() >> 1;
      bitset<200001> bits(0);
      for (int type : candyType)
      {
        bits.set(type + 1e5);
      }

      int count = bits.count();

      return count > limit ? limit : count;
    }
};