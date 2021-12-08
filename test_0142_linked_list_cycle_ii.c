#include <stdbool.h>
#include "linked_list.h"
#include "test_assert.h"

extern struct ListNode * detectCycle(struct ListNode * head);

bool testDetectCycle(void)
{
  const int a[] = { 3, 2, 0, -4 };
  struct ListNode * list = listFromArray(a, sizeof(a) / sizeof(int));
  struct ListNode * p = NULL;
  bool retVal = true;

  for (p = list; p->next; p = p->next);
  p->next = list->next;

  retVal = ASSERT(list->next == detectCycle(list)) && retVal;

  p->next = NULL;
  freeList(list);
  list = NULL;

  return retVal;
}
