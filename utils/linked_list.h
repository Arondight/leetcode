#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
  int val;
  struct ListNode *next;
} ListNode_t;

inline static void freeList(ListNode_t *head)
{
  ListNode_t *cur = NULL;

  while (head) {
    cur = head;
    head = head->next;
    free(cur);
    cur = NULL;
  }
}

inline static ListNode_t *listFromArray(const int *pArray, const size_t length)
{
  ListNode_t *list = NULL, *p = NULL, *pt = NULL;

  for (size_t i = 0; i < length; ++i) {
    pt = (ListNode_t *)malloc(sizeof(ListNode_t));
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

inline static ListNode_t *reverseListBetween(ListNode_t *const a, ListNode_t *const b)
{
  ListNode_t *pre = NULL, *cur = a, *next = b;

  while (cur != b) {
    next = cur->next;
    cur->next = pre;
    pre = cur;
    cur = next;
  }

  return pre;
}

inline static ListNode_t *reverseList(ListNode_t *head)
{
  return reverseListBetween(head, NULL);
}

inline static ListNode_t *reverseListFirstN(ListNode_t *head, const size_t n)
{
  static ListNode_t *successor = NULL;

  if (1 == n) {
    successor = head->next;
    return head;
  }

  ListNode_t *last = reverseListFirstN(head->next, n - 1);

  head->next->next = head;
  head->next = successor;

  return last;
}

#endif /* __LINKED_LIST_H__ */
