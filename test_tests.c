#include <stddef.h>
#include "test.h"

const mapping_t tests[] = {
  {   19, testRemoveNthFromEnd },
  {   21, testMergeTwoLists },
  {   23, testMergeKLists },
  {   25, testReverseKGroup },
  {   92, testReverseBetween },
  {  141, testHasCycle },
  {  142, testDetectCycle },
  {  160, testGetIntersectionNode },
  {  876, testMiddleNode },
};
const size_t testsSize = sizeof(tests) / sizeof(mapping_t);
