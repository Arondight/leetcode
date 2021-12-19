#include <stddef.h>
#include "test.h"

const test_t tests[] = {
  {   19, testRemoveNthFromEnd },
  {   21, testMergeTwoLists },
  {   23, testMergeKLists },
  {   25, testReverseKGroup },
  {   92, testReverseBetween },
  {  114, testFlatten },
  {  116, testConnect },
  {  141, testHasCycle },
  {  142, testDetectCycle },
  {  160, testGetIntersectionNode },
  {  226, testInvertTree },
  {  234, testIsPalindrome },
  {  654, testConstructMaximumBinaryTree },
  {  876, testMiddleNode },
};
const size_t testsSize = sizeof(tests) / sizeof(test_t);
