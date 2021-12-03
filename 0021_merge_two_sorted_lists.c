/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 */

#include <stdio.h>
#include "linked_list.h"

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode * mergeTwoLists(struct ListNode * list1, struct ListNode * list2) {
  struct ListNode dummpy = { 0, NULL };
  struct ListNode * p = &dummpy;
  struct ListNode * p1 = list1, * p2 = list2;

  while (p1 && p2) {
    if (p1->val > p2->val) {
      p->next = p2;
      p2 = p2->next;
    } else {
      p->next = p1;
      p1 = p1->next;
    }

    p = p->next;
  }

  if (p1) {
    p->next = p1;
  }

  if (p2) {
    p->next = p2;
  }

  return dummpy.next;
}

// @lc code=end
