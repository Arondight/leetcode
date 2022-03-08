#include "test_assert.h"
#include "tree.h"
#include <stdbool.h>
#include <string.h>

extern struct TreeNode *constructMaximumBinaryTree(int *nums, int numsSize);

bool testConstructMaximumBinaryTree(void)
{
  const int a[] = { 3, 2, 1, 6, -1, 5 };
  const int expect[] = { 6, 3, 5, 0, 2, -1, 0, 0, 1 };
  struct TreeNode *root = constructMaximumBinaryTree((int *)a, sizeof(a) / sizeof(int));
  int *result = (int *)malloc(sizeof(expect));
  bool retVal = true;

  memset(result, 0, sizeof(expect));
  arrayFromTree(result, root, 0);

  for (size_t i = 0; i < sizeof(expect) / sizeof(int); ++i) {
    retVal = ASSERT(expect[i] == result[i]) && retVal;
  }

  freeTree(root);
  root = NULL;
  free(result);
  result = NULL;

  return retVal;
}
