class Solution
{
public:
  int minOperations(int n)
  {
    int k = n / 2;
    return k * (k + (n % 2));
  }
};