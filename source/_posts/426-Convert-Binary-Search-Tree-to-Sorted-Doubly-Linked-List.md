---
title: 426. Convert Binary Search Tree to Sorted Doubly Linked List
categories: Leetcode
date: 2024-06-07 12:18:55
tags:
    - Linked List
    - Stack
    - Tree
    - Depth-First Search
    - Binary Search Tree
    - Binary Tree
    - Doubly-Linked List
---

[426. Convert Binary Search Tree to Sorted Doubly Linked List](https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/description/)

## Description

Convert a **Binary Search Tree**  to a sorted **Circular Doubly-Linked List**  in place.

You can think of the left and right pointers as synonymous to the predecessor and successor pointers in a doubly-linked list. For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.

We want to do the transformation **in place** . After the transformation, the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. You should return the pointer to the smallest element of the linked list.

**Example 1:**

<img src="https://assets.leetcode.com/uploads/2018/10/12/bstdlloriginalbst.png" style="width: 100%; max-width: 300px;">

```bash
Input: root = [4,2,5,1,3]
```

<img src="https://assets.leetcode.com/uploads/2018/10/12/bstdllreturndll.png" style="width: 100%; max-width: 450px;">

```bash
Output: [1,2,3,4,5]

Explanation: The figure below shows the transformed BST. The solid line indicates the successor relationship, while the dashed line means the predecessor relationship.
```

<img src="https://assets.leetcode.com/uploads/2018/10/12/bstdllreturnbst.png" style="width: 100%; max-width: 450px;">

**Example 2:**

```bash
Input: root = [2,1,3]
Output: [1,2,3]
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 2000]`.
- `-1000 <= Node.val <= 1000`
- All the values of the tree are **unique** .

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

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    TreeNode* head = nullptr;

    Node* treeToDoublyList(Node* root) {
        if (!root) {
            return nullptr;
        }
        Node *leftHead = nullptr, *rightHead = nullptr, *leftTail = nullptr,
             *rightTail = nullptr;
        if (root->left) {
            leftHead = treeToDoublyList(root->left);
            leftTail = leftHead->left;
            leftTail->right = root;
            root->left = leftTail;
        } else {
            leftTail = leftHead = root;
        }
        if (root->right) {
            rightHead = treeToDoublyList(root->right);
            rightTail = rightHead->left;
            root->right = rightHead;
            rightHead->left = root;
        } else {
            rightTail = rightHead = root;
        }

        leftHead->left = rightTail;
        rightTail->right = leftHead;
        return leftHead;
    }
};
```
