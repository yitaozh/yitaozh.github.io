---
title: 235. Lowest Common Ancestor of a Binary Search Tree
categories: Leetcode
date: 2023-08-29 14:27:21
tags:
    - Tree
    - Depth-First Search
    - Binary Search Tree
    - Binary Tree
---

[235\. Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

## Description

Difficulty: **Medium**

Related Topics: [Tree](https://leetcode.com/tag/https://leetcode.com/tag/tree//), [Depth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/depth-first-search//), [Binary Search Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-search-tree//), [Binary Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-tree//)

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**).”

**Example 1:**

![](https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png)

```bash
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png)

```bash
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
```

**Example 3:**

```bash
Input: root = [2,1], p = 2, q = 1
Output: 2
```

**Constraints:**

* The number of nodes in the tree is in the range [2, 10<sup>5</sup>].
* -10<sup>9</sup> <= Node.val <= 10<sup>9</sup>
* All `Node.val` are **unique**.
* `p != q`
* `p` and `q` will exist in the BST.

## Hints/Notes

* It's binary serach tree, we can use the property of this data structure

## Solution

Language: **C++**

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int val1 = min(p->val, q->val);
        int val2 = max(p->val, q->val);

        return find(root, val1, val2);
    }

    TreeNode* find(TreeNode* root, int val1, int val2) {
        if (root == nullptr) return root;

        if (root->val == val1 || root->val == val2) {
            return root;
        }

        if (root->val > val1 && root->val < val2) {
            return root;
        }

        TreeNode* left = find(root->left, val1, val2);
        TreeNode* right = find(root->right, val1, val2);

        return left ? left : right;
    }
};
```
