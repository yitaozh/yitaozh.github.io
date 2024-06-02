---
title: 993. Cousins in Binary Tree
categories: Leetcode
date: 2024-05-24 18:08:11
tags:
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Binary Tree
---

[993. Cousins in Binary Tree](https://leetcode.com/problems/cousins-in-binary-tree/description/)

## Description

Given the `root` of a binary tree with unique values and the values of two different nodes of the tree `x` and `y`, return `true` if the nodes corresponding to the values `x` and `y` in the tree are **cousins** , or `false` otherwise.

Two nodes of a binary tree are **cousins**  if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth `0`, and children of each depth `k` node are at the depth `k + 1`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/02/12/q1248-01.png" style="width: 304px; height: 270px;">

```bash
Input: root = [1,2,3,4], x = 4, y = 3
Output: false
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/02/12/q1248-02.png" style="width: 334px; height: 266px;">

```bash
Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
```

**Example 3:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/02/13/q1248-03.png" style="width: 267px; height: 258px;">

```bash
Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
```

**Constraints:**

- The number of nodes in the tree is in the range `[2, 100]`.
- `1 <= Node.val <= 100`
- Each node has a **unique**  value.
- `x != y`
- `x` and `y` are exist in the tree.

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
    int x_;
    int y_;
    int depthX = -1;
    int depthY = -1;
    TreeNode* parentX;
    TreeNode* parentY;

    bool isCousins(TreeNode* root, int x, int y) {
        x_ = x;
        y_ = y;
        dfs(root, 0, nullptr);
        return depthX == depthY && parentX != parentY;
    }

    void dfs(TreeNode* root, int depth, TreeNode* parent) {
        if (!root) {
            return;
        }

        if (depthX != -1 && depthY != -1) {
            return;
        }

        if (root->val == x_) {
            depthX = depth;
            parentX = parent;
        }

        if (root->val == y_) {
            depthY = depth;
            parentY = parent;
        }

        dfs(root->left, depth + 1, root);
        dfs(root->right, depth + 1, root);
    }
};
```
