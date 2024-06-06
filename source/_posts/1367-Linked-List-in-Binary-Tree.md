---
title: 1367. Linked List in Binary Tree
categories: Leetcode
date: 2024-06-06 12:10:12
tags:
    - Linked List
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Binary Tree
---

[1367. Linked List in Binary Tree](https://leetcode.com/problems/linked-list-in-binary-tree/description/)

## Description

Given a binary tree `root` and a linked list with`head`as the first node.

Return True if all the elements in the linked list starting from the `head` correspond to some downward path connected in the binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.

**Example 1:**

**<img alt="" src="https://assets.leetcode.com/uploads/2020/02/12/sample_1_1720.png" style="width: 220px; height: 280px;">**

```bash
Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Explanation: Nodes in blue form a subpath in the binary Tree.
```

**Example 2:**

**<img alt="" src="https://assets.leetcode.com/uploads/2020/02/12/sample_2_1720.png" style="width: 220px; height: 280px;">**

```bash
Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
```

**Example 3:**

```bash
Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: false
Explanation: There is no path in the binary tree that contains all the elements of the linked list from `head`.
```

**Constraints:**

- The number of nodes in the tree will be in the range `[1, 2500]`.
- The number of nodes in the list will be in the range `[1, 100]`.
- `1 <= Node.val<= 100`for each node in the linked list and binary tree.

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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head) {
            return true;
        }
        if (!root) {
            return false;
        }
        bool ans = false;
        if (head->val == root->val) {
            ans = check(head, root);
        }
        if (ans)
            return true;
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }

    bool check(ListNode* head, TreeNode* root) {
        if (!head) {
            return true;
        }
        if (!root) {
            return false;
        }
        if (root->val != head->val) {
            return false;
        }

        return check(head->next, root->left) || check(head->next, root->right);
    }
};
```
