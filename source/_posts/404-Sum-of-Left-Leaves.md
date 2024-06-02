---
title: 404. Sum of Left Leaves
categories: Leetcode
date: 2024-05-24 11:15:08
tags:
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Binary Tree
---

[404. Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves/description/)

## Description

Given the `root` of a binary tree, return the sum of all left leaves.

A **leaf**  is a node with no children. A **left leaf**  is a leaf that is the left child of another node.

**Example 1:**
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/08/leftsum-tree.jpg" style="width: 277px; height: 302px;">

```bash
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
```

**Example 2:**

```bash
Input: root = [1]
Output: 0
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 1000]`.
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        if (!root) {
            return res;
        }
        if (root->left && !root->left->left && !root->left->right) {
            res += root->left->val;
        }
        res += sumOfLeftLeaves(root->left);
        res += sumOfLeftLeaves(root->right);
        return res;
    }
};
```
