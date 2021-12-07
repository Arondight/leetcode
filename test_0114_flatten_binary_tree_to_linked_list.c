#include <stdbool.h>
#include <string.h>
#include "tree.h"
#include "test_assert.h"

extern void flatten(struct TreeNode * root);

bool testFlatten(void)
{
  const int a[] = { 1, 2, 5, 3, 4, 0, 6 };
  const int expect[] = { 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6 };
  struct TreeNode * root = NULL;
  int * result = (int *)malloc(sizeof(expect));
  bool retVal = true;

  memset(result, 0, sizeof(expect));
  treeFromArray(&root, a, 0, sizeof(a) / sizeof(int));
  flatten(root);
  arrayFromTree(result, root, 0);

  for (size_t i = 0; i < sizeof(expect) / sizeof(int); ++i) {
    retVal = ASSERT(expect[i] == result[i]) && retVal;
  }

  free(result);
  result = NULL;

  return retVal;
}
