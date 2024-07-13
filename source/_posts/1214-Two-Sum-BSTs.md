---
title: 1214. Two Sum BSTs
categories: Leetcode
date: 2024-07-13 01:44:02
tags:
    - Two Pointers
    - Binary Search
    - Stack
    - Tree
    - Depth-First Search
    - Binary Search Tree
    - Binary Tree
---

[1214. Two Sum BSTs](https://leetcode.com/problems/two-sum-bsts/description/)

## Description

Given the roots of two binary search trees, `root1` and `root2`, return `true` if and only if there is a node in the first tree and a node in the second tree whose values sum up to a given integer `target`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/02/10/ex1.png" style="width: 369px; height: 169px;">

```bash
Input: root1 = [2,1,4], root2 = [1,0,3], target = 5
Output: true
Explanation: 2 and 3 sum up to 5.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/02/10/ex2.png" style="width: 453px; height: 290px;">

```bash
Input: root1 = [0,-10,10], root2 = [5,1,7,0,2], target = 18
Output: false
```

**Constraints:**

- The number of nodes in each tree is in the range `[1, 5000]`.
- `-10^9 <= Node.val, target <= 10^9`

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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<int> v1 = traverse(root1);
        vector<int> v2 = traverse(root2);
        int i = 0, j = v2.size() - 1;
        while (i < v1.size() && j >= 0) {
            int sum = v1[i] + v2[j];
            if (sum == target) {
                return true;
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }

    vector<int> traverse(TreeNode* root) {
        if (!root) {
            return {};
        }
        auto l = traverse(root->left);
        auto r = traverse(root->right);

        l.push_back(root->val);
        l.insert(l.end(), r.begin(), r.end());
        return l;
    }
};
```
