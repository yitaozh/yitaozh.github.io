---
title: 1161. Maximum Level Sum of a Binary Tree
categories: Leetcode
date: 2024-07-08 23:25:31
tags:
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Binary Tree
---

[1161. Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/)

## Description

Given the `root` of a binary tree, the level of its root is `1`, the level of its children is `2`, and so on.

Return the **smallest**  level `x` such that the sum of all the values of nodes at level `x` is **maximal** .

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/05/03/capture.JPG" style="width: 200px; height: 175px;">

```bash
Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation:
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
```

**Example 2:**

```bash
Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-10^5 <= Node.val <= 10^5`

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
    int maxLevelSum(TreeNode* root) {
        map<int, int> m;
        queue<TreeNode*> q;
        if (root)
            q.push(root);
        int level = 1;
        while (!q.empty()) {
            int n = q.size(), sum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* cur = q.front();
                q.pop();
                sum += cur->val;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            if (!m.contains(sum)) {
                m[sum] = level;
            }
            level++;
        }
        return m.rbegin()->second;
    }
};
```
