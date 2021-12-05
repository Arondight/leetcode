#include <stdbool.h>
#include "linked_list.h"
#include "test_assert.h"

struct ListNode * removeNthFromEnd(struct ListNode * head, int n);

bool testRemoveNthFromEnd(void)
{
  const int a1[] = { 1, 2, 3, 4, 5 };
  const int a2[] = { 1 };
  const int a1Expect[] = { 1, 2, 3, 5 };
  struct ListNode * list1 = listFromArray(a1, sizeof(a1) / sizeof(int));
  struct ListNode * list2 = listFromArray(a2, sizeof(a2) / sizeof(int));
  struct ListNode * result = removeNthFromEnd(list1, 2);
  struct ListNode * p = result;
  bool retVal = true;

  for (size_t i = 0; i < sizeof(a1Expect) / sizeof(int); p = p->next, ++i) {
    retVal = ASSERT(a1Expect[i] == p->val) && retVal;
  }

  retVal = ASSERT(NULL == removeNthFromEnd(list2, 1)) && retVal;

  return retVal;
}
