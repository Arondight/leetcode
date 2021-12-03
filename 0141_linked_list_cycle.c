/*
 * @lc app=leetcode.cn id=141 lang=c
 *
 * [141] 环形链表
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
bool hasCycle(struct ListNode *head) {
  struct ListNode * fast = head, * slow = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if (fast == slow) {
      return true;
    }
  }

  return false;
}
// @lc code=end
