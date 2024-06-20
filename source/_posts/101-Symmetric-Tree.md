---
title: 101. Symmetric Tree
categories: Leetcode
date: 2024-06-19 22:59:12
tags:
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Binary Tree
---

[101. Symmetric Tree](https://leetcode.com/problems/symmetric-tree/description/)

## Description

Given the `root` of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

**Example 1:**
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/symtree1.jpg" style="width: 354px; height: 291px;">

```bash
Input: root = [1,2,2,3,4,4,3]
Output: true
```

**Example 2:**
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/symtree2.jpg" style="width: 308px; height: 258px;">

```bash
Input: root = [1,2,2,null,3,null,3]
Output: false
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 1000]`.
- `-100 <= Node.val <= 100`

**Follow up:**  Could you solve it both recursively and iteratively?

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
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }

        return isMirrorTree(root->left, root->right);
    }

    bool isMirrorTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }

        if (!p || !q) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        return isMirrorTree(p->left, q->right) &&
               isMirrorTree(p->right, q->left);
    }
};
```
