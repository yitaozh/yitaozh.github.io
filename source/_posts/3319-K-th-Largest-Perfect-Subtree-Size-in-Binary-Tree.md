---
title: 3319. K-th Largest Perfect Subtree Size in Binary Tree
categories: Leetcode
date: 2024-10-21 15:22:44
tags:
    - Tree
    - Depth-First Search
    - Sorting
    - Binary Tree
---

[3319. K-th Largest Perfect Subtree Size in Binary Tree](https://leetcode.com/problems/k-th-largest-perfect-subtree-size-in-binary-tree/description/)

## Description

You are given the `root` of a **binary tree**  and an integer `k`.

Return an integer denoting the size of the `k^th` **largest perfect binary**  subtree, or `-1` if it doesn't exist.

A **perfect binary tree**  is a tree where all leaves are on the same level, and every parent has two children.

**Example 1:**

```bash
Input: root = [5,3,6,5,2,5,7,1,8,null,null,6,8], k = 2

Output: 3
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/10/14/tmpresl95rp-1.png" style="width: 400px; height: 173px;">

The roots of the perfect binary subtrees are highlighted in black. Their sizes, in non-increasing order are `[3, 3, 1, 1, 1, 1, 1, 1]`.<br>
The `2^nd` largest size is 3.

**Example 2:**

```bash
Input: root = [1,2,3,4,5,6,7], k = 1

Output: 7
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/10/14/tmp_s508x9e-1.png" style="width: 300px; height: 189px;">

The sizes of the perfect binary subtrees in non-increasing order are `[7, 3, 3, 1, 1, 1, 1]`. The size of the largest perfect binary subtree is 7.

**Example 3:**

```bash
Input: root = [1,2,3,null,4], k = 3

Output: -1
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/10/14/tmp74xnmpj4-1.png" style="width: 250px; height: 225px;">

The sizes of the perfect binary subtrees in non-increasing order are `[1, 1]`. There are fewer than 3 perfect binary subtrees.

**Constraints:**

- The number of nodes in the tree is in the range `[1, 2000]`.
- `1 <= Node.val <= 2000`
- `1 <= k <= 1024`

## Hints/Notes

- priority queue
- Weekly Contest 419

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
    priority_queue<int> pq;

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        traverse(root);
        while (!pq.empty() && k > 0) {
            int val = pq.top();
            pq.pop();
            k--;
            if (k == 0) {
                return val;
            }
        }
        return -1;
    }

    int traverse(TreeNode* root) {
        if (!root) {
            return -1;
        }
        if (!root->left && !root->right) {
            pq.push(1);
            return 1;
        }
        int left = traverse(root->left);
        int right = traverse(root->right);
        if (left == right) {
            int res = left + right + 1;
            pq.push(res);
            return res;
        } else {
            return -1;
        }
    }
};
```
