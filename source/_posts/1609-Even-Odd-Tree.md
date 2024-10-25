---
title: 1609. Even Odd Tree
categories: Leetcode
date: 2024-07-08 23:28:50
tags:
    - Tree
    - Breadth-First Search
    - Binary Tree
---

[1609. Even Odd Tree](https://leetcode.com/problems/even-odd-tree/description/)

## Description

A binary tree is named **Even-Odd**  if it meets the following conditions:

- The root of the binary tree is at level index `0`, its children are at level index `1`, their children are at level index `2`, etc.
- For every **even-indexed**  level, all nodes at the level have **odd**  integer values in **strictly increasing**  order (from left to right).
- For every <b>odd-indexed</b> level, all nodes at the level have <b>even</b> integer values in **strictly decreasing**  order (from left to right).

Given the `root` of a binary tree, return `true` if the binary tree is **Even-Odd** , otherwise return `false`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/09/15/sample_1_1966.png" style="width: 362px; height: 229px;">

```bash
Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
Output: true
Explanation: The node values on each level are:
Level 0: [1]
Level 1: [10,4]
Level 2: [3,7,9]
Level 3: [12,8,6,2]
Since levels 0 and 2 are all odd and increasing and levels 1 and 3 are all even and decreasing, the tree is Even-Odd.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/09/15/sample_2_1966.png" style="width: 363px; height: 167px;">

```bash
Input: root = [5,4,2,3,3,7]
Output: false
Explanation: The node values on each level are:
Level 0: [5]
Level 1: [4,2]
Level 2: [3,3,7]
Node values in level 2 must be in strictly increasing order, so the tree is not Even-Odd.
```

**Example 3:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/09/22/sample_1_333_1966.png" style="width: 363px; height: 167px;">

```bash
Input: root = [5,9,1,3,5,7]
Output: false
Explanation: Node values in the level 1 should be even integers.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^5]`.
- `1 <= Node.val <= 10^6`

## Hints/Notes

- binary tree

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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        int m = 1;
        queue<TreeNode*> q;
        if (root)
            q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int val = m ? INT_MIN : INT_MAX;
            for (int i = 0; i < n; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->val % 2 != m) {
                    return false;
                }
                if (m && cur->val <= val) {
                    return false;
                }
                if (!m && cur->val >= val) {
                    return false;
                }
                val = cur->val;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            m ^= 1;
        }
        return true;
    }
};
```
