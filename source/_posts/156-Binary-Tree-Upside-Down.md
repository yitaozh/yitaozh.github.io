---
title: 156. Binary Tree Upside Down
categories: Leetcode
date: 2025-03-17 00:37:56
tags:
    - Tree
    - Depth-First Search
    - Binary Tree
---

[156. Binary Tree Upside Down](https://leetcode.com/problems/binary-tree-upside-down/description/?envType=company&envId=linkedin&favoriteSlug=linkedin-three-months)

## Description

Given the `root` of a binary tree, turn the tree upside down and return the new root.

You can turn a binary tree upside down with the following steps:

- The original left child becomes the new root.
- The original root becomes the new right child.
- The original right child becomes the new left child.

<img alt="" src="https://assets.leetcode.com/uploads/2020/08/29/main.jpg" style="width: 600px; height: 95px;">

The mentioned steps are done level by level. It is **guaranteed**  that every right node has a sibling (a left node with the same parent) and has no children.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/08/29/updown.jpg" style="width: 800px; height: 161px;">

```bash
Input: root = [1,2,3,4,5]
Output: [4,5,2,null,null,3,1]
```

**Example 2:**

```bash
Input: root = []
Output: []
```

**Example 3:**

```bash
Input: root = [1]
Output: [1]
```

**Constraints:**

- The number of nodes in the tree will be in the range `[0, 10]`.
- `1 <= Node.val <= 10`
- Every right node in the tree has a sibling (a left node that shares the same parent).
- Every right node in the tree has no children.

## Hints/Notes

- 2025/02/11 Q3
- binary tree
- No solution from 0x3F or Leetcode

## Solution

Language: **C++**

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        if (!root->left) {
            return root;
        }
        return helper(root->left, root, root->right);
    }

    TreeNode* helper(TreeNode* left, TreeNode* parent, TreeNode* right) {
        TreeNode* newHead = left;
        if (left->left) {
            newHead = helper(left->left, left, left->right);
        }
        parent->left = nullptr;
        parent->right = nullptr;
        left->left = right;
        left->right = parent;
        return newHead;
    }
};
```
