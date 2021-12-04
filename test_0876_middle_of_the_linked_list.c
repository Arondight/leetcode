#include <stdbool.h>
#include "linked_list.h"
#include "test_assert.h"

struct ListNode * middleNode(struct ListNode * head);

bool testMiddleNode(void)
{
  const int a1[] = { 1, 2, 3, 4, 5 };
  const int a2[] = { 1, 2, 3, 4, 5, 6 };
  struct ListNode * list1 = listFromArray(a1, sizeof(a1) / sizeof(int));
  struct ListNode * list2 = listFromArray(a2, sizeof(a2) / sizeof(int));
  struct ListNode * p = NULL;
  bool retVal = true;

  p = list1;
  for (size_t i = 0; i < 3 - 1; p = p->next, ++i);
  retVal = ASSERT(p == middleNode(list1)) && retVal;

  p = list2;
  for (size_t i = 0; i < 4 - 1; p = p->next, ++i);
  retVal = ASSERT(p == middleNode(list2)) && retVal;

  return retVal;
}
