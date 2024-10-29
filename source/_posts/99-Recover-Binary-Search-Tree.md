---
title: 99. Recover Binary Search Tree
categories: Leetcode
date: 2024-07-13 01:34:02
tags:
    - Tree
    - Depth-First Search
    - Binary Search Tree
    - Binary Tree
---

[99. Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree/description/)

## Description

You are given the `root` of a binary search tree (BST), where the values of **exactly** two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/10/28/recover1.jpg" style="width: 422px; height: 302px;">

```bash
Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/10/28/recover2.jpg" style="width: 581px; height: 302px;">

```bash
Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
```

**Constraints:**

- The number of nodes in the tree is in the range `[2, 1000]`.
- `-2^31 <= Node.val <= 2^31 - 1`

**Follow up:**  A solution using `O(n)` space is pretty straight-forward. Could you devise a constant `O(1)` space solution?

## Hints/Notes

- the two pointers can be set in the same round(together)

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
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev;

    void recoverTree(TreeNode* root) {
        if (!root)
            return;
        traverse(root);
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }

    void traverse(TreeNode* root) {
        if (!root) {
            return;
        }

        traverse(root->left);

        if (prev) {
            if (prev->val > root->val) {
                if (!first) {
                    first = prev;
                }
                second = root;
            }
        }
        prev = root;
        traverse(root->right);
    }
};
```
