---
title: 114. Flatten Binary Tree to Linked List
categories: Leetcode
date: 2023-02-03 13:53:40
tags:
    - Linked List
    - Stack
    - Tree
    - Depth-First Search
    - Binary Tree
---

# [114\. Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)

## Description

Difficulty: **Medium**

Related Topics: [Linked List](https://leetcode.com/tag/linked-list/), [Stack](https://leetcode.com/tag/stack/), [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

Given the `root` of a binary tree, flatten the tree into a "linked list":

* The "linked list" should use the same `TreeNode` class where the `right` child pointer points to the next node in the list and the `left` child pointer is always `null`.
* The "linked list" should be in the same order as a [**pre-order** **traversal**](https://en.wikipedia.org/wiki/Tree_traversal#Pre-order,_NLR) of the binary tree.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/14/flaten.jpg)

```bash
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
```

**Example 2:**

```bash
Input: root = []
Output: []
```

**Example 3:**

```bash
Input: root = [0]
Output: [0]
```

**Constraints:**

* The number of nodes in the tree is in the range `[0, 2000]`.
* `-100 <= Node.val <= 100`

**Follow up:** Can you flatten the tree in-place (with `O(1)` extra space)?

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
    TreeNode* curr = new TreeNode(-1);

    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        flatten(root->left);
        flatten(root->right);

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        root->left = nullptr;
        root->right = left;
        
        while (root->right != nullptr) {
            root = root->right;
        }
        root->right = right;
    }

};
```
