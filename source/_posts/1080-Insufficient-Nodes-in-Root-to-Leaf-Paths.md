---
title: 1080. Insufficient Nodes in Root to Leaf Paths
categories: Leetcode
date: 2024-07-05 23:47:57
tags:
    - Tree
    - Depth-First Search
    - Binary Tree
---

[1080. Insufficient Nodes in Root to Leaf Paths](https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/description/)

## Description

Given the `root` of a binary tree and an integer `limit`, delete all **insufficient nodes** in the tree simultaneously, and return the root of the resulting binary tree.

A node is **insufficient** if every root to **leaf** path intersecting this node has a sum strictly less than `limit`.

A **leaf** is a node with no children.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/06/05/insufficient-11.png" style="width: 500px; height: 207px;">

```bash
Input: root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1
Output: [1,2,3,4,null,null,7,8,9,null,14]
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/06/05/insufficient-3.png" style="width: 400px; height: 274px;">

```bash
Input: root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22
Output: [5,4,8,11,null,17,4,7,null,null,null,5]
```

**Example 3:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/06/11/screen-shot-2019-06-11-at-83301-pm.png" style="width: 250px; height: 199px;">

```bash
Input: root = [1,2,-3,-5,null,4,null], limit = -1
Output: [1,null,-3,4]
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 5000]`.
- `-10^5 <= Node.val <= 10^5`
- `-10^9 <= limit <= 10^9`

## Hints/Notes

- binary tree

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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (!root) {
            return root;
        }

        if (!root->left && !root->right) {
            if (root->val < limit) {
                return nullptr;
            }
            return root;
        }

        root->left = sufficientSubset(root->left, limit - root->val);
        root->right = sufficientSubset(root->right, limit - root->val);

        if (!root->left && !root->right) {
            return nullptr;
        }
        return root;
    }
};
```
