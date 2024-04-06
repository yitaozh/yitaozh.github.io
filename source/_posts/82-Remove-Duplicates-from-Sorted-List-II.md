---
title: 82. Remove Duplicates from Sorted List II
categories: Leetcode
date: 2023-11-11 00:42:28
tags:
    - Linked List
    - Two Pointers
---

[82\. Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)

## Description

Difficulty: **Medium**

Related Topics: [Linked List](https://leetcode.com/tag/https://leetcode.com/tag/linked-list//), [Two Pointers](https://leetcode.com/tag/https://leetcode.com/tag/two-pointers//)

Given the `head` of a sorted linked list, _delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list_. Return _the linked list **sorted** as well_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/04/linkedlist1.jpg)

```bash
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/01/04/linkedlist2.jpg)

```bash
Input: head = [1,1,1,2,3]
Output: [2,3]
```

**Constraints:**

* The number of nodes in the list is in the range `[0, 300]`.
* `-100 <= Node.val <= 100`
* The list is guaranteed to be **sorted** in ascending order.

## Hints/Notes

* two pointers

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        ListNode *p = &dummy, *q = head;
        while (q) {
            if (q->next && q->val == q->next->val) {
                while (q->next && q->val == q->next->val) {
                    q = q->next;
                }
                if (!q->next) {
                    p->next = nullptr;
                }
                q = q->next;
            } else {
                p->next = q;
                p = p->next;
                q = q->next;
            }
        }
        return dummy.next;
    }
};
```
