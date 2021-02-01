#include <stdint.h>

class Solution
{
public:
  const int humming[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};

public:
  int hammingWeight(uint32_t n)
  {
    return humming[(n >> 0) & 0xF] + humming[(n >> 4) & 0xF] + humming[(n >> 8) & 0xF] + humming[(n >> 12) & 0xF] + humming[(n >> 16) & 0xF] + humming[(n >> 20) & 0xF] + humming[(n >> 24) & 0xF] + humming[(n >> 28) & 0xF];
  }
};