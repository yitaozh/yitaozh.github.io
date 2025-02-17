---
title: 199. Binary Tree Right Side View
categories: Leetcode
date: 2024-04-03 15:56:54
tags:
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Binary Tree
---

[199. Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/description/)

## Description

Given the `root` of a binary tree, imagine yourself standing on the **right side**  of it, return the values of the nodes you can see ordered from top to bottom.

**Example 1:**
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/14/tree.jpg" style="width: 401px; height: 301px;">

```bash
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
```

**Example 2:**

```bash
Input: root = [1,null,3]
Output: [1,3]
```

**Example 3:**

```bash
Input: root = []
Output: []
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`

## Hints/Notes

- 2023/12/31
- bfs level traverse the tree
- [0x3F's solution](https://leetcode.cn/problems/binary-tree-right-side-view/solutions/2015061/ru-he-ling-huo-yun-yong-di-gui-lai-kan-s-r1nc/)(checked)

## Solution

Language: **C++**

Recursive solution:

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
    vector<int> res;
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* root, int depth) {
        if (!root) {
            return;
        }
        if (res.size() == depth) {
            res.push_back(root->val);
        }
        if (root->right) {
            dfs(root->right, depth + 1);
        }
        if (root->left) {
            dfs(root->left, depth + 1);
        }
    }
};
```

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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (i == 0) {
                    res.push_back(node->val);
                }
                if (node->right) {
                    q.push(node->right);
                }
                if (node->left) {
                    q.push(node->left);
                }
            }
        }
        return res;
    }
};
```
