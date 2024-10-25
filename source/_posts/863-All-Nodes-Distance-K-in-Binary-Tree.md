---
title: 863. All Nodes Distance K in Binary Tree
categories: Leetcode
date: 2024-07-09 23:23:30
tags:
    - Hash Table
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Binary Tree
---

[863. All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/)

## Description

Given the `root` of a binary tree, the value of a target node `target`, and an integer `k`, return an array of the values of all nodes that have a distance `k` from the target node.

You can return the answer in **any order**.

**Example 1:**

<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/06/28/sketch0.png" style="width: 500px; height: 429px;">

```bash
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
```

**Example 2:**

```bash
Input: root = [1], target = 1, k = 3
Output: []
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 500]`.
- `0 <= Node.val <= 500`
- All the values `Node.val` are **unique** .
- `target` is the value of one of the nodes in the tree.
- `0 <= k <= 1000`

## Hints/Notes

- binary tree

## Solution

Language: **C++**

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*, TreeNode*> parent;

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        traverse(root);
        int distance = 0;
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<int> s;
        vector<int> res;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (distance == k) {
                    res.push_back(cur->val);
                }
                s.insert(cur->val);
                if (cur->left && !s.contains(cur->left->val)) {
                    q.push(cur->left);
                }
                if (cur->right && !s.contains(cur->right->val)) {
                    q.push(cur->right);
                }
                if (parent[cur] && !s.contains(parent[cur]->val)) {
                    q.push(parent[cur]);
                }
            }
            distance++;
            if (distance > k) {
                break;
            }
        }
        return res;
    }

    void traverse(TreeNode* root) {
        if (!root) {
            return;
        }
        if (root->left) {
            parent[root->left] = root;
            traverse(root->left);
        }
        if (root->right) {
            parent[root->right] = root;
            traverse(root->right);
        }
    }
};
```
