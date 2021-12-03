#include <stdbool.h>
#include "linked_list.h"
#include "test_assert.h"

extern bool hasCycle(struct ListNode *head);

bool testHasCycle(void)
{
  const int a[] = { 3, 2, 0, -4 };
  struct ListNode * list = listFromArray(a, sizeof(a) / sizeof(int));
  struct ListNode * p = NULL;
  bool retVal = ASSERT(false == hasCycle(list));

  for (p = list; p->next; p = p->next);
  p->next = list->next;

  return ASSERT(true == hasCycle(list)) && retVal;
}
