---
title: >-
  1430. Check If a String Is a Valid Sequence from Root to Leaves Path in a
  Binary Tree
categories: Leetcode
date: 2024-07-01 23:28:09
tags:
  - Tree
  - Depth-First Search
  - Breadth-First Search
  - Binary Tree
---

[1430. Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree](https://leetcode.com/problems/check-if-a-string-is-a-valid-sequence-from-root-to-leaves-path-in-a-binary-tree/description/)

## Description

Given a binary tree where each path going from the root to any leaf form a **valid sequence** , check if a given string is a **valid sequence**  in such binary tree.

We get the given string from the concatenation of an array of integers `arr` and the concatenation of all values of the nodes along a path results in a **sequence**  in the given binary tree.

**Example 1:**

**<img alt="" src="https://assets.leetcode.com/uploads/2019/12/18/leetcode_testcase_1.png" style="width: 333px; height: 250px;">**

```bash
Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,0,1]
Output: true

Explanation:
The path 0 -> 1 -> 0 -> 1 is a valid sequence (green color in the figure).
Other valid sequences are:
0 -> 1 -> 1 -> 0
0 -> 0 -> 0
```

**Example 2:**

**<img alt="" src="https://assets.leetcode.com/uploads/2019/12/18/leetcode_testcase_2.png" style="width: 333px; height: 250px;">**

```bash
Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,0,1]
Output: false
Explanation: The path 0 -> 0 -> 1 does not exist, therefore it is not even a sequence.
```

**Example 3:**

**<img alt="" src="https://assets.leetcode.com/uploads/2019/12/18/leetcode_testcase_3.png" style="width: 333px; height: 250px;">**

```bash
Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,1]
Output: false
Explanation: The path 0 -> 1 -> 1 is a sequence, but it is not a valid sequence.
```

**Constraints:**

- `1 <= arr.length <= 5000`
- `0 <= arr[i] <= 9`
- Each node's value is between [0 - 9].

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
    bool isValid = false;

    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        traverse(root, arr, 0);
        return isValid;
    }

    void traverse(TreeNode* root, vector<int>& arr, int index) {
        if (!root || index == arr.size() || isValid) {
            return;
        }

        if (root->val != arr[index]) {
            return;
        }

        if (!root->left && !root->right && index == arr.size() - 1) {
            isValid = true;
            return;
        }

        traverse(root->left, arr, index + 1);
        traverse(root->right, arr, index + 1);
    }
};
```
