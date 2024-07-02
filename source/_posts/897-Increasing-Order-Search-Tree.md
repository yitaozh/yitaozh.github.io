---
title: 897. Increasing Order Search Tree
categories: Leetcode
date: 2024-07-01 23:23:51
tags:
    - Stack
    - Tree
    - Depth-First Search
    - Binary Search Tree
    - Binary Tree
---

[897. Increasing Order Search Tree](https://leetcode.com/problems/increasing-order-search-tree/description/)

## Description

Given the `root` of a binary search tree, rearrange the tree in **in-order**  so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/11/17/ex1.jpg" style="width: 600px; height: 350px;">

```bash
Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/11/17/ex2.jpg" style="width: 300px; height: 114px;">

```bash
Input: root = [5,1,7]
Output: [1,null,5,null,7]
```

**Constraints:**

- The number of nodes in the given tree will be in the range `[1, 100]`.
- `0 <= Node.val <= 1000`

## Hints/Notes

- N/A

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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* tail = nullptr;

    TreeNode* increasingBST(TreeNode* root) {
        if (!root)
            return root;

        TreeNode* newHead = root;

        if (root->left) {
            newHead = increasingBST(root->left);
            root->left = nullptr;
        }

        if (tail)
            tail->right = root;
        tail = root;
        increasingBST(root->right);
        return newHead;
    }
};
```
