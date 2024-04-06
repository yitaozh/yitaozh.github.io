---
title: 83. Remove Duplicates from Sorted List
categories: Leetcode
date: 2023-01-17 13:34:54
tags:
    - Linked List
---

[83\. Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

## Description

Difficulty: **Easy**

Related Topics: [Linked List](https://leetcode.com/tag/linked-list/)

Given the `head` of a sorted linked list, _delete all duplicates such that each element appears only once_. Return _the linked list **sorted** as well_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/04/list1.jpg)

```bash
Input: head = [1,1,2]
Output: [1,2]
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/01/04/list2.jpg)

```bash
Input: head = [1,1,2,3,3]
Output: [1,2,3]
```

**Constraints:**

* The number of nodes in the list is in the range `[0, 300]`.
* `-100 <= Node.val <= 100`
* The list is guaranteed to be **sorted** in ascending order.

## Hints/Notes

* Fast/slow pointers

```C++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        return nullptr;
    }
}
```

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* slow = head, *fast = head;
        while (fast) {
            while (fast && fast->val == slow->val) {
                fast = fast->next;
            }
            slow->next = fast;
            slow = slow->next;
        }
        return head;
    }
};
```
