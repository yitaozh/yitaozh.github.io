---
title: 270. Closest Binary Search Tree Value
categories: Leetcode
date: 2024-05-24 11:13:43
tags:
    - Binary Search
    - Tree
    - Depth-First Search
    - Binary Search Tree
    - Binary Tree
---

[270. Closest Binary Search Tree Value](https://leetcode.com/problems/closest-binary-search-tree-value/description/)

## Description

Given the `root` of a binary search tree and a `target` value, return the value in the BST that is closest to the `target`. If there are multiple answers, print the smallest.

**Example 1:**
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/12/closest1-1-tree.jpg" style="width: 292px; height: 302px;">

```bash
Input: root = [4,2,5,1,3], target = 3.714286
Output: 4
```

**Example 2:**

```bash
Input: root = [1], target = 4.428571
Output: 1
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `0 <= Node.val <= 10^9`
- `-10^9 <= target <= 10^9`

## Hints/Notes

- 2024/02/15
- bst
- premium

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
    int res = INT_MAX;

    int closestValue(TreeNode* root, double target) {
        traverse(root, target);
        return res;
    }

    void traverse(TreeNode* root, double target) {
        if (!root) {
            return;
        }
        if (root->val == target) {
            res = root->val;
        } else if (root->val > target) {
            if (abs(root->val - target) < abs(res - target)) {
                res = root->val;
            }
            traverse(root->left, target);
        } else {
            if (abs(root->val - target) <= abs(res - target)) {
                res = root->val;
            }
            traverse(root->right, target);
        }
    }
};
```
