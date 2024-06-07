---
title: 894. All Possible Full Binary Trees
categories: Leetcode
date: 2024-06-07 12:20:29
tags:
    - Dynamic Programming
    - Tree
    - Recursion
    - Memoization
    - Binary Tree
---

[894. All Possible Full Binary Trees](https://leetcode.com/problems/all-possible-full-binary-trees/description/)

## Description

Given an integer `n`, return a list of all possible **full binary trees**  with `n` nodes. Each node of each tree in the answer must have `Node.val == 0`.

Each element of the answer is the root node of one possible tree. You may return the final list of trees in **any order** .

A **full binary tree**  is a binary tree where each node has exactly `0` or `2` children.

**Example 1:**
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/08/22/fivetrees.png" style="width: 700px; height: 400px;">

```bash
Input: n = 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
```

**Example 2:**

```bash
Input: n = 3
Output: [[0,0,0]]
```

**Constraints:**

- `1 <= n <= 20`

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
    map<int, vector<TreeNode*>> m;

    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> res;
        if (n % 2 == 0) {
            return res;
        }
        return build(n);
    }

    vector<TreeNode*> build(int n) {
        if (m.contains(n)) {
            return m[n];
        }
        vector<TreeNode*> res;
        if (n == 1) {
            res.push_back(new TreeNode(0));
            m[n] = res;
            return res;
        }
        for (int i = 1; i < n; i += 2) {
            int j = n - i - 1;
            auto left = build(i);
            auto right = build(j);
            for (auto l : left) {
                for (auto r : right) {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        m[n] = res;
        return res;
    }
};
```
