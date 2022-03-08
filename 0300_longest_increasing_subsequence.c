/*
 * @lc app=leetcode.cn id=300 lang=c
 *
 * [300] 最长递增子序列
 */

#include <stdio.h>
#include <stdlib.h>

// @lc code=start

int lengthOfLIS(const int * const nums, const int numsSize)
{
  int *dp = NULL;
  int res = 1;

  if (!(dp = (int *)malloc((numsSize + 1) * sizeof(int)))) {
    return 1;
  }

  for (int i = 0; i < numsSize; ++i) {
    dp[i] = 1;
  }

  for (int i = 0; i < numsSize; ++i) {
    for (int j = 0; j < i; ++j) {
      if (nums[i] > nums[j]) {
        if (dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
        }
      }
    }
  }

  for (int i = 0; i < numsSize; ++i) {
    if (dp[i] > res) {
      res = dp[i];
    }
  }

  return res;
}

// @lc code=end
