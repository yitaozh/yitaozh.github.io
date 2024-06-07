---
title: 1490. Clone N-ary Tree
categories: Leetcode
date: 2024-06-07 12:26:02
tags:
    - Hash Table
    - Tree
    - Depth-First Search
    - Breadth-First Search
---

[1490. Clone N-ary Tree](https://leetcode.com/problems/clone-n-ary-tree/description/)

## Description

Given a `root` of an N-ary tree, return a <a href="https://en.wikipedia.org/wiki/Object_copying#Deep_copy" target="_blank">**deep copy** </a> (clone) of the tree.

Each node in the n-ary tree contains a val (`int`) and a list (`List[Node]`) of its children.

```C++
class Node {
    public int val;
    public List<Node> children;
}
```

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

**Example 1:**

<img src="https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png" style="width: 100%; max-width: 300px;">

```bash
Input: root = [1,null,3,2,4,null,5,6]
Output: [1,null,3,2,4,null,5,6]
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png" style="width: 296px; height: 241px;">

```bash
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
```

**Constraints:**

- The depth of the n-ary tree is less than or equal to `1000`.
- The total number of nodes is between `[0, 10^4]`.

**Follow up:** Can your solution work for the <a href="https://leetcode.com/problems/clone-graph/" target="_blank">graph problem</a>?

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

class Solution {
public:
    Node* cloneTree(Node* root) {
        if (!root) {
            return nullptr;
        }
        Node* newRoot = new Node(root->val);
        for (auto child : root->children) {
            newRoot->children.push_back(cloneTree(child));
        }
        return newRoot;
    }
};
```
