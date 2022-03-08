/*
 * @lc app=leetcode.cn id=92 lang=c
 *
 * [92] 反转链表 II
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

struct ListNode *reverseBetween(struct ListNode *head, int left, int right)
{
  if (1 == left) {
    return reverseListFirstN(head, right);
  }

  head->next = reverseBetween(head->next, left - 1, right - 1);
  return head;
}

// @lc code=end
