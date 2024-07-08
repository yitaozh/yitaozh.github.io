---
title: 250. Count Univalue Subtrees
categories: Leetcode
date: 2024-07-01 23:34:03
tags:
    - Tree
    - Depth-First Search
    - Binary Tree
---

[250. Count Univalue Subtrees](https://leetcode.com/problems/count-univalue-subtrees/description/)

## Description

Given the `root` of a binary tree, return the number of **uni-value** subtrees.

A **uni-value subtree**  means all nodes of the subtree have the same value.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/08/21/unival_e1.jpg" style="width: 450px; height: 258px;">

```bash
Input: root = [5,1,5,5,5,null,5]
Output: 4
```

**Example 2:**

```bash
Input: root = []
Output: 0
```

**Example 3:**

```bash
Input: root = [5,5,5,5,5,null,5]
Output: 6
```

**Constraints:**

- The number of the node in the tree will be in the range `[0, 1000]`.
- `-1000 <= Node.val <= 1000`

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
    int res = 0;

    int countUnivalSubtrees(TreeNode* root) {
        traverse(root);
        return res;
    }

    int traverse(TreeNode* root) {
        if (!root) {
            return INT_MIN;
        }

        int left = root->left ? traverse(root->left) : root->val;
        int right = root->right ? traverse(root->right) : root->val;

        if (left == root->val && right == root->val) {
            res++;
            return root->val;
        } else {
            return INT_MIN;
        }
    }
};
```
