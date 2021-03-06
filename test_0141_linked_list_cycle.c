#include "linked_list.h"
#include "test_assert.h"
#include <stdbool.h>

extern bool hasCycle(struct ListNode *head);

bool testHasCycle(void)
{
  const int a[] = { 3, 2, 0, -4 };
  struct ListNode *list = listFromArray(a, sizeof(a) / sizeof(int));
  struct ListNode *p = NULL;
  bool retVal = ASSERT(false == hasCycle(list));

  for (p = list; p->next; p = p->next)
    ;
  p->next = list->next;

  retVal = ASSERT(true == hasCycle(list)) && retVal;

  p->next = NULL;
  freeList(list);
  list = NULL;

  return retVal;
}
