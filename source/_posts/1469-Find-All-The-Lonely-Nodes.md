---
title: 1469. Find All The Lonely Nodes
categories: Leetcode
date: 2024-05-30 12:37:46
tags:
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Binary Tree
---

# [1469. Find All The Lonely Nodes](https://leetcode.com/problems/find-all-the-lonely-nodes/description/)

In a binary tree, a **lonely**  node is a node that is the only child of its parent node. The root of the tree is not lonely because it does not have a parent node.

Given the `root` of a binary tree, return an array containing the values of all lonely nodes in the tree. Return the list **in any order** .

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/06/03/e1.png" style="width: 203px; height: 202px;">

```bash
Input: root = [1,2,3,null,4]
Output: [4]
Explanation: Light blue node is the only lonely node.
Node 1 is the root and is not lonely.
Nodes 2 and 3 have the same parent and are not lonely.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/06/03/e2.png" style="width: 442px; height: 282px;">

```bash
Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2]
Output: [6,2]
Explanation: Light blue nodes are lonely nodes.
Please remember that order doesn't matter, [2,6] is also an acceptable answer.
```

**Example 3:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/06/03/tree.png" style="width: 363px; height: 202px;">

```bash
Input:  root = [11,99,88,77,null,null,66,55,null,null,44,33,null,null,22]
Output: [77,55,33,66,44,22]
Explanation: Nodes 99 and 88 share the same parent. Node 11 is the root.
All other nodes are lonely.
```

**Constraints:**

- The number of nodes in the `tree` is in the range `[1, 1000].`
- `1 <= Node.val <= 10^6`

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

    vector<int> getLonelyNodes(TreeNode* root) {
        traverse(root);
        return res;
    }

    void traverse(TreeNode* root) {
        if (!root) {
            return;
        }
        if (root->left && !root->right) {
            res.push_back(root->left->val);
        }

        if (!root->left && root->right) {
            res.push_back(root->right->val);
        }

        traverse(root->left);
        traverse(root->right);
    }
};
```
