class Solution
{
public:
  int minOperations(int n)
  {
    return (n * n - n % 2) / 4;
  }
};