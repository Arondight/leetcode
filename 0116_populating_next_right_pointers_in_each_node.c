/*
 * @lc app=leetcode.cn id=116 lang=c
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

#include <stdio.h>

struct Node {
  int val;
  struct Node *left;
  struct Node *right;
  struct Node *next;
};

// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

static void connetNodes(struct Node *const n1, struct Node *const n2)
{
  if (!(n1 && n2)) {
    return;
  }

  n1->next = n2;

  connetNodes(n1->left, n1->right);
  connetNodes(n2->left, n2->right);
  connetNodes(n1->right, n2->left);
}

struct Node *connect(struct Node *root)
{
  if (!root) {
    return NULL;
  }

  connetNodes(root->left, root->right);
  return root;
}

// @lc code=end
