---
title: 109. Convert Sorted List to Binary Search Tree
categories: Leetcode
date: 2024-07-16 00:05:36
tags:
    - Linked List
    - Divide and Conquer
    - Tree
    - Binary Search Tree
    - Binary Tree
---

[109. Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/)

## Description

Given the `head` of a singly linked list where elements are sorted in **ascending order** , convert it to a **height-balanced** binary search tree.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/08/17/linked.jpg" style="width: 500px; height: 388px;">

```bash
Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
```

**Example 2:**

```bash
Input: head = []
Output: []
```

**Constraints:**

- The number of nodes in `head` is in the range `[0, 2 * 10^4]`.
- `-10^5 <= Node.val <= 10^5`

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* cur;

    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        for (ListNode* p = head; p; p = p->next) {
            len++;
        }
        cur = head;
        return traverse(0, len - 1);
    }

    TreeNode* traverse(int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = (end - start) / 2 + start;
        TreeNode* l = traverse(start, mid - 1);
        TreeNode* root = new TreeNode(cur->val);
        cur = cur->next;
        TreeNode* r = traverse(mid + 1, end);
        root->left = l;
        root->right = r;
        return root;
    }
};
```
