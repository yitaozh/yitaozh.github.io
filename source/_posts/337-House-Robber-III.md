---
title: 337. House Robber III
categories: Leetcode
date: 2025-03-20 00:46:05
tags:
    - Dynamic Programming
    - Tree
    - Depth-First Search
    - Binary Tree
---

[337. House Robber III](https://leetcode.com/problems/house-robber-iii/description/)

## Description

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called `root`.

Besides the `root`, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if **two directly-linked houses were broken into on the same night** .

Given the `root` of the binary tree, return the maximum amount of money the thief can rob **without alerting the police** .

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/03/10/rob1-tree.jpg" style="width: 277px; height: 293px;">

```bash
Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/03/10/rob2-tree.jpg" style="width: 357px; height: 293px;">

```bash
Input: root = [3,4,5,1,3,null,1]
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `0 <= Node.val <= 10^4`

## Hints/Notes

- 2025/02/24 Q2
- tree dp
- [Leetcode solution](https://leetcode.com/problems/house-robber-iii/editorial/)

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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, vector<int>> dp;

    int rob(TreeNode* root) {
        int res = max(dfs(root, 0), dfs(root, 1));
        return res;
    }

    int dfs(TreeNode* root, int select) {
        if (!root) {
            return 0;
        }
        if (!dp.contains(root)) {
            dp[root] = {-1, -1};
        }
        if (dp[root][select] != -1) {
            return dp[root][select];
        }
        int res = select ? root->val : 0;
        if (!select) {
            // if the current node is not selected previously, several choices here:
            // 1. select both left + right
            // 2. select only left/right
            // 3. select neither left nor right
            int left = max(dfs(root->left, 1), dfs(root->left, 0));
            int right = max(dfs(root->right, 1), dfs(root->right, 0));
            res = res + left + right;
        } else {
            // we cannot select left and right
            res = res + dfs(root->left, 0) + dfs(root->right, 0);
        }
        dp[root][select] = res;
        return res;
    }
};
```
