/*
 * @lc app=leetcode.cn id=114 lang=c
 *
 * [114] 二叉树展开为链表
 */

#include "tree.h"
#include <stdio.h>

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void flatten(struct TreeNode *root)
{
  struct TreeNode *left = NULL, *right = NULL, *p = NULL;

  if (!root) {
    return;
  }

  flatten(root->left);
  flatten(root->right);

  left = root->left;
  right = root->right;
  root->left = NULL;
  root->right = left;

  for (p = root; p->right; p = p->right)
    ;
  p->right = right;
}

// @lc code=end
