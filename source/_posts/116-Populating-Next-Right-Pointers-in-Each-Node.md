---
title: 116. Populating Next Right Pointers in Each Node
categories: Leetcode
date: 2023-02-03 13:33:55
tags:
    - Linked List
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Binary Tree
---

# [116\. Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)

## Description

Difficulty: **Medium**

Related Topics: [Linked List](https://leetcode.com/tag/linked-list/), [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

You are given a **perfect binary tree** where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

```C++
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to `NULL`.

Initially, all next pointers are set to `NULL`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/02/14/116_sample.png)

```bash
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
```

**Example 2:**

```bash
Input: root = []
Output: []
```

**Constraints:**

* The number of nodes in the tree is in the range [0, 2<sup>12</sup> - 1].
* `-1000 <= Node.val <= 1000`

**Follow-up:**

* You may only use constant extra space.
* The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.

## Solution

Language: **C++**

```C++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        traverse(root->left, root->right);
        return root;
    }

    void traverse(Node* left, Node* right) {
        if (left == nullptr) {
            return;
        }

        left->next = right;

        traverse(left->left, left->right);
        traverse(left->right, right->left);
        traverse(right->left, right->right);
    }
};
```
