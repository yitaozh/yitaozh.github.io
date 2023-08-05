---
title: 21. Merge Two Sorted Lists
date: 2022-12-29 17:57:13
tags:
    - Linked List
    - Recursion
categories: Leetcode
---

# [21\. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)

## Description

Difficulty: **Easy**

Related Topics: [Linked List](https://leetcode.com/tag/linked-list/), [Recursion](https://leetcode.com/tag/recursion/)

You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists in a one **sorted** list. The list should be made by splicing together the nodes of the first two lists.

Return _the head of the merged linked list_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg)

```bash
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
```

**Example 2:**

```bash
Input: list1 = [], list2 = []
Output: []
```

**Example 3:**

```bash
Input: list1 = [], list2 = [0]
Output: [0]
```

**Constraints:**

* The number of nodes in both lists is in the range `[0, 50]`.
* `-100 <= Node.val <= 100`
* Both `list1` and `list2` are sorted in **non-decreasing** order.

---

## Hints/Notes

* Dummy pointer
* Some edge cases: list is empty(prior or after the while loop)

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(); ListNode* p = dummy;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                p->next = list1;
                list1 = list1->next;
            } else {
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        if (list1 != nullptr) {
            p->next = list1;
        } else {
            p->next = list2;
        }
        return dummy->next;
    }
};
```
