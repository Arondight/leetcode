#include <stdbool.h>
#include "linked_list.h"
#include "test_assert.h"

extern struct ListNode * mergeTwoLists(struct ListNode * list1, struct ListNode * list2);

bool testMergeTwoLists(void)
{
  const int a1[] = { 1, 2, 4 };
  const int a2[] = { 1, 3, 4 };
  const int expect[] = { 1, 1, 2, 3, 4, 4 };
  struct ListNode * list1 = listFromArray(a1, sizeof(a1) / sizeof(int));
  struct ListNode * list2 = listFromArray(a2, sizeof(a2) / sizeof(int));
  const struct ListNode * const result = mergeTwoLists(list1, list2);
  const struct ListNode * p = result;
  bool retVal = true;

  for (size_t i = 0; i < sizeof(expect) / sizeof(int); ++i) {
    retVal = (ASSERT(expect[i] == p->val) || false) && retVal;
    p = p->next;
  }

  return retVal;
}
