---
title: 110. Balanced Binary Tree
categories: Leetcode
date: 2024-07-01 23:30:33
tags:
    - Tree
    - Depth-First Search
    - Binary Tree
---

[110. Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/description/)

## Description

Given a binary tree, determine if it is **height-balanced**.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/10/06/balance_1.jpg" style="width: 342px; height: 221px;">

```bash
Input: root = [3,9,20,null,null,15,7]
Output: true
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/10/06/balance_2.jpg" style="width: 452px; height: 301px;">

```bash
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
```

**Example 3:**

```bash
Input: root = []
Output: true
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 5000]`.
- `-10^4 <= Node.val <= 10^4`

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
    bool balanced = true;

    bool isBalanced(TreeNode* root) {
        traverse(root);
        return balanced;
    }

    int traverse(TreeNode* root) {
        if (!root || !balanced) {
            return 0;
        }

        int left = traverse(root->left);
        int right = traverse(root->right);

        if (abs(left - right) > 1) {
            balanced = false;
            return 0;
        }

        return max(left, right) + 1;
    }
};
```
