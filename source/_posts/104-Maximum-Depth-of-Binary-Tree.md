---
title: 104. Maximum Depth of Binary Tree
categories: Leetcode
date: 2023-02-02 12:54:26
tags:
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Binary Tree
---

[104\. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

## Description

Difficulty: **Easy**

Related Topics: [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

Given the `root` of a binary tree, return _its maximum depth_.

A binary tree's **maximum depth** is the number of nodes along the longest path from the root node down to the farthest leaf node.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/11/26/tmp-tree.jpg)

```bash
Input: root = [3,9,20,null,null,15,7]
Output: 3
```

**Example 2:**

```bash
Input: root = [1,null,2]
Output: 2
```

**Constraints:**

* The number of nodes in the tree is in the range [0, 10<sup>4</sup>].
* `-100 <= Node.val <= 100`

## Hints/Notes

* 2023/08/15
* Think about the tree's left and right
* [0x3F's solution](https://leetcode.cn/problems/maximum-depth-of-binary-tree/solutions/2010612/kan-wan-zhe-ge-shi-pin-rang-ni-dui-di-gu-44uz/)(checked)

## Solution

Language: **C++**

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
```
