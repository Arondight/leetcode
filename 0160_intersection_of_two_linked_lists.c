/*
 * @lc app=leetcode.cn id=160 lang=c
 *
 * [160] 相交链表
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

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
  struct ListNode *p1 = headA, *p2 = headB;

  while (p1 != p2) {
    p1 = p1 ? p1->next : headB;
    p2 = p2 ? p2->next : headA;
  }

  return p1;
}

// @lc code=end
