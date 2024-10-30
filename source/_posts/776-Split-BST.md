---
title: 776. Split BST
categories: Leetcode
date: 2024-07-13 01:40:45
tags:
    - Tree
    - Binary Search Tree
    - Recursion
    - Binary Tree
---

[776. Split BST](https://leetcode.com/problems/split-bst/description/)

## Description

Given the `root` of a binary search tree (BST) and an integer `target`, split the tree into two subtrees where the first subtree has nodes that are all smaller or equal to the target value, while the second subtree has all nodes that are greater than the target value. It is not necessarily the case that the tree contains a node with the value `target`.

Additionally, most of the structure of the original tree should remain. Formally, for any child `c` with parent `p` in the original tree, if they are both in the same subtree after the split, then node `c` should still have the parent `p`.

Return an array of the two roots of the two subtrees in order.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/06/13/split-tree.jpg" style="width: 600px; height: 193px;">

```bash
Input: root = [4,2,6,1,3,5,7], target = 2
Output: [[2,1],[4,3,6,null,null,5,7]]
```

**Example 2:**

```bash
Input: root = [1], target = 1
Output: [[1],[]]
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 50]`.
- `0 <= Node.val, target <= 1000`

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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        if (!root) {
            return {nullptr, nullptr};
        }
        vector<TreeNode*> res;
        if (root->val > target) {
            auto l = splitBST(root->left, target);
            root->left = l[1];
            res.push_back(l[0]);
            res.push_back(root);
        } else {
            auto r = splitBST(root->right, target);
            root->right = r[0];
            res.push_back(root);
            res.push_back(r[1]);
        }
        return res;
    }
};
```
