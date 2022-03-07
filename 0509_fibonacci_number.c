/*
 * @lc app=leetcode.cn id=509 lang=c
 *
 * [509] 斐波那契数
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// @lc code=start

int fib(int n)
{
  int *dp = NULL;
  int res = 0;

  if (0 == n) {
    return 0;
  }

  if (!(dp = (int *)malloc((n + 1) * sizeof(int)))) {
    return 0;
  }

  memset(dp, 0, (n + 1) * sizeof(int));

  dp[0] = 0;
  dp[1] = 1;

  for (size_t i = 2; i < (size_t)(n + 1); ++i) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  res = dp[n];

  if (dp) {
    free(dp);
    dp = NULL;
  }

  return res;
}

// @lc code=end
