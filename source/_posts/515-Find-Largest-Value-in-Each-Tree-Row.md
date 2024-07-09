---
title: 515. Find Largest Value in Each Tree Row
categories: Leetcode
date: 2024-07-08 23:21:31
tags:
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Binary Tree
---

[515. Find Largest Value in Each Tree Row](https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/)

## Description

Given the `root` of a binary tree, return an array of the largest value in each row of the tree **(0-indexed)** .

**Example 1:**
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/21/largest_e1.jpg" style="width: 300px; height: 172px;">

```bash
Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]
```

**Example 2:**

```bash
Input: root = [1,2,3]
Output: [1,3]
```

**Constraints:**

- The number of nodes in the tree will be in the range `[0, 10^4]`.
- `-2^31 <= Node.val <= 2^31 - 1`

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if (root)
            q.push(root);
        while (!q.empty()) {
            int maxValue = INT_MIN;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* cur = q.front();
                q.pop();
                maxValue = max(maxValue, cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            res.push_back(maxValue);
        }
        return res;
    }
};
```
