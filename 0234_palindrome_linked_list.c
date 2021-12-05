/*
 * @lc app=leetcode.cn id=234 lang=c
 *
 * [234] 回文链表
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

bool isPalindrome(struct ListNode * head)
{
  struct ListNode * fast = head, * slow = head;
  struct ListNode * a = NULL, * b = NULL;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  if (fast) {
    slow = slow->next;
  }

  a = head;
  b = reverseList(slow);

  while (b) {
    if (a->val != b->val) {
      return false;
    }

    a = a->next;
    b = b->next;
  }

  return true;
}

// @lc code=end
