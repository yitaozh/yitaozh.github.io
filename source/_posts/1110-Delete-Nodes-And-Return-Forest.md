---
title: 1110. Delete Nodes And Return Forest
categories: Leetcode
date: 2024-06-07 12:23:15
tags:
    - Array
    - Hash Table
    - Tree
    - Depth-First Search
    - Binary Tree
---

[1110. Delete Nodes And Return Forest](https://leetcode.com/problems/delete-nodes-and-return-forest/description/)

## Description

Given the `root` of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in `to_delete`, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/07/01/screen-shot-2019-07-01-at-53836-pm.png" style="width: 237px; height: 150px;">

```bash
Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]
```

**Example 2:**

```bash
Input: root = [1,2,4,null,3], to_delete = [3]
Output: [[1,2,4]]
```

**Constraints:**

- The number of nodes in the given tree is at most `1000`.
- Each node has a distinct value between `1` and `1000`.
- `to_delete.length <= 1000`
- `to_delete` contains distinct values between `1` and `1000`.

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
    set<int> s;
    vector<TreeNode*> res;

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        s = set<int>(to_delete.begin(), to_delete.end());
        deleteNode(root, s, false);
        return res;
    }

    TreeNode* deleteNode(TreeNode* root, set<int>& s, bool hasParent) {
        if (!root) {
            return root;
        }
        bool deleted = s.contains(root->val);
        if (!deleted && !hasParent) {
            res.push_back(root);
        }
        root->left = deleteNode(root->left, s, !deleted);
        root->right = deleteNode(root->right, s, !deleted);
        return deleted ? nullptr : root;
    }
};
```
