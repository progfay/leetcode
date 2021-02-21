class Solution {
public:
    int brokenCalc(int X, int Y) {
      int shift = 0;
      while (X < Y)
      {
        X <<= 1;
        shift++;
      }

      int ans = shift;
      int diff = X - Y;
      for (int i = 0; i < shift; i++)
      {
        ans += diff % 2;
        diff >>= 1;
      }
      ans += diff;
      return ans;
    }
};