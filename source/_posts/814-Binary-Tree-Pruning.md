---
title: 814. Binary Tree Pruning
categories: Leetcode
date: 2024-07-13 01:41:52
tags:
    - Tree
    - Depth-First Search
    - Binary Tree
---

[814. Binary Tree Pruning](https://leetcode.com/problems/binary-tree-pruning/description/)

## Description

Given the `root` of a binary tree, return the same tree where every subtree (of the given tree) not containing a `1` has been removed.

A subtree of a node `node` is `node` plus every node that is a descendant of `node`.

**Example 1:**

<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_2.png" style="width: 500px; height: 140px;">

```bash
Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
Explanation:
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.
```

**Example 2:**

<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_1.png" style="width: 500px; height: 115px;">

```bash
Input: root = [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]
```

**Example 3:**
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/05/1028.png" style="width: 500px; height: 134px;">

```bash
Input: root = [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 200]`.
- `Node.val` is either `0` or `1`.

## Hints/Notes

- binary tree
- No solution from 0x3F

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
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if (!root->left && !root->right && root->val == 0) {
            return nullptr;
        }
        return root;
    }
};
```
