---
title: 206. Reverse Linked List
categories: Leetcode
date: 2023-01-04 13:09:46
tags:
    - Linked List
    - Recursion
---

# [206\. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)

## Description

Difficulty: **Easy**

Related Topics: [Linked List](https://leetcode.com/tag/linked-list/), [Recursion](https://leetcode.com/tag/recursion/)

Given the `head` of a singly linked list, reverse the list, and return _the reversed list_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg)

```text
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg)

```text
Input: head = [1,2]
Output: [2,1]
```

**Example 3:**

```text
Input: head = []
Output: []
```

**Constraints:**

* The number of nodes in the list is the range `[0, 5000]`.
* `-5000 <= Node.val <= 5000`

**Follow up:** A linked list can be reversed either iteratively or recursively. Could you implement both?

## Hints/Notes

* For recursive solution, only think how to handle then end case and how to handle a new tail
* For iterative solution, use stack

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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        // this is only useful for the head as well
        head->next = nullptr;
        return newHead;
    }
};
```
