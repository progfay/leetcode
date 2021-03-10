#include <string>

using namespace std;

class Solution
{
public:
  string intToRoman(int num)
  {
    string thousands = string(num / 1000, 'M');
    num %= 1000;

    string hundreds = roman(num / 100, 'C', 'D', 'M');
    num %= 100;

    string tens = roman(num / 10, 'X', 'L', 'C');
    num %= 10;

    string ones = roman(num, 'I', 'V', 'X');

    return thousands + hundreds + tens + ones;
  }

private:
  inline string roman(int num, char one, char five, char ten)
  {
    switch (num)
    {
    case 0:
      return "";

    case 1:
      return string(1, one);

    case 2:
      return string(2, one);

    case 3:
      return string(3, one);

    case 4:
      return string(1, one) + string(1, five);

    case 5:
      return string(1, five);

    case 6:
      return string(1, five) + string(1, one);

    case 7:
      return string(1, five) + string(2, one);

    case 8:
      return string(1, five) + string(3, one);

    case 9:
      return string(1, one) + string(1, ten);
    }

    return "";
  }
};