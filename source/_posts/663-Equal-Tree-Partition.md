---
title: 663. Equal Tree Partition
categories: Leetcode
date: 2024-07-02 23:14:07
tags:
    - Tree
    - Depth-First Search
    - Binary Tree
---

[663. Equal Tree Partition](https://leetcode.com/problems/equal-tree-partition/description/)

## Description

Given the `root` of a binary tree, return `true` if you can partition the tree into two trees with equal sums of values after removing exactly one edge on the original tree.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/05/03/split1-tree.jpg" style="width: 500px; height: 204px;">

```bash
Input: root = [5,10,10,null,null,2,3]
Output: true
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/05/03/split2-tree.jpg" style="width: 277px; height: 302px;">

```bash
Input: root = [1,2,10,null,null,2,20]
Output: false
Explanation: You cannot split the tree into two trees with equal sums after removing exactly one edge on the tree.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-10^5 <= Node.val <= 10^5`

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
    unordered_set<int> s;

    bool checkEqualTree(TreeNode* root) {
        int treeSum = root->val + traverse(root->left) + traverse(root->right);
        if (treeSum % 2) {
            return false;
        }
        return s.contains(treeSum / 2);
    }

    int traverse(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int val = root->val;

        int left = traverse(root->left);
        int right = traverse(root->right);

        val += left + right;

        s.insert(val);
        return val;
    }
};
```
