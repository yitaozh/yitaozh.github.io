---
title: 536. Construct Binary Tree from String
categories: Leetcode
date: 2024-07-11 14:36:28
tags:
    - String
    - Stack
    - Tree
    - Depth-First Search
    - Binary Tree
---

[536. Construct Binary Tree from String](https://leetcode.com/problems/construct-binary-tree-from-string/description/)

## Description

You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the <b>left</b> child node of the parent first if it exists.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/09/02/butree.jpg" style="width: 382px; height: 322px;">

```bash
Input: s = "4(2(3)(1))(6(5))"
Output: [4,2,6,3,1,5]
```

**Example 2:**

```bash
Input: s = "4(2(3)(1))(6(5)(7))"
Output: [4,2,6,3,1,5,7]
```

**Example 3:**

```bash
Input: s = "-4(2(3)(1))(6(5)(7))"
Output: [-4,2,6,3,1,5,7]
```

**Constraints:**

- `0 <= s.length <= 3 * 10^4`
- `s` consists of digits, `'('`, `')'`, and `'-'` only.

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
    TreeNode* str2tree(string s) {
        if (s.empty()) {
            return nullptr;
        }
        int start = s.find_first_of('(');
        if (start == -1)
            start = s.size();
        int val = stoi(s.substr(0, start));
        TreeNode* root = new TreeNode(val);
        if (start == s.size()) {
            return root;
        }
        int parenthesis = 0, i = 0;
        for (i = start; i < s.size(); i++) {
            if (s[i] == '(') {
                parenthesis++;
            } else if (s[i] == ')') {
                parenthesis--;
            }
            if (parenthesis == 0) {
                break;
            }
        }
        // s[start] = '(', s[i] = ')'
        root->left = str2tree(s.substr(start + 1, i - (start + 1)));
        if (i == s.size() - 1) {
            return root;
        }
        // i + 2 since we need to skip the ')' and '('
        root->right = str2tree(s.substr(i + 2, s.size() - 1 - (i + 2)));
        return root;
    }
};
```
