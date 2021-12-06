#include <stdbool.h>
#include "linked_list.h"
#include "test_assert.h"

extern struct ListNode * reverseBetween(struct ListNode * head, int left, int right);

bool testReverseBetween(void)
{
  const int a[] = { 1, 2, 3, 4, 5 };
  const int expect[] = { 1, 4, 3, 2, 5 };
  struct ListNode * list = listFromArray(a, sizeof(a) / sizeof(int));
  struct ListNode * result = reverseBetween(list, 2, 4);
  struct ListNode * p = result;
  bool retVal = true;

  for (size_t i = 0; i < sizeof(expect) / sizeof(int); p = p->next, ++i) {
    retVal = ASSERT(expect[i] == p->val) && retVal;
  }

  return retVal;
}
