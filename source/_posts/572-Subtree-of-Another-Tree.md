---
title: 572. Subtree of Another Tree
categories: Leetcode
date: 2024-06-06 12:08:48
tags:
    - Tree
    - Depth-First Search
    - String Matching
    - Binary Tree
    - Hash Function
---

[572. Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/description/)

## Description

Given the roots of two binary trees `root` and `subRoot`, return `true` if there is a subtree of `root` with the same structure and node values of `subRoot` and `false` otherwise.

A subtree of a binary tree `tree` is a tree that consists of a node in `tree` and all of this node's descendants. The tree `tree` could also be considered as a subtree of itself.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/04/28/subtree1-tree.jpg" style="width: 532px; height: 400px;">

```bash
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/04/28/subtree2-tree.jpg" style="width: 502px; height: 458px;">

```bash
Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
```

**Constraints:**

- The number of nodes in the `root` tree is in the range `[1, 2000]`.
- The number of nodes in the `subRoot` tree is in the range `[1, 1000]`.
- `-10^4 <= root.val <= 10^4`
- `-10^4 <= subRoot.val <= 10^4`

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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) {
            return true;
        }
        if (!root || !subRoot) {
            return false;
        }
        bool ans = false;
        if (root->val == subRoot->val) {
            ans = validate(root, subRoot);
        }
        if (ans) {
            return true;
        } else {
            return isSubtree(root->left, subRoot) ||
                   isSubtree(root->right, subRoot);
        }
    }

    bool validate(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) {
            return true;
        }
        if (!root || !subRoot) {
            return false;
        }
        if (root->val != subRoot->val) {
            return false;
        }
        return validate(root->left, subRoot->left) &&
               validate(root->right, subRoot->right);
    }
};
```
