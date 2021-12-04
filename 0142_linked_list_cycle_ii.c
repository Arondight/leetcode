/*
 * @lc app=leetcode.cn id=142 lang=c
 *
 * [142] 环形链表 II
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

struct ListNode * detectCycle(struct ListNode * head)
{
  struct ListNode * fast = head, * slow = head;

  while (fast) {
    slow = slow->next;

    if (!fast->next) {
      return NULL;
    }

    fast = fast->next->next;

    if (fast == slow) {
      break;
    }
  }

  if (!fast || !slow) {
    return NULL;
  }

  for (fast = head; fast != slow; fast = fast->next, slow = slow->next);

  return fast;
}

// @lc code=end
