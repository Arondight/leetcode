#include <stddef.h>
#include "test.h"

const mapping_t tests[] = {
  { 1, testTwoSum },
  { 21, testMergeTwoLists },
};
const size_t testsSize = sizeof(tests) / sizeof(mapping_t);
