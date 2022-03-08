#include <stdbool.h>
#include "test_assert.h"

extern int lengthOfLIS(const int * const nums, const int numsSize);

bool testLengthOfLIS(void)
{
  const int nums[] = { 10, 9, 2, 5, 3, 7, 101, 18 };
  const bool retVal = ASSERT(4 == lengthOfLIS(nums, sizeof(nums) / sizeof(int)));

  return retVal;
}
