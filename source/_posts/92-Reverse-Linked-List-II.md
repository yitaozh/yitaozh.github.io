---
title: 92. Reverse Linked List II
categories: Leetcode
date: 2023-01-04 16:23:04
tags:
    - Linked List
---

# [92\. Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/)

## Description

Difficulty: **Medium**

Related Topics: [Linked List](https://leetcode.com/tag/linked-list/)

Given the `head` of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the list from position `left` to position `right`, and return _the reversed list_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/19/rev2ex2.jpg)

```text
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
```

**Example 2:**

```text
Input: head = [5], left = 1, right = 1
Output: [5]
```

**Constraints:**

* The number of nodes in the list is `n`.
* `1 <= n <= 500`
* `-500 <= Node.val <= 500`
* `1 <= left <= right <= n`

**Follow up:** Could you do it in one pass?

## Hints/Notes

* Implement reverseN first

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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1) {
            return reverseN(head, right);
        }
        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }

    ListNode* reverseN(ListNode* head, int n) {
        if (n == 1) {
            next = head->next;
            return head;
        }
        ListNode* tmpHead = reverseN(head->next, n - 1);
        head->next->next = head;
        // in fact, this step is only useful for the first node
        head->next = next;
        return tmpHead;
    }

    ListNode* next = nullptr;
};
```
