---
title: 971. Flip Binary Tree To Match Preorder Traversal
categories: Leetcode
date: 2024-05-24 17:01:13
tags:
    - Tree
    - Depth-First Search
    - Binary Tree
---

[971. Flip Binary Tree To Match Preorder Traversal](https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/description/)

You are given the `root` of a binary tree with `n` nodes, where each node is uniquely assigned a value from `1` to `n`. You are also given a sequence of `n` values `voyage`, which is the **desired**  <a href="https://en.wikipedia.org/wiki/Tree_traversal#Pre-order" target="_blank">**pre-order traversal** </a> of the binary tree.

Any node in the binary tree can be **flipped**  by swapping its left and right subtrees. For example, flipping node 1 will have the following effect:

<img alt="" src="https://assets.leetcode.com/uploads/2021/02/15/fliptree.jpg" style="width: 400px; height: 187px;">

Flip the **smallest**  number of nodes so that the **pre-order traversal**  of the tree **matches**  `voyage`.

Return a list of the values of all **flipped**  nodes. You may return the answer in **any order** . If it is **impossible**  to flip the nodes in the tree to make the pre-order traversal match `voyage`, return the list `[-1]`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/01/02/1219-01.png" style="width: 150px; height: 205px;">

```bash
Input: root = [1,2], voyage = [2,1]
Output: [-1]
Explanation: It is impossible to flip the nodes such that the pre-order traversal matches voyage.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/01/02/1219-02.png" style="width: 150px; height: 142px;">

```bash
Input: root = [1,2,3], voyage = [1,3,2]
Output: [1]
Explanation: Flipping node 1 swaps nodes 2 and 3, so the pre-order traversal matches voyage.
```

**Example 3:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/01/02/1219-02.png" style="width: 150px; height: 142px;">

```bash
Input: root = [1,2,3], voyage = [1,2,3]
Output: []
Explanation: The tree's pre-order traversal already matches voyage, so no nodes need to be flipped.
```

**Constraints:**

- The number of nodes in the tree is `n`.
- `n == voyage.length`
- `1 <= n <= 100`
- `1 <= Node.val, voyage[i] <= n`
- All the values in the tree are **unique** .
- All the values in `voyage` are **unique** .

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
    vector<int> res;
    bool possible = true;
    int index = 0;

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        flip(root, voyage);
        if (!possible) {
            res = {-1};
        }
        return res;
    }

    void flip(TreeNode* root, vector<int>& voyage) {
        if (!root || index == voyage.size() || !possible) {
            return;
        }
        if (root->val != voyage[index]) {
            possible = false;
            return;
        }
        index++;
        if (root->left && voyage[index] != root->left->val) {
            res.push_back(root->val);
            TreeNode* tmp = root->left;
            root->left = root->right;
            root->right = tmp;
        }
        flip(root->left, voyage);
        flip(root->right, voyage);
    }
};
```
