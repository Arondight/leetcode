#include <stddef.h>
#include "test.h"

const mapping_t tests[] = {
  {   21, testMergeTwoLists },
  {   23, testMergeKLists },
  {  141, testHasCycle },
  {  142, testDetectCycle },
  {  876, testMiddleNode },
};
const size_t testsSize = sizeof(tests) / sizeof(mapping_t);
