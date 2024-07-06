---
title: 1120. Maximum Average Subtree
categories: Leetcode
date: 2024-07-05 23:28:48
tags:
    - Tree
    - Depth-First Search
    - Binary Tree
---

[1120. Maximum Average Subtree](https://leetcode.com/problems/maximum-average-subtree/description/)

## Description

Given the `root` of a binary tree, return the maximum **average**  value of a **subtree**  of that tree. Answers within `10^-5` of the actual answer will be accepted.

A **subtree**  of a tree is any node of that tree plus all its descendants.

The **average**  value of a tree is the sum of its values, divided by the number of nodes.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/04/09/1308_example_1.png" style="width: 132px; height: 123px;">

```bash
Input: root = [5,6,1]
Output: 6.00000
Explanation:
For the node with value = 5 we have an average of (5 + 6 + 1) / 3 = 4.
For the node with value = 6 we have an average of 6 / 1 = 6.
For the node with value = 1 we have an average of 1 / 1 = 1.
So the answer is 6 which is the maximum.
```

**Example 2:**

```bash
Input: root = [0,null,1]
Output: 1.00000
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `0 <= Node.val <= 10^5`

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
    double res = 0;

    double maximumAverageSubtree(TreeNode* root) {
        traverse(root);
        return res;
    }

    pair<int, int> traverse(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

        auto l = traverse(root->left);
        auto r = traverse(root->right);

        int sum = root->val + l.first + r.first;
        int cnt = 1 + l.second + r.second;
        double tmp = sum * 1.0 / cnt;
        res = max(res, tmp);

        return {sum, cnt};
    }
};
```
