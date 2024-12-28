---
title: 124. Binary Tree Maximum Path Sum
categories: Leetcode
date: 2024-06-19 23:00:34
tags:
    - Dynamic Programming
    - Tree
    - Depth-First Search
    - Binary Tree
---

[124. Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/description/)

## Description

A **path**  in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence **at most once** . Note that the path does not need to pass through the root.

The **path sum**  of a path is the sum of the node's values in the path.

Given the `root` of a binary tree, return the maximum **path sum**  of any **non-empty**  path.

**Example 1:**
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/13/exx1.jpg" style="width: 322px; height: 182px;">

```bash
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
```

**Example 2:**
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/13/exx2.jpg">

```bash
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 3 * 10^4]`.
- `-1000 <= Node.val <= 1000`

## Hints/Notes

- 2024/04/25
- binary tree
- [0x3F's solution](https://leetcode.cn/problems/binary-tree-maximum-path-sum/solutions/2227021/shi-pin-che-di-zhang-wo-zhi-jing-dpcong-n9s91/)(checked)

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
    int res = INT_MIN;

    int maxPathSum(TreeNode* root) {
        traverse(root);

        return res;
    }

    int traverse(TreeNode* root) {
        int ans = 0;
        if (!root) {
            return ans;
        }

        ans += root->val;

        int left = traverse(root->left);
        int right = traverse(root->right);

        res = max(res, root->val + left + right);

        ans += max(left, right);

        return max(0, ans);
    }
};
```
