---
title: 143. Reorder List
categories: Leetcode
date: 2023-12-07 22:06:29
tags:
    - Linked List
    - Two Pointers
    - Stack
    - Recursion
---

[143\. Reorder List](https://leetcode.com/problems/reorder-list/)

## Description

Difficulty: **Medium**

Related Topics: [Linked List](https://leetcode.com/tag/https://leetcode.com/tag/linked-list//), [Two Pointers](https://leetcode.com/tag/https://leetcode.com/tag/two-pointers//), [Stack](https://leetcode.com/tag/https://leetcode.com/tag/stack//), [Recursion](https://leetcode.com/tag/https://leetcode.com/tag/recursion//)

You are given the head of a singly linked-list. The list can be represented as:

```bash
L0 → L1 → … → Ln - 1 → Ln
```

_Reorder the list to be on the following form:_

```bash
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
```

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/04/reorder1linked-list.jpg)

```bash
Input: head = [1,2,3,4]
Output: [1,4,2,3]
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/03/09/reorder2-linked-list.jpg)

```bash
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
```

**Constraints:**

* The number of nodes in the list is in the range [1, 5 * 10<sup>4</sup>].
* `1 <= Node.val <= 1000`

## Hints/Notes

* stack

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
class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        ListNode* tmp = head;
        while (tmp) {
            s.push(tmp);
            tmp = tmp->next;
        }
        tmp = head;
        while (tmp != s.top() && tmp->next != s.top()) {
            ListNode* tail = s.top();
            s.pop();
            ListNode* next = tmp->next;
            tmp->next = tail;
            tail->next = next;
            tmp = next;
        }
        if (tmp == s.top()) {
            tmp->next = nullptr;
        } else {
            tmp->next->next = nullptr;
        }
    }
};
```
