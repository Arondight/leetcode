#include <stdbool.h>
#include "test_assert.h"

extern int fib(int n);

bool testFib(void)
{
  bool retVal = ASSERT(3 == fib(4)) &&
    ASSERT(21 == fib(8)) &&
    ASSERT(144 == fib(12)) &&
    ASSERT(987 == fib(16));

  return retVal;
}
