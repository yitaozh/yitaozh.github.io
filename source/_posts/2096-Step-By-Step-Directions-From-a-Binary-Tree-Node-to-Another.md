---
title: 2096. Step-By-Step Directions From a Binary Tree Node to Another
categories: Leetcode
date: 2025-04-06 16:14:21
tags:
    - String
    - Tree
    - Depth-First Search
    - Binary Tree
---

[2096. Step-By-Step Directions From a Binary Tree Node to Another](https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-six-months)

## Description

You are given the `root` of a **binary tree**  with `n` nodes. Each node is uniquely assigned a value from `1` to `n`. You are also given an integer `startValue` representing the value of the start node `s`, and a different integer `destValue` representing the value of the destination node `t`.

Find the **shortest path**  starting from node `s` and ending at node `t`. Generate step-by-step directions of such path as a string consisting of only the **uppercase**  letters `'L'`, `'R'`, and `'U'`. Each letter indicates a specific direction:

- `'L'` means to go from a node to its **left child**  node.
- `'R'` means to go from a node to its **right child**  node.
- `'U'` means to go from a node to its **parent**  node.

Return the step-by-step directions of the **shortest path**  from node `s` to node `t`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/11/15/eg1.png" style="width: 214px; height: 163px;">

```bash
Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"
Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/11/15/eg2.png" style="width: 74px; height: 102px;">

```bash
Input: root = [2,1], startValue = 2, destValue = 1
Output: "L"
Explanation: The shortest path is: 2 → 1.
```

**Constraints:**

- The number of nodes in the tree is `n`.
- `2 <= n <= 10^5`
- `1 <= Node.val <= n`
- All the values in the tree are **unique** .
- `1 <= startValue, destValue <= n`
- `startValue != destValue`

## Hints/Notes

- 2025/04/06 Q2
- LCA + DFS
- [0x3F's solution](https://leetcode.cn/problems/step-by-step-directions-from-a-binary-tree-node-to-another/solutions/1139430/bfs-zuo-fa-by-endlesscheng-dfcf/)

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
    // steps:
    //  1. find LCA
    //  2. getPath to start and destValue

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = findLCA(root, startValue, destValue);
        string toStart, toDest;
        calPath(lca, startValue, toStart);
        calPath(lca, destValue, toDest);
        reverse(toDest.begin(), toDest.end());
        int n = toStart.size();
        return string(n, 'U') + toDest;
    }

    TreeNode* calPath(TreeNode* root, int val, string& path) {
        if (!root) {
            return nullptr;
        }
        if (root->val == val) {
            return root;
        }
        TreeNode* left = calPath(root->left, val, path);
        TreeNode* right = calPath(root->right, val, path);
        if (left) {
            path.push_back('L');
        } else if (right) {
            path.push_back('R');
        }
        return left ? left : right;
    }

    TreeNode* findLCA(TreeNode* root, int startVal, int destVal) {
        if (!root) {
            return nullptr;
        }
        if (root->val == startVal || root->val == destVal) {
            return root;
        }
        TreeNode* left = findLCA(root->left, startVal, destVal);
        TreeNode* right = findLCA(root->right, startVal, destVal);
        if (left && right) {
            return root;
        }
        return left ? left : right;
    }
};
```
