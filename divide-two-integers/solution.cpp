#include <climits>

class Solution
{
public:
  int divide(int dividend, int divisor)
  {
    if (dividend == INT_MIN && divisor == -1)
      return INT_MAX;
    if (dividend == INT_MIN && divisor == 1)
      return INT_MIN;

    bool isNegative = (dividend <= 0) != (divisor < 0);

    if (dividend > 0)
    {
      dividend = 0 - dividend;
    }

    if (divisor > 0)
    {
      divisor = 0 - divisor;
    }

    int quotient = 0;
    while (dividend >= divisor)
    {
      int decrease = divisor;
      int q = 1;
      while (decrease > (INT_MIN >> 1) && decrease + decrease >= dividend)
      {
        decrease += decrease;
        q += q;
      }
      dividend -= decrease;
      quotient += q;
    }

    return isNegative ? 0 - quotient : quotient;
  }
};