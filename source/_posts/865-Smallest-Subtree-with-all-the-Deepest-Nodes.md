---
title: 865. Smallest Subtree with all the Deepest Nodes
categories: Leetcode
date: 2024-07-03 23:34:00
tags:
    - Hash Table
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Binary Tree
---

[865. Smallest Subtree with all the Deepest Nodes](https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/)

## Description

Given the `root` of a binary tree, the depth of each node is **the shortest distance to the root**.

Return the smallest subtree such that it contains **all the deepest nodes** in the original tree.

A node is called **the deepest** if it has the largest depth possible among any node in the entire tree.

The **subtree** of a node is a tree consisting of that node, plus the set of all descendants of that node.

**Example 1:**

<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/01/sketch1.png" style="width: 600px; height: 510px;">

```bash
Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest nodes of the tree.
Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.
```

**Example 2:**

```bash
Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree.
```

**Example 3:**

```bash
Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest node in the tree is 2, the valid subtrees are the subtrees of nodes 2, 1 and 0 but the subtree of node 2 is the smallest.
```

**Constraints:**

- The number of nodes in the tree will be in the range `[1, 500]`.
- `0 <= Node.val <= 500`
- The values of the nodes in the tree are **unique** .

**Note:**  This question is the same as 1123: <a href="https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/" target="_blank">https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/</a>

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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* res;
    int maxDepth = -1;

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) {
            return root;
        }

        traverse(root, 0);
        return res;
    }

    int traverse(TreeNode* root, int depth) {
        if (!root) {
            return depth - 1;
        }

        if (depth > maxDepth) {
            maxDepth = depth;
            res = root;
        }

        int left = traverse(root->left, depth + 1);
        int right = traverse(root->right, depth + 1);

        if (left == right && left == maxDepth) {
            res = root;
        }

        return left > right ? left : right;
    }
};
```
