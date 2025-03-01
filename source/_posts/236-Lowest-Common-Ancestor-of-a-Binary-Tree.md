---
title: 236. Lowest Common Ancestor of a Binary Tree
categories: Leetcode
date: 2023-08-28 23:32:11
tags:
    - Tree
    - Depth-First Search
    - Binary Tree
---

[236\. Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)

## Description

Difficulty: **Medium**

Related Topics: [Tree](https://leetcode.com/tag/https://leetcode.com/tag/tree//), [Depth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/depth-first-search//), [Binary Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-tree//)

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**).”

**Example 1:**

![](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

```bash
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

```bash
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
```

**Example 3:**

```bash
Input: root = [1,2], p = 1, q = 2
Output: 1
```

**Constraints:**

* The number of nodes in the tree is in the range [2, 10<sup>5</sup>].
* -10<sup>9</sup> <= Node.val <= 10<sup>9</sup>
* All `Node.val` are **unique**.
* `p != q`
* `p` and `q` will exist in the tree.

## Hints/Notes

* 2023/08/28
* think about what we are going to do with each node
* [0x3F's solution](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/solutions/2023872/fen-lei-tao-lun-luan-ru-ma-yi-ge-shi-pin-2r95/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

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
        if (root == nullptr) {
            return nullptr;
        }
        
        if (root->val == p->val || root->val == q->val) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root;

        return left ? left : right; 
    }
};
```
