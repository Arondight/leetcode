#include <stdbool.h>
#include "linked_list.h"
#include "test_assert.h"

extern bool isPalindrome(struct ListNode * head);

bool testIsPalindrome(void)
{
  const int a1[] = { 1, 2, 2, 1 };
  const int a2[] = { 1, 2 };
  struct ListNode * list1 = listFromArray(a1, sizeof(a1) / sizeof(int));
  struct ListNode * list2 = listFromArray(a2, sizeof(a2) / sizeof(int));
  bool retVal = true;

  retVal = ASSERT(true == isPalindrome(list1)) && retVal;
  retVal = ASSERT(false == isPalindrome(list2)) && retVal;

  freeList(list1);
  list1 = NULL;
  freeList(list2);
  list2 = NULL;

  return retVal;
}
