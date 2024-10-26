---
title: 742. Closest Leaf in a Binary Tree
categories: Leetcode
date: 2024-07-11 14:27:48
tags:
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Binary Tree
---

[742. Closest Leaf in a Binary Tree](https://leetcode.com/problems/closest-leaf-in-a-binary-tree/description/)

## Description

Given the `root` of a binary tree where every node has **a unique value** and a target integer `k`, return the value of the **nearest leaf node** to the target `k` in the tree.

**Nearest to a leaf** means the least number of edges traveled on the binary tree to reach any leaf of the tree. Also, a node is called a leaf if it has no children.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/06/13/closest1-tree.jpg" style="width: 224px; height: 145px;">

```bash
Input: root = [1,3,2], k = 1
Output: 2
Explanation: Either 2 or 3 is the nearest leaf node to the target of 1.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/06/13/closest2-tree.jpg" style="width: 64px; height: 65px;">

```bash
Input: root = [1], k = 1
Output: 1
Explanation: The nearest leaf node is the root node itself.
```

**Example 3:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/06/13/closest3-tree.jpg" style="width: 464px; height: 384px;">

```bash
Input: root = [1,2,3,4,null,null,null,5,null,6], k = 2
Output: 3
Explanation: The leaf node with value 3 (and not the leaf node with value 6) is nearest to the node with value 2.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 1000]`.
- `1 <= Node.val <= 1000`
- All the values of the tree are **unique** .
- There exist some node in the tree where `Node.val == k`.

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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* target;
    int k_;
    map<TreeNode*, TreeNode*> parent;

    int findClosestLeaf(TreeNode* root, int k) {
        k_ = k;
        traverse(root);
        queue<TreeNode*> q;
        unordered_set<int> visited;
        q.push(target);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* cur = q.front();
                q.pop();
                visited.insert(cur->val);
                if (!cur->left && !cur->right) {
                    return cur->val;
                }
                if (cur->left && !visited.contains(cur->left->val)) {
                    q.push(cur->left);
                }
                if (cur->right && !visited.contains(cur->right->val)) {
                    q.push(cur->right);
                }
                if (parent.contains(cur) &&
                    !visited.contains(parent[cur]->val)) {
                    q.push(parent[cur]);
                }
            }
        }
        return 0;
    }

    void traverse(TreeNode* root) {
        if (!root) {
            return;
        }
        if (root->val == k_) {
            target = root;
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
