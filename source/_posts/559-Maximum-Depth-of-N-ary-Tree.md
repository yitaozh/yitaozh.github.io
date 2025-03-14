---
title: 559. Maximum Depth of N-ary Tree
categories: Leetcode
date: 2025-03-14 12:25:57
tags:
    - Tree
    - Depth-First Search
    - Breadth-First Search
---

[559. Maximum Depth of N-ary Tree](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/)

## Description

Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

**Example 1:**

<img src="https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png" style="width: 100%; max-width: 300px;">

```bash
Input: root = [1,null,3,2,4,null,5,6]
Output: 3
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png" style="width: 296px; height: 241px;">

```bash
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: 5
```

**Constraints:**

- The total number of nodes is in the range `[0, 10^4]`.
- The depth of the n-ary tree is less than or equal to `1000`.

## Hints/Notes

- 2025/03/12 Q2
- tree
- [Leetcode solution](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/editorial/)

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
    int maxDepth(Node* root) {
        return find(root, 1);
    }

    int find(Node* root, int depth) {
        if (!root) {
            return 0;
        }
        int res = depth;
        for (auto child : root->children) {
            res = max(res, find(child, depth + 1));
        }
        return res;
    }
};
```
