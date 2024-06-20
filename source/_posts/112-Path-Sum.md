---
title: 112. Path Sum
categories: Leetcode
date: 2024-06-19 23:01:43
tags:
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Binary Tree
---

[112. Path Sum](https://leetcode.com/problems/path-sum/description/)

## Description

Given the `root` of a binary tree and an integer `targetSum`, return `true` if the tree has a **root-to-leaf**  path such that adding up all the values along the path equals `targetSum`.

A **leaf**  is a node with no children.

**Example 1:**
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/18/pathsum1.jpg" style="width: 500px; height: 356px;">

```bash
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
```

**Example 2:**
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg">

```bash
Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
```

**Example 3:**

```bash
Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.
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
    bool found = false;
    int targetSum_;
    int curSum = 0;

    bool hasPathSum(TreeNode* root, int targetSum) {
        targetSum_ = targetSum;
        traverse(root);
        return found;
    }

    void traverse(TreeNode* root) {
        if (!root || found) {
            return;
        }
        curSum += root->val;

        if (!root->left && !root->right && curSum == targetSum_) {
            found = true;
            return;
        }

        traverse(root->left);
        traverse(root->right);

        curSum -= root->val;
    }
};
```
