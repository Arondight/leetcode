/*
 * @lc app=leetcode.cn id=25 lang=c
 *
 * [25] K 个一组翻转链表
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

struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
  struct ListNode *a = head, *b = head, *new = NULL;

  if (!head) {
    return NULL;
  }

  for (size_t i = 0; i < (size_t)k; ++i) {
    if (!b) {
      return head;
    }

    b = b->next;
  }

  new = reverseListBetween(a, b);
  a->next = reverseKGroup(b, k);
  return new;
}

// @lc code=end
