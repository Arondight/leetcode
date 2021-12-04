/*
 * @lc app=leetcode.cn id=23 lang=c
 *
 * [23] 合并K个升序链表
 */

#include <stdbool.h>
#include "linked_list.h"

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include "priority_queue.h"

/* A min heap */
bool isGreaterThan(const void * const a, const void * const b)
{
  return ((struct ListNode *)a)->val > ((struct ListNode *)b)->val;
}

struct ListNode * mergeKLists(struct ListNode ** lists, int listsSize)
{
  struct ListNode dummpy = { 0, NULL };
  struct ListNode * p = &dummpy;
  void * pq = PQCreate(listsSize, sizeof(struct ListNode));
  size_t end = 0;

  for (size_t i = 0; i < (size_t)listsSize; ++i) {
    if (lists[i]) {
      PQInsert(pq, lists[i], &end, sizeof(struct ListNode), isGreaterThan);
    }
  }

  while (end > 0)  {
    struct ListNode * temp = PQDelete(pq, &end, sizeof(struct ListNode), isGreaterThan);
    p->next = temp;

    if (temp->next) {
      PQInsert(pq, temp->next, &end, sizeof(struct ListNode), isGreaterThan);
    }

    p = p->next;
  }

  return dummpy.next;
}

// @lc code=end
