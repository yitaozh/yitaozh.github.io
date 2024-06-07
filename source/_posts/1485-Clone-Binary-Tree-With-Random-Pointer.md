---
title: 1485. Clone Binary Tree With Random Pointer
categories: Leetcode
date: 2024-06-07 12:24:37
tags:
    - Hash Table
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Binary Tree
---

[1485. Clone Binary Tree With Random Pointer](https://leetcode.com/problems/clone-binary-tree-with-random-pointer/description/)

## Description

A binary tree is given such that each node contains an additional random pointer which could point to any node in the tree or null.

Return a <a href="https://en.wikipedia.org/wiki/Object_copying#Deep_copy" target="_blank">**deep copy** </a> of the tree.

The tree is represented in the same input/output way as normal binary trees where each node is represented as a pair of `[val, random_index]` where:

- `val`: an integer representing `Node.val`
- `random_index`: the index of the node (in the input) where the random pointer points to, or `null` if it does not point to any node.

You will be given the tree in class `Node` and you should return the cloned tree in class `NodeCopy`. `NodeCopy` class is just a clone of `Node` class with the same attributes and constructors.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/06/17/clone_1.png" style="width: 500px; height: 473px;">

```bash
Input: root = [[1,null],null,[4,3],[7,0]]
Output: [[1,null],null,[4,3],[7,0]]
Explanation: The original binary tree is [1,null,4,7].
The random pointer of node one is null, so it is represented as [1, null].
The random pointer of node 4 is node 7, so it is represented as [4, 3] where 3 is the index of node 7 in the array representing the tree.
The random pointer of node 7 is node 1, so it is represented as [7, 0] where 0 is the index of node 1 in the array representing the tree.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/06/17/clone_2.png" style="width: 500px; height: 540px;">

```bash
Input: root = [[1,4],null,[1,0],null,[1,5],[1,5]]
Output: [[1,4],null,[1,0],null,[1,5],[1,5]]
Explanation: The random pointer of a node can be the node itself.
```

**Example 3:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/06/17/clone_3.png" style="width: 500px; height: 426px;">

```bash
Input: root = [[1,6],[2,5],[3,4],[4,3],[5,2],[6,1],[7,0]]
Output: [[1,6],[2,5],[3,4],[4,3],[5,2],[6,1],[7,0]]
```

**Constraints:**

- The number of nodes in the `tree` is in the range `[0, 1000].`
- `1 <= Node.val <= 10^6`

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left),
 * right(right), random(random) {}
 * };
 */

class Solution {
public:
    map<Node*, NodeCopy*> m;

    NodeCopy* copyRandomBinaryTree(Node* root) {
        NodeCopy* copyRoot = copy(root);
        copyRandom(root, copyRoot);
        return copyRoot;
    }

    NodeCopy* copy(Node* root) {
        if (!root) {
            return nullptr;
        }
        NodeCopy* copyRoot = new NodeCopy(root->val);
        m[root] = copyRoot;
        copyRoot->left = copy(root->left);
        copyRoot->right = copy(root->right);
        return copyRoot;
    }

    void copyRandom(Node* root, NodeCopy* copyRoot) {
        if (!root) {
            return;
        }
        copyRoot->random = m[root->random];
        copyRandom(root->left, copyRoot->left);
        copyRandom(root->right, copyRoot->right);
    }
};
```
