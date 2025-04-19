---
title: 1522. Diameter of N-Ary Tree
categories: Leetcode
date: 2025-04-19 02:48:25
tags:
    - Tree
    - Depth-First Search
---

[1522. Diameter of N-Ary Tree](https://leetcode.com/problems/diameter-of-n-ary-tree/description/?envType=company&envId=doordash&favoriteSlug=doordash-more-than-six-months)

## Description

Given a `root` of an `N-ary tree`, you need to compute the length of the diameter of the tree.

The diameter of an N-ary tree is the length of the **longest**  path between any two nodes in the tree. This path may or may not pass through the root.

(Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value.)

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/07/19/sample_2_1897.png" style="width: 324px; height: 173px;">

```bash
Input: root = [1,null,3,2,4,null,5,6]
Output: 3
Explanation: Diameter is shown in red color.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/07/19/sample_1_1897.png" style="width: 253px; height: 246px;">

```bash
Input: root = [1,null,2,null,3,4,null,5,null,6]
Output: 4
```

**Example 3:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/07/19/sample_3_1897.png" style="width: 369px; height: 326px;">

```bash
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: 7
```

**Constraints:**

- The depth of the n-ary tree is less than or equal to `1000`.
- The total number of nodes is between `[1, 10^4]`.

## Hints/Notes

- 2025/04/15 Q3
- dfs
- [Leetcode solution](https://leetcode.com/problems/diameter-of-n-ary-tree/editorial)

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
    int res = 0;

    int diameter(Node* root) {
        dfs(root);
        return res;
    }

    int dfs(Node* root) {
        if (!root) {
            return 0;
        }
        int mx1 = 0, mx2 = 0;
        for (auto& node : root->children) {
            int cur = dfs(node);
            if (cur >= mx1) {
                mx2 = mx1;
                mx1 = cur;
            } else if (cur > mx2) {
                mx2 = cur;
            }
        }
        res = max(res, mx1 + mx2);
        return mx1 + 1;
    }
};
```
