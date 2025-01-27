---
title: 938. Range Sum of BST
categories: Leetcode
date: 2024-07-01 23:25:25
tags:
    - Tree
    - Depth-First Search
    - Binary Search Tree
    - Binary Tree
---

[938. Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst/description/)

## Description

Given the `root` node of a binary search tree and two integers `low` and `high`, return the sum of values of all nodes with a value in the **inclusive**  range `[low, high]`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/11/05/bst1.jpg" style="width: 400px; height: 222px;">

```bash
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/11/05/bst2.jpg" style="width: 400px; height: 335px;">

```bash
Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 2 * 10^4]`.
- `1 <= Node.val <= 10^5`
- `1 <= low <= high <= 10^5`
- All `Node.val` are **unique** .

## Hints/Notes

- 2024/05/08
- bst
- [0x3F's solution](https://leetcode.cn/problems/range-sum-of-bst/solutions/2653989/jian-ji-xie-fa-pythonjavacgojsrust-by-en-7jw4/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) {
            return 0;
        }
        int res = 0;

        if (root->val >= low && root->val <= high) {
            res += root->val;
        }

        if (root->val > low) {
            res += rangeSumBST(root->left, low, high);
        }

        if (root->val < high) {
            res += rangeSumBST(root->right, low, high);
        }

        return res;
    }
};
```
