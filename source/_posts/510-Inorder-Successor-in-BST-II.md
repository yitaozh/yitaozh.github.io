---
title: 510. Inorder Successor in BST II
categories: Leetcode
date: 2024-07-13 01:37:31
tags:
    - Tree
    - Binary Search Tree
    - Binary Tree
---

[510. Inorder Successor in BST II](https://leetcode.com/problems/inorder-successor-in-bst-ii/description/)

## Description

Given a `node` in a binary search tree, return the in-order successor of that node in the BST. If that node has no in-order successor, return `null`.

The successor of a `node` is the node with the smallest key greater than `node.val`.

You will have direct access to the node but not to the root of the tree. Each node will have a reference to its parent node. Below is the definition for `Node`:

```C++
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
```

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/01/23/285_example_1.PNG" style="width: 122px; height: 117px;">

```bash
Input: tree = [2,1,3], node = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both the node and the return value is of Node type.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/01/23/285_example_2.PNG" style="width: 246px; height: 229px;">

```bash
Input: tree = [5,3,6,2,4,null,null,1], node = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer is null.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-10^5 <= Node.val <= 10^5`
- All Nodes will have unique values.

**Follow up:**  Could you solve it without looking up any of the node's values?

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (!node) {
            return node;
        }
        if (node->right) {
            Node* cur = node->right;
            while (cur->left) {
                cur = cur->left;
            }
            return cur;
        }

        if (node->parent) {
            while (node->parent && node->parent->right == node) {
                node = node->parent;
            }
            if (node->parent) {
                return node->parent;
            }
        }
        return nullptr;
    }
};
```
