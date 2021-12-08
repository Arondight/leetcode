#include <stdbool.h>
#include "linked_list.h"
#include "test_assert.h"

extern struct ListNode * getIntersectionNode(struct ListNode * headA, struct ListNode * headB);

bool testGetIntersectionNode(void)
{
  const int c[] = { 8, 4, 5 };
  const int a1[] = { 4, 1 };
  const int a2[] = { 5, 6, 1 };
  const int expect = 8;
  struct ListNode * listc = listFromArray(c, sizeof(c) / sizeof(int));
  struct ListNode * list1 = listFromArray(a1, sizeof(a1) / sizeof(int));
  struct ListNode * list2 = listFromArray(a2, sizeof(a2) / sizeof(int));
  struct ListNode * p = NULL;
  bool retVal = true;

  retVal = ASSERT(NULL == getIntersectionNode(list1, list2)) && retVal;

  for (p = list1; p->next; p = p->next);
  p->next = listc;
  for (p = list2; p->next; p = p->next);
  p->next = listc;

  retVal = ASSERT(expect == getIntersectionNode(list1, list2)->val) && retVal;

  for (p = list1; listc != p->next; p = p->next);
  p->next = NULL;
  for (p = list2; listc != p->next; p = p->next);
  p->next = NULL;

  freeList(listc);
  listc = NULL;
  freeList(list1);
  list1 = NULL;
  freeList(list2);
  list2 = NULL;

  return retVal;
}
