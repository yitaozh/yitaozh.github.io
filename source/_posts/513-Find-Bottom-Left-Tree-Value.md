---
title: 513. Find Bottom Left Tree Value
categories: Leetcode
date: 2024-06-03 01:04:21
tags:
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Binary Tree
---

[513. Find Bottom Left Tree Value](https://leetcode.com/problems/find-bottom-left-tree-value/description/)

## Description

Given the `root` of a binary tree, return the leftmost value in the last row of the tree.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/12/14/tree1.jpg" style="width: 302px; height: 182px;">

```bash
Input: root = [2,1,3]
Output: 1
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/12/14/tree2.jpg" style="width: 432px; height: 421px;">

```bash
Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-2^31 <= Node.val <= 2^31 - 1`

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
    int maxDepth = 0, depth = 0, res = 0;

    int findBottomLeftValue(TreeNode* root) {
        traverse(root);
        return res;
    }

    void traverse(TreeNode* root) {
        if (!root) {
            return;
        }
        depth++;
        if (depth > maxDepth) {
            maxDepth = depth;
            res = root->val;
        }
        traverse(root->left);
        traverse(root->right);
        depth--;
    }
};
```
