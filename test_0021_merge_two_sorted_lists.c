#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test_assert.h"
#include "0021_merge_two_sorted_lists.h"

extern struct ListNode * mergeTwoLists(struct ListNode * list1, struct ListNode * list2);

static struct ListNode * fromArray(const int *pArray, const size_t length) {
  struct ListNode * list = NULL, * p = NULL, * pt = NULL;

  for (size_t i = 0; i < length; ++i) {
    pt = (struct ListNode *)malloc(sizeof(struct ListNode));
    pt->val = pArray[i];
    pt->next = NULL;

    if (!list) {
      p = list = pt;
    } else {
      p->next = pt;
      p = p->next;
    }
  }

  return list;
}

bool testMergeTwoLists(void)
{
  const int a1[] = { 1, 2, 4 };
  const int a2[] = { 1, 3, 4 };
  const int expect[] = { 1, 1, 2, 3, 4, 4 };
  struct ListNode * list1 = fromArray(a1, sizeof(a1) / sizeof(int));
  struct ListNode * list2 = fromArray(a2, sizeof(a2) / sizeof(int));
  const struct ListNode * const result = mergeTwoLists(list1, list2);
  const struct ListNode * p = result;
  bool retVal = true;

  for (size_t i = 0; i < sizeof(expect) / sizeof(int); ++i) {
    retVal = (ASSERT(expect[i] == p->val) || false) && retVal;
    p = p->next;
  }

  return retVal;
}
