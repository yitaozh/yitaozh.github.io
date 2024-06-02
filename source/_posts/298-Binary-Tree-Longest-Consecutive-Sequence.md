---
title: 298. Binary Tree Longest Consecutive Sequence
categories: Leetcode
date: 2024-04-03 15:58:53
tags:
    - Tree
    - Depth-First Search
    - Binary Tree
---

[298. Binary Tree Longest Consecutive Sequence](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/description/)

## Description

Given the `root` of a binary tree, return the length of the longest **consecutive sequence path** .

A **consecutive sequence path**  is a path where the values **increase by one**  along the path.

Note that the path can start **at any node**  in the tree, and you cannot go from a node to its parent in the path.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/consec1-1-tree.jpg" style="width: 306px; height: 400px;">

```bash
Input: root = [1,null,3,2,4,null,null,null,5]
Output: 3
Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/consec1-2-tree.jpg" style="width: 249px; height: 400px;">

```bash
Input: root = [2,null,3,2,null,1]
Output: 2
Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 3 * 10^4]`.
- `-3 * 10^4 <= Node.val <= 3 * 10^4`

## Hints/Notes

- traverse the tree

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
    int res = 0;

    int longestConsecutive(TreeNode* root) {
        traverse(root, 1);
        return res;
    }

    void traverse(TreeNode* root, int cur) {
        if (root->left) {
            if (root->left->val == root->val + 1) {
                traverse(root->left, cur + 1);
            } else {
                traverse(root->left, 1);
            }
        }
        if (root->right) {
            if (root->right->val == root->val + 1) {
                traverse(root->right, cur + 1);
            } else {
                traverse(root->right, 1);
            }
        }
        res = max(res, cur);
    }
};
```
