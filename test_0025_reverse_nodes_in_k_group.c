#include <stdbool.h>
#include "linked_list.h"
#include "test_assert.h"

extern struct ListNode * reverseKGroup(struct ListNode * head, int k);

bool testReverseKGroup(void)
{
  const int a[] = { 1, 2, 3, 4, 5 };
  const int expect1[] = { 2, 1, 4, 3, 5 };
  const int expect2[] = { 3, 2, 1, 4, 5 };
  struct ListNode * list1 = listFromArray(a, sizeof(a) / sizeof(int));
  struct ListNode * list2 = listFromArray(a, sizeof(a) / sizeof(int));
  struct ListNode * result1 = reverseKGroup(list1, 2);
  struct ListNode * result2 = reverseKGroup(list2, 3);
  struct ListNode * p = NULL;
  bool retVal = true;

  p = result1;
  for (size_t i = 0; i < sizeof(expect1) / sizeof(int); p = p->next, ++i) {
    retVal = ASSERT(expect1[i] == p->val) && retVal;
  }

  p = result2;
  for (size_t i = 0; i < sizeof(expect2) / sizeof(int); p = p->next, ++i) {
    retVal = ASSERT(expect2[i] == p->val) && retVal;
  }

  freeList(list1);  /* result1 */
  list1 = result1 = NULL;
  freeList(list2);  /* result2 */
  list1 = result2 = NULL;

  return retVal;
}
