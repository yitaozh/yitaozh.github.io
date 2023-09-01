---
title: 222. Count Complete Tree Nodes
categories: Leetcode
date: 2023-08-30 23:48:19
tags:
    - Binary Search
    - Tree
    - Depth-First Search
    - Binary Tree
---

# [222\. Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes/)

## Description

Difficulty: **Easy**

Related Topics: [Binary Search](https://leetcode.com/tag/https://leetcode.com/tag/binary-search//), [Tree](https://leetcode.com/tag/https://leetcode.com/tag/tree//), [Depth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/depth-first-search//), [Binary Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-tree//)

Given the `root` of a **complete** binary tree, return the number of the nodes in the tree.

According to **[Wikipedia](http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees)**, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between `1` and 2<sup>h</sup> nodes inclusive at the last level `h`.

Design an algorithm that runs in less than `O(n)` time complexity.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/14/complete.jpg)

```bash
Input: root = [1,2,3,4,5,6]
Output: 6
```

**Example 2:**

```bash
Input: root = []
Output: 0
```

**Example 3:**

```bash
Input: root = [1]
Output: 1
```

**Constraints:**

* The number of nodes in the tree is in the range [0, 5 * 10<sup>4</sup>].
* 0 <= Node.val <= 5 * 10<sup>4</sup>
* The tree is guaranteed to be **complete**.

## Hints/Notes

* Check if it's a full BST to improve the time complexity

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
    int countNodes(TreeNode* root) {
        int count = 0;
        if (!root) return count;
        int leftDepth = 0, rightDepth = 0;
        TreeNode* tmp = root;
        while (tmp) {
            leftDepth++;
            tmp = tmp->left;
        }
        tmp = root;
        while (tmp) {
            rightDepth++;
            tmp = tmp->right;
        }
        if (leftDepth == rightDepth) {
            return pow(2, leftDepth) - 1;
        }
        int leftCount = countNodes(root->left);
        int rightCount = countNodes(root->right);
        return leftCount + rightCount + 1;
    }
};
```
