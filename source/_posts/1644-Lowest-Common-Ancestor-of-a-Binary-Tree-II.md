---
title: 1644. Lowest Common Ancestor of a Binary Tree II
categories: Leetcode
date: 2023-08-29 14:17:57
tags:
    - Tree
    - Depth-First Search
    - Binary Tree
---

# [1644\. Lowest Common Ancestor of a Binary Tree II](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/)

## Description

Difficulty: **Medium**

Related Topics: [Tree](https://leetcode.com/tag/https://leetcode.com/tag/tree//), [Depth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/depth-first-search//), [Binary Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-tree//)

Given the `root` of a binary tree, return _the lowest common ancestor (LCA) of two given nodes,_ `p` _and_ `q`. If either node `p` or `q` **does not exist** in the tree, return `null`. All values of the nodes in the tree are **unique**.

According to the **[definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor)**: "The lowest common ancestor of two nodes `p` and `q` in a binary tree `T` is the lowest node that has both `p` and `q` as **descendants** (where we allow **a node to be a descendant of itself**)". A **descendant** of a node `x` is a node `y` that is on the path from node `x` to some leaf node.

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
Explanation: The LCA of nodes 5 and 4 is 5\. A node can be a descendant of itself according to the definition of LCA.
```

**Example 3:**

![](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

```bash
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 10
Output: null
Explanation: Node 10 does not exist in the tree, so return null.
```

**Constraints:**

* The number of nodes in the tree is in the range [1, 10<sup>4</sup>].
* -10<sup>9</sup> <= Node.val <= 10<sup>9</sup>
* All `Node.val` are **unique**.
* `p != q`

**Follow up:** Can you find the LCA traversing the tree, without checking nodes existence?

## Solution

Language: **C++**

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool foundP = false, foundQ = false;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = find(root, p, q);

        if (!foundP || !foundQ) {
            return nullptr;
        }

        return res;
    }

    TreeNode* find(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return root;

        TreeNode* left = find(root->left, p, q);
        TreeNode* right = find(root->right, p, q);

        if (root == p) {
            foundP = true;
            return root;
        }

        if (root == q) {
            foundQ = true;
            return root;
        }

        if (left && right) {
            return root;
        }

        return left ? left : right;
    }
};
```
