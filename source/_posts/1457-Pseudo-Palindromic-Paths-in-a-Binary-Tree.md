---
title: 1457. Pseudo-Palindromic Paths in a Binary Tree
categories: Leetcode
date: 2024-04-03 16:55:24
tags:
    - Bit Manipulation
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Binary Tree
---

# [1457. Pseudo-Palindromic Paths in a Binary Tree](https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/)

Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be **pseudo-palindromic**  if at least one permutation of the node values in the path is a palindrome.

Return the number of **pseudo-palindromic**  paths going from the root node to leaf nodes.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/05/06/palindromic_paths_1.png" style="width: 300px; height: 201px;">

```bash
Input: root = [2,3,1,3,1,null,1]
Output: 2
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).
```

**Example 2:**

**<img alt="" src="https://assets.leetcode.com/uploads/2020/05/07/palindromic_paths_2.png" style="width: 300px; height: 314px;">**

```bash
Input: root = [2,1,1,1,3,null,null,null,null,null,1]
Output: 1
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).
```

**Example 3:**

```bash
Input: root = [9]
Output: 1
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^5]`.
- `1 <= Node.val <= 9`

## Hints/Notes

- traverse the tree

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
    int count[10] = {0};
    int res = 0;

    int pseudoPalindromicPaths (TreeNode* root) {
        if (!root) {
            return res;
        }
        count[root->val]++;
        if (!root->left && !root->right) {
            int odd_count = 0;
            for (int i = 0; i < 10; i++) {
                if (count[i] % 2 == 1) {
                    odd_count++;
                }
            }
            if (odd_count <= 1) {
                res++;
            }
        }
        if (root->left) pseudoPalindromicPaths(root->left);
        if (root->right) pseudoPalindromicPaths(root->right);
        count[root->val]--;
        return res;
    }
};
```
