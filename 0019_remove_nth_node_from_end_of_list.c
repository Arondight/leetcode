/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第 N 个结点
 */

#include "linked_list.h"

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode * removeNthFromEnd(struct ListNode * head, int n)
{
  struct ListNode dummpy = { 0, head };
  struct ListNode * p1 = &dummpy, * p2 = &dummpy;
  struct ListNode * temp = NULL;

  for (size_t i = 0; i < (size_t)n + 1; ++i) {
    p1 = p1->next;
  }

  while (p1) {
    p1 = p1->next;
    p2 = p2->next;
  }

  temp = p2->next;
  p2->next = p2->next->next;
  free(temp);

  return dummpy.next;
}

// @lc code=end
