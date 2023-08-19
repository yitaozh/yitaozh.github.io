---
title: 654. Maximum Binary Tree
categories: Leetcode
date: 2023-07-31 12:58:46
tags:
    - Array
    - Divide and Conquer
    - Stack
    - Tree
    - Monotonic Stack
    - Binary Tree
---

# [654\. Maximum Binary Tree](https://leetcode.com/problems/maximum-binary-tree/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Divide and Conquer](https://leetcode.com/tag/https://leetcode.com/tag/divide-and-conquer//), [Stack](https://leetcode.com/tag/https://leetcode.com/tag/stack//), [Tree](https://leetcode.com/tag/https://leetcode.com/tag/tree//), [Monotonic Stack](https://leetcode.com/tag/https://leetcode.com/tag/monotonic-stack//), [Binary Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-tree//)

You are given an integer array `nums` with no duplicates. A **maximum binary tree** can be built recursively from `nums` using the following algorithm:

1. Create a root node whose value is the maximum value in `nums`.
2. Recursively build the left subtree on the **subarray prefix** to the **left** of the maximum value.
3. Recursively build the right subtree on the **subarray suffix** to the **right** of the maximum value.

Return _the **maximum binary tree** built from_ `nums`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/12/24/tree1.jpg)

```bash
Input: nums = [3,2,1,6,0,5]
Output: [6,3,5,null,2,0,null,null,1]
Explanation: The recursive calls are as follow:
- The largest value in [3,2,1,6,0,5] is 6\. Left prefix is [3,2,1] and right suffix is [0,5].
    - The largest value in [3,2,1] is 3\. Left prefix is [] and right suffix is [2,1].
        - Empty array, so no child.
        - The largest value in [2,1] is 2\. Left prefix is [] and right suffix is [1].
            - Empty array, so no child.
            - Only one element, so child is a node with value 1.
    - The largest value in [0,5] is 5\. Left prefix is [0] and right suffix is [].
        - Only one element, so child is a node with value 0.
        - Empty array, so no child.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/12/24/tree2.jpg)

```bash
Input: nums = [3,2,1]
Output: [3,null,2,null,1]
```

**Constraints:**

* `1 <= nums.length <= 1000`
* `0 <= nums[i] <= 1000`
* All integers in `nums` are **unique**.

## Hints/Notes

* Draw the picture to get ideas
* It's like recursive

## Solution

Language: **C++**

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }

    TreeNode* build(vector<int>& nums, int start, int end) {
        if (start == end) {
            return nullptr;
        }
        int max = INT_MIN, idx = -1;
        for (int i = start; i < end; i++) {
            if (nums[i] > max) {
                max = nums[i];
                idx = i;
            }
        }
        TreeNode* root = new TreeNode(max);
        root->left = build(nums, start, idx);
        root->right = build(nums, idx + 1, end);
        return root;
    }
};
```
