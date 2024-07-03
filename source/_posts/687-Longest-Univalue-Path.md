---
title: 687. Longest Univalue Path
categories: Leetcode
date: 2024-07-02 23:15:34
tags:
    - Tree
    - Depth-First Search
    - Binary Tree
---

[687. Longest Univalue Path](https://leetcode.com/problems/longest-univalue-path/description/)

## Description

Given the `root` of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.

**The length of the path**  between two nodes is represented by the number of edges between them.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/10/13/ex1.jpg" style="width: 450px; height: 238px;">

```bash
Input: root = [5,4,5,1,1,null,5]
Output: 2
Explanation: The shown image shows that the longest path of the same value (i.e. 5).
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/10/13/ex2.jpg" style="width: 450px; height: 238px;">

```bash
Input: root = [1,4,5,4,4,null,5]
Output: 2
Explanation: The shown image shows that the longest path of the same value (i.e. 4).
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-1000 <= Node.val <= 1000`
- The depth of the tree will not exceed `1000`.

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
    int res = 0;

    int longestUnivaluePath(TreeNode* root) {
        if (!root) {
            return 0;
        }
        traverse(root, root->val);
        return res;
    }

    int traverse(TreeNode* root, int val) {
        if (!root) {
            return 0;
        }
        int left = traverse(root->left, root->val);
        int right = traverse(root->right, root->val);

        res = max(res, left + right);

        if (root->val != val) {
            return 0;
        }

        return max(left, right) + 1;
    }
};
```
