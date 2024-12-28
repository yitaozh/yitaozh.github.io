---
title: 102. Binary Tree Level Order Traversal
categories: Leetcode
date: 2024-12-28 02:07:07
tags:
    - Tree
    - Breadth-First Search
    - Binary Tree
---

[102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given the `root` of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg" style="width: 277px; height: 302px;">

```bash
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
```

**Example 2:**

```bash
Input: root = [1]
Output: [[1]]
```

**Example 3:**

```bash
Input: root = []
Output: []
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 2000]`.
- `-1000 <= Node.val <= 1000`

## Hints/Notes

- 2024/12/27
- binary tree
- [0x3F's solution](https://leetcode.cn/problems/binary-tree-level-order-traversal/solutions/2049807/bfs-wei-shi-yao-yao-yong-dui-lie-yi-ge-s-xlpz/)(checked)

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> cur;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto* node = q.front();
                q.pop();
                cur.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(cur);
        }
        return res;
    }
};
```
