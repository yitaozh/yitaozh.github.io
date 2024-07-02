---
title: 333. Largest BST Subtree
categories: Leetcode
date: 2024-07-01 23:35:27
tags:
    - Dynamic Programming
    - Tree
    - Depth-First Search
    - Binary Search Tree
    - Binary Tree
---

[333. Largest BST Subtree](https://leetcode.com/problems/largest-bst-subtree/description/)

## Description

Given the root of a binary tree, find the largest subtree, which is also a Binary Search Tree (BST), where the largest means subtree has the largest number of nodes.

A **Binary Search Tree (BST)**  is a tree in which all the nodes follow the below-mentioned properties:

- The left subtree values are less than the value of their parent (root) node's value.
- The right subtree values are greater than the value of their parent (root) node's value.

**Note:**  A subtree must include all of its descendants.

**Example 1:**

**<img alt="" src="https://assets.leetcode.com/uploads/2020/10/17/tmp.jpg" style="width: 571px; height: 302px;">**

```bash
Input: root = [10,5,15,1,8,null,7]
Output: 3
Explanation: The Largest BST Subtree in this case is the highlighted one. The return value is the subtree's size, which is 3.
```

**Example 2:**

```bash
Input: root = [4,2,7,2,3,5,null,2,null,null,null,null,null,1]
Output: 2
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-10^4 <= Node.val <= 10^4`

**Follow up:**  Can you figure out ways to solve it with `O(n)` time complexity?

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

    int largestBSTSubtree(TreeNode* root) {
        traverse(root);
        return res;
    }

    // the return value: number of nodes, min, max
    vector<int> traverse(TreeNode* root) {
        if (!root) {
            return {0, INT_MAX, INT_MIN};
        }

        int valid = true;

        int minVal = root->val, maxVal = root->val, cur = 1;
        if (root->left) {
            vector<int> left = traverse(root->left);
            if (root->val <= left[2]) {
                valid = false;
            }
            minVal = left[1];
            cur += left[0];
        }

        if (root->right) {
            vector<int> right = traverse(root->right);
            if (root->val >= right[1]) {
                valid = false;
            }
            maxVal = right[2];
            cur += right[0];
        }

        if (valid) {
            res = max(res, cur);
            return {cur, minVal, maxVal};
        } else {
            return {0, INT_MIN, INT_MAX};
        }
    }
};
```
