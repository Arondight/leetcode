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

struct ListNode * reverseN(struct ListNode * head, const size_t n)
{
  static struct ListNode * successor = NULL;

  if (1 == n) {
    successor = head->next;
    return head;
  }

  struct ListNode * last = reverseN(head->next, n - 1);

  head->next->next = head;
  head->next = successor;

  return last;
}

struct ListNode * reverseBetween(struct ListNode * head, int left, int right)
{
  if (1 == left) {
    return reverseN(head, right);
  }

  head->next = reverseBetween(head->next, left - 1, right - 1);
  return head;
}

// @lc code=end
