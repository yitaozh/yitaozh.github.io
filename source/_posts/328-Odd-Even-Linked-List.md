---
title: 328. Odd Even Linked List
categories: Leetcode
date: 2025-02-09 17:08:26
tags:
    - Linked List
---

[328. Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given the `head` of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The **first**  node is considered **odd** , and the **second**  node is **even** , and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in `O(1)`extra space complexity and `O(n)` time complexity.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/03/10/oddeven-linked-list.jpg" style="width: 300px; height: 123px;">

```bash
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/03/10/oddeven2-linked-list.jpg" style="width: 500px; height: 142px;">

```bash
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
```

**Constraints:**

- The number of nodes in the linked list is in the range `[0, 10^4]`.
- `-10^6 <= Node.val <= 10^6`

## Hints/Notes

- 2025/02/03 Q1
- linked list
- [Leetcode solution](https://leetcode.com/problems/odd-even-linked-list/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *odd = head, *even = head->next, *evenHead = head->next;
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
```
