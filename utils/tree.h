#ifndef __TREE_H__
#define __TREE_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
  int val;
  struct TreeNode * left;
  struct TreeNode * right;
} TreeNode_t;

inline static int deepOfTree(const TreeNode_t * const root)
{
  int left = 0, right = 0;

  if (!root) {
    return 0;
  }

  left = deepOfTree(root->left);
  right = deepOfTree(root->right);

  return (left > right ? left : right) + 1;
}

inline static void freeTree(TreeNode_t * root)
{
  if (!root) {
    return;
  }

  if (root->left) {
    freeTree(root->left);
  }

  if (root->right) {
    freeTree(root->right);
  }

  free(root);
  root = NULL;
}

inline static void treeFromArray(TreeNode_t ** const root, const int * const pArray, const size_t index,
                                 const size_t length)
{
  if (index > length - 1) {
    return;
  }

  if (0 != pArray[index]) {
    *root = (TreeNode_t *)malloc(sizeof(TreeNode_t));

    (*root)->val = pArray[index];
    (*root)->left = NULL;
    (*root)->right = NULL;
  }

  treeFromArray(&(*root)->left, pArray, index * 2 + 1, length);
  treeFromArray(&(*root)->right, pArray, index * 2 + 2, length);
}

inline static void arrayFromTreeLevel(int * const pArray, TreeNode_t * const root, size_t * const index,
                                      const size_t level)
{
  if (!root) {
    return;
  }

  if (0 == level) {
    if (root->left) {
      pArray[(*index)++] = root->left->val;
    } else {
      if (root->right) {
        pArray[(*index)++] = 0;
      }
    }

    if (root->right) {
      pArray[(*index)++] = root->right->val;
    } else {
      if (root->left) {
        pArray[(*index)++] = 0;
      }
    }
  }

  arrayFromTreeLevel(pArray, root->left, index, level - 1);
  arrayFromTreeLevel(pArray, root->right, index, level - 1);
}

inline static void arrayFromTree(int * const pArray, TreeNode_t * const root, size_t index)
{
  int deep = 0;

  if (!root) {
    return;
  }

  deep = deepOfTree(root);
  pArray[index++] = root->val;

  for (size_t i = 0; i < (size_t)deep - 1; ++i) {
    arrayFromTreeLevel(pArray, root, &index, i);
  }
}

#endif /* __TREE_H__ */
