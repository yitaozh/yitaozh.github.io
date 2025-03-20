---
title: 148. Sort List
categories: Leetcode
date: 2025-03-20 19:02:42
tags:
    - Linked List
    - Two Pointers
    - Divide and Conquer
    - Sorting
    - Merge Sort
---

[148. Sort List](https://leetcode.com/problems/sort-list/description/?envType=study-plan-v2&envId=top-100-liked)

## Description

Given the `head` of a linked list, return the list after sorting it in **ascending order** .

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/09/14/sort_list_1.jpg" style="width: 450px; height: 194px;">

```bash
Input: head = [4,2,1,3]
Output: [1,2,3,4]
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/09/14/sort_list_2.jpg" style="width: 550px; height: 184px;">

```bash
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
```

**Example 3:**

```bash
Input: head = []
Output: []
```

**Constraints:**

- The number of nodes in the list is in the range `[0, 5 * 10^4]`.
- `-10^5 <= Node.val <= 10^5`

**Follow up:**  Can you sort the linked list in `O(n logn)` time and `O(1)` memory (i.e. constant space)?

## Hints/Notes

- 2025/02/25 Q2
- merge sort
- [Leetcode solution](https://leetcode.com/problems/sort-list/editorial/?envType=study-plan-v2&envId=top-100-liked)

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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* head = &dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                head->next = list1;
                list1 = list1->next;
            } else {
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }
        if (list1) {
            head->next = list1;
        } else {
            head->next = list2;
        }
        return dummy.next;
    }

    ListNode* getMid(ListNode* head) {
        ListNode* midPrev = nullptr;
        while (head && head->next) {
            midPrev = (midPrev == nullptr) ? head : midPrev->next;
            head = head->next->next;
        }
        ListNode* mid = midPrev->next;
        midPrev->next = nullptr;
        return mid;
    }
};
```
