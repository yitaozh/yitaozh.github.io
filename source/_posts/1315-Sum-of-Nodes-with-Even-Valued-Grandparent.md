---
title: 1315. Sum of Nodes with Even-Valued Grandparent
categories: Leetcode
date: 2024-05-30 12:33:19
tags:
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Binary Tree
---

[1315. Sum of Nodes with Even-Valued Grandparent](https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/description/)

Given the `root` of a binary tree, return the sum of values of nodes with an **even-valued grandparent** . If there are no nodes with an **even-valued grandparent** , return `0`.

A **grandparent**  of a node is the parent of its parent if it exists.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/08/10/even1-tree.jpg" style="width: 504px; height: 302px;">

```bash
Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 18
Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/08/10/even2-tree.jpg" style="width: 64px; height: 65px;">

```bash
Input: root = [1]
Output: 0
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `1 <= Node.val <= 100`

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
    int res = 0;

    int sumEvenGrandparent(TreeNode* root) {
        traverse(root);
        return res;
    }

    void traverse(TreeNode* root) {
        if (!root) {
            return;
        }
        if (root->val % 2 == 0) {
            if (root->left) {
                res += root->left->left ? root->left->left->val : 0;
                res += root->left->right ? root->left->right->val : 0;
            }

            if (root->right) {
                res += root->right->left ? root->right->left->val : 0;
                res += root->right->right ? root->right->right->val : 0;
            }
        }

        traverse(root->left);
        traverse(root->right);
    }
};
```
