---
title: 1676. Lowest Common Ancestor of a Binary Tree IV
categories: Leetcode
date: 2023-08-29 14:01:12
tags:
    - Tree
    - Depth-First Search
    - Binary Tree
---

# [1676\. Lowest Common Ancestor of a Binary Tree IV](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/)

## Description

Difficulty: **Medium**

Related Topics: [Tree](https://leetcode.com/tag/https://leetcode.com/tag/tree//), [Depth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/depth-first-search//), [Binary Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-tree//)

Given the `root` of a binary tree and an array of `TreeNode` objects `nodes`, return _the lowest common ancestor (LCA) of **all the nodes** in_ `nodes`. All the nodes will exist in the tree, and all values of the tree's nodes are **unique**.

Extending the **[definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor)**: "The lowest common ancestor of `n` nodes p<sub>1</sub>, p<sub>2</sub>, ..., p<sub>n</sub> in a binary tree `T` is the lowest node that has every p<sub>i</sub> as a **descendant** (where we allow **a node to be a descendant of itself**) for every valid `i`". A **descendant** of a node `x` is a node `y` that is on the path from node `x` to some leaf node.

**Example 1:**

![](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

```bash
Input: root = [3,5,1,6,2,0,8,null,null,7,4], nodes = [4,7]
Output: 2
Explanation: The lowest common ancestor of nodes 4 and 7 is node 2.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

```bash
Input: root = [3,5,1,6,2,0,8,null,null,7,4], nodes = [1]
Output: 1
Explanation: The lowest common ancestor of a single node is the node itself.

```

**Example 3:**

![](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

```bash
Input: root = [3,5,1,6,2,0,8,null,null,7,4], nodes = [7,6,2,4]
Output: 5
Explanation: The lowest common ancestor of the nodes 7, 6, 2, and 4 is node 5.
```

**Constraints:**

* The number of nodes in the tree is in the range [1, 10<sup>4</sup>].
* -10<sup>9</sup> <= Node.val <= 10<sup>9</sup>
* All `Node.val` are **unique**.
* All `nodes[i]` will exist in the tree.
* All `nodes[i]` are distinct.

## Hints/Notes

* Since every node exists, we can just return when we find the first item in the list
* It's the same as find the LCA of two nodes

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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        set<TreeNode*> values(nodes.begin(), nodes.end());
        return find(root, values);
    }

    TreeNode* find(TreeNode* root, set<TreeNode*> &values) {
        if (root == nullptr) return root;

        if (values.contains(root)) {
            return root;
        }

        TreeNode* left = find(root->left, values);
        TreeNode* right = find(root->right, values);
        
        if (left && right) return root;

        return left ? left : right;
    }
};
```
