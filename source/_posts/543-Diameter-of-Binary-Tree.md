---
title: 543. Diameter of Binary Tree
categories: Leetcode
date: 2023-02-02 13:05:47
tags:
    - Tree
    - Depth-First Search
    - Binary Tree
---

[543\. Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)

## Description

Difficulty: **Easy**

Related Topics: [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

Given the `root` of a binary tree, return _the length of the **diameter** of the tree_.

The **diameter** of a binary tree is the **length** of the longest path between any two nodes in a tree. This path may or may not pass through the `root`.

The **length** of a path between two nodes is represented by the number of edges between them.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/06/diamtree.jpg)

```text
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
```

**Example 2:**

```text
Input: root = [1,2]
Output: 1
```

**Constraints:**

* The number of nodes in the tree is in the range [1, 10<sup>4</sup>].
* `-100 <= Node.val <= 100`

## Hints/Notes

* Draw and imagine the diameter

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
    int res = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return res;
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        res = max(left + right, res);
        return max(left, right) + 1;
    }
};
```
