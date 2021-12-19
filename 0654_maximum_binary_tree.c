/*
 * @lc app=leetcode.cn id=654 lang=c
 *
 * [654] 最大二叉树
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

#include <limits.h>

struct TreeNode * const constructMaximumBinaryTreeHelper(int * const nums, const int start, const int end)
{
  struct TreeNode * root = NULL;
  int max = INT_MIN;
  int index = 0;

  if (start > end) {
    return NULL;
  }

  for (int i = start; i < end + 1; ++i) {
    if (nums[i] > max) {
      max = nums[i];
      index = i;
    }
  }

  root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  root->val = max;
  root->left = constructMaximumBinaryTreeHelper(nums, start, index - 1);
  root->right = constructMaximumBinaryTreeHelper(nums, index + 1, end);

  return root;
}

struct TreeNode * constructMaximumBinaryTree(int * nums, int numsSize)
{
  return constructMaximumBinaryTreeHelper(nums, 0, numsSize - 1);
}

// @lc code=end
