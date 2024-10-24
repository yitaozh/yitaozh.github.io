---
title: 1026. Maximum Difference Between Node and Ancestor
categories: Leetcode
date: 2024-07-03 23:35:38
tags:
    - Tree
    - Depth-First Search
    - Binary Tree
---

[1026. Maximum Difference Between Node and Ancestor](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/)

## Description

Given the `root` of a binary tree, find the maximum value `v` for which there exist **different**  nodes `a` and `b` where `v = |a.val - b.val|` and `a` is an ancestor of `b`.

A node `a` is an ancestor of `b` if either: any child of `a` is equal to `b`or any child of `a` is an ancestor of `b`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/11/09/tmp-tree.jpg" style="width: 400px; height: 390px;">

```bash
Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/11/09/tmp-tree-1.jpg" style="width: 250px; height: 349px;">

```bash
Input: root = [1,null,2,null,0,3]
Output: 3
```

**Constraints:**

- The number of nodes in the tree is in the range `[2, 5000]`.
- `0 <= Node.val <= 10^5`

## Hints/Notes

- back tracking

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
    map<int, int> s;
    int res = 0;

    int maxAncestorDiff(TreeNode* root) {
        traverse(root);
        return res;
    }

    void traverse(TreeNode* root) {
        if (!root) {
            return;
        }
        s[root->val]++;
        int minVal = s.begin()->first;
        int maxVal = s.rbegin()->first;
        res = max(res, abs(maxVal - minVal));
        traverse(root->left);
        traverse(root->right);
        s[root->val]--;
        if (s[root->val] == 0) {
            s.erase(root->val);
        }
    }
};
```
