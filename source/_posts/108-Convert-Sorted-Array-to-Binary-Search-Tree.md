---
title: 108. Convert Sorted Array to Binary Search Tree
categories: Leetcode
date: 2024-07-13 01:45:20
tags:
    - Array
    - Divide and Conquer
    - Tree
    - Binary Search Tree
    - Binary Tree
---

[108. Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/)

## Description

Given an integer array `nums` where the elements are sorted in **ascending order** , convert it to a **height-balanced** binary search tree.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/02/18/btree1.jpg" style="width: 302px; height: 222px;">

```bash
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
```

Explanation: [0,-10,5,null,-3,null,9] is also accepted:

<img alt="" src="https://assets.leetcode.com/uploads/2021/02/18/btree2.jpg" style="width: 302px; height: 222px;">

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/02/18/btree.jpg" style="width: 342px; height: 142px;">

```bash
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
```

**Constraints:**

- `1 <= nums.length <= 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` is sorted in a **strictly increasing**  order.

## Hints/Notes

- 2024/07/05
- binary search tree
- No solution from 0x3F

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return nullptr;
        }
        int mid = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        if (mid >= 1) {
            vector<int> l = vector<int>(nums.begin(), nums.begin() + mid);
            root->left = sortedArrayToBST(l);
        }
        if (nums.size() - 1 >= mid + 1) {
            vector<int> r = vector<int>(nums.begin() + mid + 1, nums.end());
            root->right = sortedArrayToBST(r);
        }
        return root;
    }
};
```
