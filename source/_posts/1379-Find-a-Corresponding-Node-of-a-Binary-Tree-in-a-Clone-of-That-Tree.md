---
title: 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
categories: Leetcode
date: 2024-07-01 23:26:45
tags:
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Binary Tree
---

[1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree](https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/description/)

## Description

Given two binary trees `original` and `cloned` and given a reference to a node `target` in the original tree.

The `cloned` tree is a **copy of**  the `original` tree.

Return a reference to the same node in the `cloned` tree.

**Note**  that you are **not allowed**  to change any of the two trees or the `target` node and the answer **must be**  a reference to a node in the `cloned` tree.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/02/21/e1.png" style="width: 544px; height: 426px;">

```bash
Input: tree = [7,4,3,null,null,6,19], target = 3
Output: 3
Explanation: In all examples the original and cloned trees are shown. The target node is a green node from the original tree. The answer is the yellow node from the cloned tree.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/02/21/e2.png" style="width: 221px; height: 159px;">

```bash
Input: tree = [7], target =  7
Output: 7
```

**Example 3:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/02/21/e3.png" style="width: 459px; height: 486px;">

```bash
Input: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
Output: 4
```

**Constraints:**

- The number of nodes in the `tree` is in the range `[1, 10^4]`.
- The values of the nodes of the `tree` are unique.
- `target` node is a node from the `original` tree and is not `null`.

**Follow up:**  Could you solve the problem if repeated values on the tree are allowed?

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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool found = false;

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned,
                            TreeNode* target) {
        if (original == cloned || found) {
            return nullptr;
        }

        if (cloned->val == target->val) {
            found = true;
            return cloned;
        }

        TreeNode* left = getTargetCopy(original->left, cloned->left, target);
        TreeNode* right = getTargetCopy(original->right, cloned->right, target);
        return left ? left : right;
    }
};
```
