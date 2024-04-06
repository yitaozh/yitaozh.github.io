---
title: 95. Unique Binary Search Trees II
categories: Leetcode
date: 2023-08-27 23:26:38
tags:
    - Dynamic Programming
    - Backtracking
    - Tree
    - Binary Search Tree
    - Binary Tree
---

[95\. Unique Binary Search Trees II](https://leetcode.com/problems/unique-binary-search-trees-ii/)

## Description

Difficulty: **Medium**

Related Topics: [Dynamic Programming](https://leetcode.com/tag/https://leetcode.com/tag/dynamic-programming//), [Backtracking](https://leetcode.com/tag/https://leetcode.com/tag/backtracking//), [Tree](https://leetcode.com/tag/https://leetcode.com/tag/tree//), [Binary Search Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-search-tree//), [Binary Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-tree//)

Given an integer `n`, return _all the structurally unique **BST'**s (binary search trees), which has exactly_ `n` _nodes of unique values from_ `1` _to_ `n`. Return the answer in **any order**.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg)

```bash
Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
```

**Example 2:**

```bash
Input: n = 1
Output: [[1]]
```

**Constraints:**

* `1 <= n <= 8`

## Hints/Notes

* Draw the tree
* Dynamic programming

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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return generate(1, n);
    }

    vector<TreeNode*> generate(int low, int high) {
        vector<TreeNode*> res;
        if (low > high) {
            res.push_back(nullptr);
            return res;
        } else if (low == high) {
            res.push_back(new TreeNode(low));
            return res;
        }

        for (int i = low; i <= high; i++) {
            vector<TreeNode*> leftTrees = generate(low, i - 1);
            vector<TreeNode*> rightTrees = generate(i + 1, high);
            for (TreeNode* leftTree : leftTrees) {
                for (TreeNode* rightTree : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTree;
                    root->right = rightTree;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
```
