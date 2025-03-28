---
title: 653. Two Sum IV - Input is a BST
categories: Leetcode
date: 2025-03-28 00:52:12
tags:
    - Hash Table
    - Two Pointers
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Binary Search Tree
    - Binary Tree
---

[653. Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days)

## Description

Given the `root` of a binary search tree and an integer `k`, return `true` if there exist two elements in the BST such that their sum is equal to `k`, or `false` otherwise.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/09/21/sum_tree_1.jpg" style="width: 400px; height: 229px;">

```bash
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/09/21/sum_tree_2.jpg" style="width: 400px; height: 229px;">

```bash
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-10^4 <= Node.val <= 10^4`
- `root` is guaranteed to be a **valid**  binary search tree.
- `-10^5 <= k <= 10^5`

## Hints/Notes

- 2025/03/27
- bst
- [Leetcode solution](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/editorial/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days)

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

    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        int l = 0, r = inorder.size() - 1;
        while (l < r) {
            if (inorder[l] + inorder[r] == k) {
                return true;
            } else if (inorder[l] + inorder[r] > k) {
                r--;
            } else {
                l++;
            }
        }
        return false;
    }

    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        if (root->left) dfs(root->left);
        inorder.push_back(root->val);
        if (root->right) dfs(root->right);
    }
};
```
