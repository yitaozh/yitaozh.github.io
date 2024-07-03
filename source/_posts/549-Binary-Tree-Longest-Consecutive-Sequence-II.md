---
title: 549. Binary Tree Longest Consecutive Sequence II
categories: Leetcode
date: 2024-07-02 23:10:59
tags:
    - Tree
    - Depth-First Search
    - Binary Tree
---

[549. Binary Tree Longest Consecutive Sequence II](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/description/)

## Description

Given the `root` of a binary tree, return the length of the longest consecutive path in the tree.

A consecutive path is a path where the values of the consecutive nodes in the path differ by one. This path can be either increasing or decreasing.

- For example, `[1,2,3,4]` and `[4,3,2,1]` are both considered valid, but the path `[1,2,4,3]` is not valid.

On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/consec2-1-tree.jpg" style="width: 207px; height: 183px;">

```bash
Input: root = [1,2,3]
Output: 2
Explanation: The longest consecutive path is [1, 2] or [2, 1].
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/consec2-2-tree.jpg" style="width: 207px; height: 183px;">

```bash
Input: root = [2,1,3]
Output: 3
Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 3 * 10^4]`.
- `-3 * 10^4 <= Node.val <= 3 * 10^4`

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

    int longestConsecutive(TreeNode* root) {
        traverse(root);
        return res;
    }

    pair<int, int> traverse(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

        int inc = 1, dec = 1, l = 1, r = 1;
        if (root->left) {
            auto left = traverse(root->left);
            if (root->val == root->left->val + 1) {
                inc += left.first;
                l = max(l, 1 + left.first);
            } else if (root->val == root->left->val - 1) {
                dec += left.second;
                r = max(r, 1 + left.second);
            }
        }
        if (root->right) {
            auto right = traverse(root->right);
            if (root->val == root->right->val + 1) {
                dec += right.first;
                l = max(l, 1 + right.first);
            } else if (root->val == root->right->val - 1) {
                inc += right.second;
                r = max(r, 1 + right.second);
            }
        }
        res = max(res, max(inc, dec));
        return {l, r};
    }
};
```
