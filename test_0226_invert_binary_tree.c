#include <stdbool.h>
#include <string.h>
#include "tree.h"
#include "test_assert.h"

extern struct TreeNode * invertTree(struct TreeNode * root);

bool testInvertTree(void)
{
  const int a[] = { 4, 2, 7, 1, 3, 6, 9 };
  const int expect[] = { 4, 7 ,2 ,9, 6, 3, 1 };
  struct TreeNode * root = NULL, * new = NULL;
  int * result = (int *)malloc(sizeof(expect));
  bool retVal = true;

  memset(result, 0, sizeof(expect));
  treeFromArray(&root, a, 0, sizeof(a) / sizeof(int));
  new = invertTree(root);
  arrayFromTree(result, new, 0);

  for (size_t i = 0; i < sizeof(expect) / sizeof(int); ++i) {
    retVal = ASSERT(expect[i] == result[i]) && retVal;
  }

  freeTree(root);
  root = NULL;
  free(result);
  result = NULL;

  return retVal;
}
