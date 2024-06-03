---
title: 1602. Find Nearest Right Node in Binary Tree
categories: Leetcode
date: 2024-05-30 12:39:29
tags:
    - Tree
    - Breadth-First Search
    - Binary Tree
---

[1602. Find Nearest Right Node in Binary Tree](https://leetcode.com/problems/find-nearest-right-node-in-binary-tree/description/)

## Description

Given the `root` of a binary tree and a node `u` in the tree, return the **nearest**  node on the **same level**  that is to the **right**  of `u`, or return `null` if `u` is the rightmost node in its level.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/09/24/p3.png" style="width: 241px; height: 161px;">

```bash
Input: root = [1,2,3,null,4,5,6], u = 4
Output: 5
Explanation: The nearest node on the same level to the right of node 4 is node 5.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/09/23/p2.png" style="width: 101px; height: 161px;">

```bash
Input: root = [3,null,4,2], u = 2
Output: null
Explanation: There are no nodes to the right of 2.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^5]`.
- `1 <= Node.val <= 10^5`
- All values in the tree are **distinct** .
- `u` is a node in the binary tree rooted at `root`.

## Hints/Notes

- use targetDepth as a proxy to show the node has been found

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
    int targetDepth = -1;
    TreeNode* target = nullptr;

    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        traverse(root, u, 0);
        return target;
    }

    void traverse(TreeNode* root, TreeNode* u, int depth) {
        if (!root || target) {
            return;
        }
        if (depth == targetDepth) {
            target = root;
        }
        if (root == u) {
            targetDepth = depth;
        }
        traverse(root->left, u, depth + 1);
        traverse(root->right, u, depth + 1);
    }
};
```
