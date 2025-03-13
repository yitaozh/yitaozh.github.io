---
title: 1382. Balance a Binary Search Tree
categories: Leetcode
date: 2025-03-13 12:55:24
tags:
    - Divide and Conquer
    - Greedy
    - Tree
    - Depth-First Search
    - Binary Search Tree
    - Binary Tree
---

[1382. Balance a Binary Search Tree](https://leetcode.com/problems/balance-a-binary-search-tree/description/)

## Description

Given the `root` of a binary search tree, return a **balanced**  binary search tree with the same node values. If there is more than one answer, return **any of them** .

A binary search tree is **balanced**  if the depth of the two subtrees of every node never differs by more than `1`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/08/10/balance1-tree.jpg" style="width: 500px; height: 319px;">

```bash
Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
<b>Explanation:</b> This is not the only correct answer, [3,1,4,null,2] is also correct.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/08/10/balanced2-tree.jpg" style="width: 224px; height: 145px;">

```bash
Input: root = [2,1,3]
Output: [2,1,3]
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `1 <= Node.val <= 10^5`

## Hints/Notes

- 2025/03/01 Q2
- BST inorder traversal
- [Leetcode solution](https://leetcode.com/problems/balance-a-binary-search-tree/editorial/)

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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> nodes;

    TreeNode* balanceBST(TreeNode* root) {
        if (!root) {
            return root;
        }
        inorderTraversal(root);

        return buildTree(0, nodes.size() - 1);
    }

    TreeNode* buildTree(int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = (start + end) / 2;
        TreeNode* root = nodes[mid];
        root->left = buildTree(start, mid - 1);
        root->right = buildTree(mid + 1, end);
        return root;
    }

    void inorderTraversal(TreeNode* root) {
        if (root->left) inorderTraversal(root->left);
        nodes.push_back(root);
        if (root->right) inorderTraversal(root->right);
    }
};
```
