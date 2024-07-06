---
title: 1339. Maximum Product of Splitted Binary Tree
categories: Leetcode
date: 2024-07-05 23:30:12
tags:
    - Tree
    - Depth-First Search
    - Binary Tree
---

[1339. Maximum Product of Splitted Binary Tree](https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/)

## Description

Given the `root` of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it **modulo**  `10^9 + 7`.

**Note**  that you need to maximize the answer before taking the mod and not after taking it.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/01/21/sample_1_1699.png" style="width: 500px; height: 167px;">

```bash
Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/01/21/sample_2_1699.png" style="width: 500px; height: 211px;">

```bash
Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)
```

**Constraints:**

- The number of nodes in the tree is in the range `[2, 5 * 10^4]`.
- `1 <= Node.val <= 10^4`

## Hints/Notes

- N/A

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
    vector<int> sums;

    int maxProduct(TreeNode* root) {
        int sum = traverse(root);
        long long mx = 0;
        for (int s : sums) {
            mx = max(mx, (long long)s * (sum - s));
        }
        int mod = 1e9 + 7;
        return mx % mod;
    }

    int traverse(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int l = traverse(root->left);
        int r = traverse(root->right);

        int sum = l + r + root->val;
        sums.push_back(sum);
        return sum;
    }
};
```
