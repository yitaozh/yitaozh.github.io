---
title: 285. Inorder Successor in BST
categories: Leetcode
date: 2024-07-13 01:35:25
tags:
    - Tree
    - Depth-First Search
    - Binary Search Tree
    - Binary Tree
---

[285. Inorder Successor in BST](https://leetcode.com/problems/inorder-successor-in-bst/description/)

## Description

Given the `root` of a binary search tree and a node `p` in it, return the in-order successor of that node in the BST. If the given node has no in-order successor in the tree, return `null`.

The successor of a node `p` is the node with the smallest key greater than `p.val`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/01/23/285_example_1.PNG" style="width: 122px; height: 117px;">

```bash
Input: root = [2,1,3], p = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/01/23/285_example_2.PNG" style="width: 246px; height: 229px;">

```bash
Input: root = [5,3,6,2,4,null,null,1], p = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer is `null`.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-10^5 <= Node.val <= 10^5`
- All Nodes will have unique values.

## Hints/Notes

- binary search tree

## Solution

Language: **C++**

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* node = nullptr;
    int found = false;

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        traverse(root, p);
        return node;
    }

    void traverse(TreeNode* root, TreeNode* p) {
        if (!root || node) {
            return;
        }
        traverse(root->left, p);

        if (found && !node) {
            node = root;
        }

        if (root == p) {
            found = true;
        }
        traverse(root->right, p);
    }
};
```
