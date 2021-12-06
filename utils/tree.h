#ifndef __TREE_H__
#define __TREE_H__

#include <stdio.h>
#include <stdlib.h>
#include "utstack.h"
#include "linked_list.h"

typedef struct TreeNode {
  int val;
  struct TreeNode * left;
  struct TreeNode * right;
} TreeNode_t;

typedef struct element {
  TreeNode_t * node;
  struct element * next;
} element_t;

inline static void treeFromArray(TreeNode_t ** root, const int * const pArray, const size_t index,
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

inline static void arrayFromTree(int * pArray, TreeNode_t * root, size_t index)
{
  element_t * stack = NULL, * temp = NULL, * el = NULL;

  if(!root) {
    return;
  }

  el = (element_t *)malloc(sizeof(element_t));
  el->node = root;
  pArray[index++] = el->node->val;
  STACK_PUSH(stack, el);

  while (!STACK_EMPTY(stack)) {
    STACK_POP(stack, temp);

    if (temp->node->left) {
      el = (element_t *)malloc(sizeof(element_t));
      el->node = temp->node->left;
      pArray[index++] = el->node->val;
      STACK_PUSH(stack, el);
    } else {
      if (temp->node->right) {
        pArray[index++] = 0;
      }
    }

    if (temp->node->right) {
      el = (element_t *)malloc(sizeof(element_t));
      el->node = temp->node->right;
      pArray[index++] = el->node->val;
      STACK_PUSH(stack, el);
    } else {
      if (temp->node->left) {
        pArray[index++] = 0;
      }
    }

    free(temp);
    temp = NULL;
  }
}

#endif /* __TREE_H__ */
