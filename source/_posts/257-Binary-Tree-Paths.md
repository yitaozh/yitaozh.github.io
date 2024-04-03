---
title: 257. Binary Tree Paths
categories: Leetcode
date: 2024-04-03 15:49:34
tags:
    - String
    - Backtracking
    - Tree
    - Depth-First Search
    - Binary Tree
---

# [257. Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/description/)

Given the `root` of a binary tree, return all root-to-leaf paths in **any order** .

A **leaf**  is a node with no children.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/03/12/paths-tree.jpg" style="width: 207px; height: 293px;">

```bash
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
```

**Example 2:**

```bash
Input: root = [1]
Output: ["1"]
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 100]`.
- `-100 <= Node.val <= 100`

## Hints/Notes

- traverse the tree

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
    vector<string> res;

    vector<string> binaryTreePaths(TreeNode* root) {
        traverse(root, "");
        return res;
    }

    void traverse(TreeNode* root, string path) {
        if (!root) {
            return;
        }
        path += to_string(root->val);
        bool node = true;
        if (root->left) {
            traverse(root->left, path + "->");
            node = false;
        }
        if (root->right) {
            traverse(root->right, path + "->");
            node = false;
        }
        if (node) {
            res.push_back(path);
        }
    }
};
```
