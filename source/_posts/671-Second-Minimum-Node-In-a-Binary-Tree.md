---
title: 671. Second Minimum Node In a Binary Tree
categories: Leetcode
date: 2024-07-13 01:39:39
tags:
    - Tree
    - Depth-First Search
    - Binary Tree
---

[671. Second Minimum Node In a Binary Tree](https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/)

## Description

Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly `two` or `zero` sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property`root.val = min(root.left.val, root.right.val)`always holds.

Given such a binary tree, you need to output the <b>second minimum</b> value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/10/15/smbt1.jpg" style="width: 431px; height: 302px;">

```bash
Input: root = [2,2,5,null,null,5,7]
Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/10/15/smbt2.jpg" style="width: 321px; height: 182px;">

```bash
Input: root = [2,2,2]
Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 25]`.
- `1 <= Node.val <= 2^31 - 1`
- `root.val == min(root.left.val, root.right.val)`for each internal node of the tree.

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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root->left && !root->right) {
            return -1;
        }

        int left = root->left->val, right = root->right->val;
        // the child's val is the minimum of the child tree
        // 1. if the child->val == root->val, then no need to dig further
        // 2. if the child->val != root->val, it indicates that there can be
        //    value larger than child->val
        // if the return value is -1:
        //     1. either the node doesn't have children
        //     2. all its children have the same value
        if (left == root->val) {
            left = findSecondMinimumValue(root->left);
        }

        if (right == root->val) {
            right = findSecondMinimumValue(root->right);
        }

        if (left == -1) {
            return right;
        }

        if (right == -1) {
            return left;
        }

        return min(left, right);
    }
};
```
