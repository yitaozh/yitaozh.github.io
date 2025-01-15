---
title: 314. Binary Tree Vertical Order Traversal
categories: Leetcode
date: 2025-01-15 00:46:45
tags:
    - Hash Table
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Sorting
    - Binary Tree
---

[314. Binary Tree Vertical Order Traversal](https://leetcode.com/problems/binary-tree-vertical-order-traversal/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given the `root` of a binary tree, return **the vertical order traversal**  of its nodes' values. (i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from **left to right** .

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2024/09/23/image1.png" style="width: 400px; height: 273px;">

```bash
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2024/09/23/image3.png" style="width: 450px; height: 285px;">

```bash
Input: root = [3,9,8,4,0,1,7]
Output: [[4],[9],[3,0,1],[8],[7]]
```

**Example 3:**

<img alt="" src="https://assets.leetcode.com/uploads/2024/09/23/image2.png" style="width: 350px; height: 342px;">

```bash
Input: root = [1,2,3,4,10,9,11,null,5,null,null,null,null,null,null,null,6]
Output: [[4],[2,5],[1,10,9,6],[3],[11]]
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`

## Hints/Notes

- 2025/01/14
- binary tree
- premium

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
    map<int, map<int, vector<int>>> m;

    vector<vector<int>> verticalOrder(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> res;
        for (auto& [_, mp] : m) {
            vector<int> cur;
            for (auto& [_, v] : mp) {
                cur.insert(cur.end(), v.begin(), v.end());
            }
            res.push_back(cur);
        }
        return res;
    }

    void dfs(TreeNode* root, int level, int order) {
        if (!root) {
            return;
        }
        m[order][level].push_back(root->val);
        dfs(root->left, level + 1, order - 1);
        dfs(root->right, level + 1, order + 1);
    }
};
```
