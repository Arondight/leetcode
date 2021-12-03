#include <stdbool.h>
#include <stdio.h>
#include "test_assert.h"

extern int * twoSum(int * nums, int numsSize, int target, int * returnSize);

bool testTwoSum(void)
{
  int nums[] = { 2, 7, 11, 15 };
  int returnSize = 0;
  const int target = 9;
  const size_t numsSize = sizeof(nums) / sizeof(int);
  const int * const result = twoSum(nums, numsSize, target, &returnSize);

  return ASSERT(NULL != result) &&
         ASSERT(2 == returnSize) &&
         ASSERT(0 == result[0] && 1 == result[1]);
}
