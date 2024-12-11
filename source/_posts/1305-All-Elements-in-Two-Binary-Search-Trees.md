---
title: 1305. All Elements in Two Binary Search Trees
categories: Leetcode
date: 2024-07-16 00:08:22
tags:
    - Tree
    - Depth-First Search
    - Binary Search Tree
    - Sorting
    - Binary Tree
---

[1305. All Elements in Two Binary Search Trees](https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/)

## Description

Given two binary search trees `root1` and `root2`, return a list containing all the integers from both trees sorted in **ascending**  order.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/12/18/q2-e1.png" style="width: 457px; height: 207px;">

```bash
Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/12/18/q2-e5-.png" style="width: 352px; height: 197px;">

```bash
Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
```

**Constraints:**

- The number of nodes in each tree is in the range `[0, 5000]`.
- `-10^5 <= Node.val <= 10^5`

## Hints/Notes

- 2024/07-08
- get two sorted array first
- no solution fromm 0x3F

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        auto v1 = getNums(root1);
        auto v2 = getNums(root2);
        int idx1 = 0, idx2 = 0;
        vector<int> res;
        while (idx1 < v1.size() || idx2 < v2.size()) {
            if (idx1 == v1.size()) {
                res.push_back(v2[idx2++]);
            } else if (idx2 == v2.size()) {
                res.push_back(v1[idx1++]);
            } else if (v1[idx1] < v2[idx2]) {
                res.push_back(v1[idx1++]);
            } else {
                res.push_back(v2[idx2++]);
            }
        }
        return res;
    }

    vector<int> getNums(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return {};
        }
        res.push_back(root->val);
        auto l = getNums(root->left);
        auto r = getNums(root->right);
        if (!l.empty()) {
            res.insert(res.begin(), l.begin(), l.end());
        }
        if (!r.empty()) {
            res.insert(res.end(), r.begin(), r.end());
        }
        return res;
    }
};
```
