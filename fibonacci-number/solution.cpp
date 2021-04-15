class Solution
{
private:
  int memo[31];

public:
  Solution() {
    for (int i = 0; i < sizeof(memo) / sizeof(int); i++)
    {
      memo[i] = -1;
    }
    memo[0] = 0;
    memo[1] = 1;
  }

public:
  int fib(int n)
  {
    return memo[n] != -1 ? memo[n] : fib(n - 1) + fib(n - 2);
  }
};
