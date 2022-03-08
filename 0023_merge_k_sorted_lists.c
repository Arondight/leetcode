/*
 * @lc app=leetcode.cn id=23 lang=c
 *
 * [23] 合并K个升序链表
 */

#include "linked_list.h"
#include <stdbool.h>

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
bool mergeKListsIsGreaterThan(const void *const a, const void *const b)
{
  return ((struct ListNode *)a)->val > ((struct ListNode *)b)->val;
}

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
  struct ListNode dummpy = { 0, NULL };
  struct ListNode *p = &dummpy;
  size_t end = 0;
  void *pq = PQCreate(listsSize, &end, sizeof(struct ListNode));

  for (size_t i = 0; i < (size_t)listsSize; ++i) {
    if (lists[i]) {
      PQInsert(pq, lists[i], &end, sizeof(struct ListNode), mergeKListsIsGreaterThan);
    }
  }

  while (end > 0) {
    struct ListNode *temp = PQDelete(pq, &end, sizeof(struct ListNode), mergeKListsIsGreaterThan);
    p->next = temp;

    if (temp->next) {
      PQInsert(pq, temp->next, &end, sizeof(struct ListNode), mergeKListsIsGreaterThan);
    }

    p = p->next;
  }

  return dummpy.next;
}

// @lc code=end
