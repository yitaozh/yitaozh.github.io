---
title: 1028. Recover a Tree From Preorder Traversal
categories: Leetcode
date: 2025-03-14 12:00:54
tags:
    - String
    - Tree
    - Depth-First Search
    - Binary Tree
---

[1028. Recover a Tree From Preorder Traversal](https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/description/)

## Description

We run a preorder depth-first search (DFS) on the `root` of a binary tree.

At each node in this traversal, we output `D` dashes (where `D` is the depth of this node), then we output the value of this node. If the depth of a node is `D`, the depth of its immediate child is `D + 1`. The depth of the `root` node is `0`.

If a node has only one child, that child is guaranteed to be **the left child** .

Given the output `traversal` of this traversal, recover the tree and return its `root`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2024/09/10/recover_tree_ex1.png" style="width: 423px; height: 200px;">

```bash
Input: traversal = "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2024/09/10/recover_tree_ex2.png" style="width: 432px; height: 250px;">

```bash
Input: traversal = "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]
```

**Example 3:**

<img alt="" src="https://assets.leetcode.com/uploads/2024/09/10/recover_tree_ex3.png" style="width: 305px; height: 250px;">

```bash
Input: traversal = "1-401--349---90--88"
Output: [1,401,null,349,88,90]
```

**Constraints:**

- The number of nodes in the original tree is in the range `[1, 1000]`.
- `1 <= Node.val <= 10^9`

## Hints/Notes

- 2025/03/10 Q3
- tree
- [Leetcode solution](https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/editorial/)

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
    TreeNode* recoverFromPreorder(string traversal) {
        int index = 0;
        return dfs(traversal, index, 0);
    }

    TreeNode* dfs(string& s, int& index, int depth) {
        if (index >= s.size()) return nullptr;

        int dashCount = 0;
        while (index + dashCount < s.size() && s[index + dashCount] == '-') {
            dashCount++;
        }

        if (dashCount != depth) {
            return nullptr;
        }

        index += dashCount;

        int val = 0;
        while (index < s.size() && isdigit(s[index])) {
            val = val * 10 + s[index] - '0';
            index++;
        }

        TreeNode* node = new TreeNode(val);
        node->left = dfs(s, index, depth + 1);
        node->right = dfs(s, index, depth + 1);
        return node;
    }
};
```
