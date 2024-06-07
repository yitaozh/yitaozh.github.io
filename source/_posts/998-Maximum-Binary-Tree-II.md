---
title: 998. Maximum Binary Tree II
categories: Leetcode
date: 2024-06-07 12:21:51
tags:
    - Tree
    - Binary Tree
---

[998. Maximum Binary Tree II](https://leetcode.com/problems/maximum-binary-tree-ii/description/)

## Description

A **maximum tree**  is a tree where every node has a value greater than any other value in its subtree.

You are given the `root` of a maximum binary tree and an integer `val`.

Just as in the <a href="https://leetcode.com/problems/maximum-binary-tree/" target="_blank">previous problem</a>, the given tree was constructed from a list `a` (`root = Construct(a)`) recursively with the following `Construct(a)` routine:

- If `a` is empty, return `null`.
- Otherwise, let `a[i]` be the largest element of `a`. Create a `root` node with the value `a[i]`.
- The left child of `root` will be `Construct([a[0], a[1], ..., a[i - 1]])`.
- The right child of `root` will be `Construct([a[i + 1], a[i + 2], ..., a[a.length - 1]])`.
- Return `root`.

Note that we were not given `a` directly, only a root node `root = Construct(a)`.

Suppose `b` is a copy of `a` with the value `val` appended to it. It is guaranteed that `b` has unique values.

Return `Construct(b)`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/08/09/maxtree1.JPG" style="width: 376px; height: 235px;">

```bash
Input: root = [4,1,3,null,null,2], val = 5
Output: [5,4,null,1,3,null,null,2]
Explanation: a = [1,4,2,3], b = [1,4,2,3,5]
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/08/09/maxtree21.JPG" style="width: 358px; height: 156px;">

```bash
Input: root = [5,2,4,null,1], val = 3
Output: [5,2,4,null,1,null,3]
Explanation: a = [2,1,5,4], b = [2,1,5,4,3]
```

**Example 3:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/08/09/maxtree3.JPG" style="width: 404px; height: 180px;">

```bash
Input: root = [5,2,3,null,1], val = 4
Output: [5,2,4,null,1,3]
Explanation: a = [2,1,5,3], b = [2,1,5,3,4]
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 100]`.
- `1 <= Node.val <= 100`
- All the values of the tree are **unique** .
- `1 <= val <= 100`

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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        if (root->val < val) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        } else {
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        }
    }
};
```
