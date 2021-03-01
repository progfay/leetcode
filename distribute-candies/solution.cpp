#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
      return min(set<int>(candyType.begin(), candyType.end()).size(), candyType.size() / 2);
    }
};