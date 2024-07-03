---
title: 508. Most Frequent Subtree Sum
categories: Leetcode
date: 2024-07-02 23:06:14
tags:
    - Hash Table
    - Tree
    - Depth-First Search
    - Binary Tree
---

[508. Most Frequent Subtree Sum](https://leetcode.com/problems/most-frequent-subtree-sum/description/)

## Description

Given the `root` of a binary tree, return the most frequent **subtree sum** . If there is a tie, return all the values with the highest frequency in any order.

The **subtree sum**  of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/freq1-tree.jpg" style="width: 207px; height: 183px;">

```bash
Input: root = [5,2,-3]
Output: [2,-3,4]
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/freq2-tree.jpg" style="width: 207px; height: 183px;">

```bash
Input: root = [5,2,-5]
Output: [2]
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
    unordered_map<int, int> m;

    vector<int> findFrequentTreeSum(TreeNode* root) {
        traverse(root);
        int maxCount = -1;
        for (auto it : m) {
            maxCount = max(maxCount, it.second);
        }
        vector<int> res;
        for (auto it : m) {
            if (it.second == maxCount) {
                res.push_back(it.first);
            }
        }
        return res;
    }

    int traverse(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int val = root->val;

        val += traverse(root->left);
        val += traverse(root->right);

        m[val]++;
        return val;
    }
};
```
