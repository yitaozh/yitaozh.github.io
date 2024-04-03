---
title: 988. Smallest String Starting From Leaf
categories: Leetcode
date: 2024-04-03 16:01:13
tags:
    - String
    - Tree
    - Depth-First Search
    - Binary Tree
---

# [988. Smallest String Starting From Leaf](https://leetcode.com/problems/smallest-string-starting-from-leaf/description/)

You are given the `root` of a binary tree where each node has a value in the range `[0, 25]` representing the letters `'a'` to `'z'`.

Return the **lexicographically smallest**  string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is **lexicographically smaller** .

- For example, `"ab"` is lexicographically smaller than `"aba"`.

A leaf of a node is a node that has no children.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/01/30/tree1.png" style="width: 534px; height: 358px;">

```bash
Input: root = [0,1,2,3,4,3,4]
Output: "dba"
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/01/30/tree2.png" style="width: 534px; height: 358px;">

```bash
Input: root = [25,1,3,1,3,0,2]
Output: "adz"
```

**Example 3:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/02/01/tree3.png" style="height: 490px; width: 468px;">

```bash
Input: root = [2,2,1,null,1,0,null,0]
Output: "abc"
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 8500]`.
- `0 <= Node.val <= 25`

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
    string res;

    string smallestFromLeaf(TreeNode* root) {
        traverse(root, "");
        return res;
    }

    void traverse(TreeNode* root, string cur) {
        if (!root) {
            return;
        }
        cur = char(root->val + 'a') + cur;
        if (!root->left && !root->right) {
            if (res == "" || res > cur) {
                res = cur;
            }
        }
        if (root->left) traverse(root->left, cur);
        if (root->right) traverse(root->right, cur);
    }
};
```
