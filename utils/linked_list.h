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

#endif /* __LINKED_LIST_H__ */
