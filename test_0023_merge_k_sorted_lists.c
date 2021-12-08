#include <stdbool.h>
#include "linked_list.h"
#include "test_assert.h"

extern struct ListNode * mergeKLists(struct ListNode ** lists, int listsSize);

bool testMergeKLists(void)
{
  const int * a[] = {
    (int []){ 1, 4, 5, 0 },
    (int []){ 1, 3, 4, 0 },
    (int []){ 2, 6, 0 },
    NULL
  };
  const int expect[] = { 1, 1, 2, 3, 4, 4, 5, 6 };
  struct ListNode ** lists = NULL;
  struct ListNode * result = NULL, * p = NULL;
  size_t listsSize = 0;
  size_t len = 0;
  bool retVal = true;

  for (size_t i = 0; a[i]; ++i) {
    for (len = 0; a[i][len]; ++len);
    lists = (struct ListNode **)realloc(lists, i * sizeof(struct ListNode *));
    lists[i] = listFromArray(a[i], len);
    ++listsSize;
  }

  result = mergeKLists(lists, (int)listsSize);
  p = result;

  for (size_t i = 0; i < sizeof(expect) / sizeof(int); ++i) {
    retVal = ASSERT(expect[i] == p->val) && retVal;
    p = p->next;
  }

  for (size_t i = 0; i < listsSize; ++i) {
    freeList(lists[i]);
    lists[i] = NULL;
  }

  free(lists);  /* result */
  lists = NULL;
  result = NULL;

  return retVal;
}
