---
title: 1038. Binary Search Tree to Greater Sum Tree
categories: Leetcode
date: 2025-03-14 13:31:18
tags:
    - Tree
    - Depth-First Search
    - Binary Search Tree
    - Binary Tree
---

[1038. Binary Search Tree to Greater Sum Tree](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/)

## Description

Given the `root` of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

- The left subtree of a node contains only nodes with keys **less than**  the node's key.
- The right subtree of a node contains only nodes with keys **greater than**  the node's key.
- Both the left and right subtrees must also be binary search trees.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/05/02/tree.png" style="width: 400px; height: 273px;">

```bash
Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
```

**Example 2:**

```bash
Input: root = [0,null,1]
Output: [1,null,1]
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 100]`.
- `0 <= Node.val <= 100`
- All the values in the tree are **unique** .

**Note:**  This question is the same as 538: <a href="https://leetcode.com/problems/convert-bst-to-greater-tree/" target="_blank">https://leetcode.com/problems/convert-bst-to-greater-tree/</a>

## Hints/Notes

- 2025/03/14 Q2
- tree
- [0x3F's solution](https://leetcode.cn/problems/binary-search-tree-to-greater-sum-tree/solutions/2552797/jian-ji-xie-fa-li-yong-er-cha-sou-suo-sh-r5zm/)

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
    int sum = 0;

    TreeNode* bstToGst(TreeNode* root) {
        if (!root) {
            return root;
        }
        bstToGst(root->right);
        int tmp = root->val;
        root->val += sum;
        sum += tmp;
        bstToGst(root->left);
        return root;
    }
};
```
