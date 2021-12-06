/*
 * @lc app=leetcode.cn id=226 lang=c
 *
 * [226] 翻转二叉树
 */

#include <stdio.h>
#include "tree.h"

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode * invertTree(struct TreeNode * root)
{
  struct TreeNode * temp = NULL;

  if (!root) {
    return NULL;
  }

  temp = root->left;
  root->left = root->right;
  root->right = temp;

  invertTree(root->left);
  invertTree(root->right);

  return root;
}

// @lc code=end
