#include <stdbool.h>
#include "linked_list.h"
#include "test_assert.h"

struct ListNode * detectCycle(struct ListNode * head);

bool testDetectCycle(void)
{
  const int a[] = { 3, 2, 0, -4 };
  struct ListNode * list = listFromArray(a, sizeof(a) / sizeof(int));
  struct ListNode * p = NULL;

  for (p = list; p->next; p = p->next);
  p->next = list->next;

  return ASSERT(list->next == detectCycle(list));
}
