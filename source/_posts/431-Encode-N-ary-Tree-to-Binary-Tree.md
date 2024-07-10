---
title: 431. Encode N-ary Tree to Binary Tree
categories: Leetcode
date: 2024-07-09 23:21:03
tags:
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Design
    - Binary Tree
---

[431. Encode N-ary Tree to Binary Tree](https://leetcode.com/problems/encode-n-ary-tree-to-binary-tree/description/)

## Description

Design an algorithm to encode an N-ary tree into a binary tree and decode the binary tree to get the original N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. Similarly, a binary tree is a rooted tree in which each node has no more than 2 children. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that an N-ary tree can be encoded to a binary tree and this binary tree can be decoded to the original N-nary tree structure.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See following example).

For example, you may encode the following `3-ary` tree to a binary tree in this way:

<img src="https://assets.leetcode.com/uploads/2018/10/12/narytreebinarytreeexample.png" style="width: 100%; max-width: 640px;">

```bash
Input: root = [1,null,3,2,4,null,5,6]
```

Note that the above is just an example which might or might not work. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

**Example 1:**

```bash
Input: root = [1,null,3,2,4,null,5,6]
Output: [1,null,3,2,4,null,5,6]
```

**Example 2:**

```bash
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
```

**Example 3:**

```bash
Input: root = []
Output: []
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `0 <= Node.val <= 10^4`
- The height of the n-ary tree is less than or equal to `1000`
- Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.

## Hints/Notes

- the N-ary tree to binary tree algorithm

## Solution

Language: **C++**

```C++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (!root) {
            return nullptr;
        }
        TreeNode* head = new TreeNode(root->val);
        TreeNode *left = nullptr, *prev = nullptr;
        for (Node* node : root->children) {
            TreeNode* child = encode(node);
            if (!left) {
                left = child;
            }
            if (prev) {
                prev->right = child;
            }
            prev = child;
        }
        head->left = left;
        return head;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        Node* head = new Node(root->val);
        TreeNode* left = root->left;
        while (left) {
            Node* child = decode(left);
            head->children.push_back(child);
            left = left->right;
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));
```
