#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode * next;
};

inline static struct ListNode * listFromArray(const int *pArray, const size_t length)
{
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

inline static struct ListNode * reverseListBetween(struct ListNode * const a, struct ListNode * const b)
{
  struct ListNode * pre = NULL, * cur = a, * next = b;

  while (cur != b) {
    next = cur->next;
    cur->next = pre;
    pre = cur;
    cur = next;
  }

  return pre;
}

inline static struct ListNode * reverseList(struct ListNode * head)
{
  return reverseListBetween(head, NULL);
}

inline static struct ListNode * reverseListFirstN(struct ListNode * head, const size_t n)
{
  static struct ListNode * successor = NULL;

  if (1 == n) {
    successor = head->next;
    return head;
  }

  struct ListNode * last = reverseListFirstN(head->next, n - 1);

  head->next->next = head;
  head->next = successor;

  return last;
}

#endif /* __LINKED_LIST_H__ */
