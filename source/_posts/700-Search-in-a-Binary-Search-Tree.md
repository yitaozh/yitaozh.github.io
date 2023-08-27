---
title: 700. Search in a Binary Search Tree
categories: Leetcode
date: 2023-08-27 00:05:05
tags:
    - Tree
    - Binary Search Tree
    - Binary Tree
---

# [700\. Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/)

## Description

Difficulty: **Easy**

Related Topics: [Tree](https://leetcode.com/tag/https://leetcode.com/tag/tree//), [Binary Search Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-search-tree//), [Binary Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-tree//)

You are given the `root` of a binary search tree (BST) and an integer `val`.

Find the node in the BST that the node's value equals `val` and return the subtree rooted with that node. If such a node does not exist, return `null`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/12/tree1.jpg)

```bash
Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/01/12/tree2.jpg)

```bash
Input: root = [4,2,7,1,3], val = 5
Output: []
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 5000]`.
* 1 <= Node.val <= 10<sup>7</sup>
* `root` is a binary search tree.
* 1 <= val <= 10<sup>7</sup>

## Hints/Notes

* N/A

## Solution

Language: **C++**

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return root;
        if (root->val < val) {
            return searchBST(root->right, val);
        }
        if (root->val > val) {
            return searchBST(root->left, val);
        }
        return root;
    }
};
```
