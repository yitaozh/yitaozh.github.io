---
title: 968. Binary Tree Cameras
categories: Leetcode
date: 2024-07-05 23:34:30
tags:
    - Dynamic Programming
    - Tree
    - Depth-First Search
    - Binary Tree
---

[968. Binary Tree Cameras](https://leetcode.com/problems/binary-tree-cameras/description/)

## Description

You are given the `root` of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2018/12/29/bst_cameras_01.png" style="width: 138px; height: 163px;">

```bash
Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2018/12/29/bst_cameras_02.png" style="width: 139px; height: 312px;">

```bash
Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 1000]`.
- `Node.val == 0`

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

    int minCameraCover(TreeNode* root) {
        setCamera(root, false, 0);
        return res;
    }

    // the meaning of the return value:
    // 1. -1: the node doesn't exist, i.e. nullptr
    // 2. 0: the node is leaf
    // 3. 1: the node has one camera
    int setCamera(TreeNode* root, bool hasParent, int depth) {
        if (!root) {
            return -1;
        }

        int l = setCamera(root->left, true, depth + 1);
        int r = setCamera(root->right, true, depth + 1);

        if (l == -1 && r == -1) {
            if (hasParent) {
                return 0;
            } else {
                res++;
                return 1;
            }
        }

        if (l == 0 || r == 0) {
            res++;
            return 1;
        }

        // the above conditions have ensured that there's
        // at least one 1 in l and r
        return -1;
        // if (l == 1 || r == 1) {
        //     return -1;
        // }
    }
};
```
