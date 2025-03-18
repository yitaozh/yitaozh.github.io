---
title: 272. Closest Binary Search Tree Value II
categories: Leetcode
date: 2025-03-17 22:50:03
tags:
    - Two Pointers
    - Stack
    - Tree
    - Depth-First Search
    - Binary Search Tree
    - Heap (Priority Queue)
    - Binary Tree
---

[272. Closest Binary Search Tree Value II](https://leetcode.com/problems/closest-binary-search-tree-value-ii/description/?envType=company&envId=linkedin&favoriteSlug=linkedin-three-months)

## Description

Given the `root` of a binary search tree, a `target` value, and an integer `k`, return the `k` values in the BST that are closest to the `target`. You may return the answer in **any order** .

You are **guaranteed**  to have only one unique set of `k` values in the BST that are closest to the `target`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/03/12/closest1-1-tree.jpg" style="width: 292px; height: 302px;">

```bash
Input: root = [4,2,5,1,3], target = 3.714286, k = 2
Output: [4,3]
```

**Example 2:**

```bash
Input: root = [1], target = 0.000000, k = 1
Output: [1]
```

**Constraints:**

- The number of nodes in the tree is `n`.
- `1 <= k <= n <= 10^4`.
- `0 <= Node.val <= 10^9`
- `-10^9 <= target <= 10^9`

**Follow up:**  Assume that the BST is balanced. Could you solve it in less than `O(n)` runtime (where `n = total nodes`)?

## Hints/Notes

- 2025/02/15 Q3
- BST
- [Leetcode solution](https://leetcode.com/problems/closest-binary-search-tree-value-ii/editorial/?envType=company&envId=linkedin&favoriteSlug=linkedin-three-months)

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
    vector<int> inorder;

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        dfs(root);
        int size = inorder.size();
        int closestIdx = 0;
        for (int i = 1; i < size; i++) {
            if (abs(inorder[i] - target) < abs(inorder[closestIdx] - target)) {
                closestIdx = i;
            }
        }
        vector<int> res;
        int left = closestIdx, right = closestIdx + 1;
        // we are looking at (left, right)
        while (right - left - 1 < k) {
            if (left < 0) {
                res.push_back(inorder[right++]);
            } else if (right == size) {
                res.push_back(inorder[left--]);
            } else {
                if (abs(inorder[left] - target) <= abs(inorder[right] - target)) {
                    res.push_back(inorder[left--]);
                } else {
                    res.push_back(inorder[right++]);
                }
            }
        }
        return res;
    }

    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }
};
```
