---
title: 113. Path Sum II
categories: Leetcode
date: 2024-06-19 23:02:55
tags:
    - Backtracking
    - Tree
    - Depth-First Search
    - Binary Tree
---

[113. Path Sum II](https://leetcode.com/problems/path-sum-ii/description/)

## Description

Given the `root` of a binary tree and an integer `targetSum`, return all **root-to-leaf**  paths where the sum of the node values in the path equals `targetSum`. Each path should be returned as a list of the node **values** , not node references.

A **root-to-leaf**  path is a path starting from the root and ending at any leaf node. A **leaf**  is a node with no children.

**Example 1:**
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/18/pathsumii1.jpg" style="width: 500px; height: 356px;">

```bash
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
```

**Example 2:**
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg" style="width: 212px; height: 181px;">

```bash
Input: root = [1,2,3], targetSum = 5
Output: []
```

**Example 3:**

```bash
Input: root = [1,2], targetSum = 0
Output: []
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 5000]`.
- `-1000 <= Node.val <= 1000`
- `-1000 <= targetSum <= 1000`

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
    vector<int> cur;
    vector<vector<int>> res;
    int curSum = 0;
    int targetSum_;

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        targetSum_ = targetSum;
        traverse(root);
        return res;
    }

    void traverse(TreeNode* root) {
        if (!root) {
            return;
        }

        curSum += root->val;
        cur.push_back(root->val);

        if (!root->left && !root->right && curSum == targetSum_) {
            res.push_back(cur);
        }

        traverse(root->left);
        traverse(root->right);

        cur.pop_back();
        curSum -= root->val;
    }
};
```
