---
title: 98. Validate Binary Search Tree
categories: Leetcode
date: 2023-08-26 23:55:46
tags:
    - Tree
    - Depth-First Search
    - Binary Search Tree
    - Binary Tree
---

# [98\. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)

## Description

Difficulty: **Medium**

Related Topics: [Tree](https://leetcode.com/tag/https://leetcode.com/tag/tree//), [Depth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/depth-first-search//), [Binary Search Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-search-tree//), [Binary Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-tree//)

Given the `root` of a binary tree, _determine if it is a valid binary search tree (BST)_.

A **valid BST** is defined as follows:

* The left<span data-keyword="subtree" datakeyword="subtree" class=" cursor-pointer relative text-dark-blue-s text-sm"> subtree </span>of a node contains only nodes with keys **less than** the node's key.
* The right subtree of a node contains only nodes with keys **greater than** the node's key.
* Both the left and right subtrees must also be binary search trees.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg)

```bash
Input: root = [2,1,3]
Output: true
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg)

```bash
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
```

**Constraints:**

* The number of nodes in the tree is in the range [1, 10<sup>4</sup>].
* -2<sup>31</sup> <= Node.val <= 2<sup>31</sup> - 1

# Hints/Notes

* We need max/min node to decide if one node is valid
* Because the val is between MIN_INT and MAX_INT, so use a nullptr node is better

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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }

    bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == nullptr) return true;
        if (min && root->val <= min->val) return false;
        if (max && root->val >= max->val) return false;
        return isValidBST(root->left, min, root)
            && isValidBST(root->right, root, max);
    }
};
```
