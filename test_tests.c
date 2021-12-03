#include <stddef.h>
#include "test.h"

const mapping_t tests[] = {
  {   21, testMergeTwoLists },
  {  141, testHasCycle },
};
const size_t testsSize = sizeof(tests) / sizeof(mapping_t);
