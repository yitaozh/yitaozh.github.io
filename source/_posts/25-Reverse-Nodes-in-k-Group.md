---
title: 25. Reverse Nodes in k-Group
categories: Leetcode
date: 2023-01-06 17:47:44
tags:
    - Linked List
    - Recursion
---

# [25\. Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)

## Description

Difficulty: **Hard**

Related Topics: [Linked List](https://leetcode.com/tag/linked-list/), [Recursion](https://leetcode.com/tag/recursion/)

Given the `head` of a linked list, reverse the nodes of the list `k` at a time, and return _the modified list_.

`k` is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of `k` then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/10/03/reverse_ex1.jpg)

```text
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/10/03/reverse_ex2.jpg)

```text
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
```

**Constraints:**

* The number of nodes in the list is `n`.
* `1 <= k <= n <= 5000`
* `0 <= Node.val <= 1000`

**Follow-up:** Can you solve the problem in `O(1)` extra memory space?

## Hints/Notes

* Recursive

## Solution

Language: **C++**

```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *tail = head;
        for (int i = 0; i < k; i++) {
            if (tail) {
                tail = tail->next;
            } else {
                return head;
            }
        }
        ListNode *newHead = reverse(head, tail);
        head->next = reverseKGroup(tail, k);
        // Note:
        // At first i was trying to do reverseKGroup() first then reverse(), i.e
        //
        // reverseKGroup(tail, k);
        // ListNode *newHead = reverse(head, tail);
        //
        // But it run into problem because the tail has been changed and the afterwards
        // reverse would fail. It's also more complicated to understand than the current
        // implementation, i.e. reverse just return a reversed linked list ending with nullptr
        return newHead;
    }

    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode *cur = head, *pre = nullptr, *tmp = nullptr;
        while (cur != tail) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};
```
