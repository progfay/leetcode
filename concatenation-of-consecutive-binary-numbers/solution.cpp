class Solution
{
public:
  const int m = 1e9 + 7;

  int concatenatedBinary(int n)
  {
    int ans = 0;
    int digit = 1;
    for (int i = 1; i <= n; i++)
    {
      if (i >= (1 << digit))
      {
        digit++;
      }

      for (int j = 0; j < digit; j++)
      {
        ans <<= 1;
        ans %= m;
      }

      ans += i;
      ans %= m;
    }

    return ans;
  }
};
