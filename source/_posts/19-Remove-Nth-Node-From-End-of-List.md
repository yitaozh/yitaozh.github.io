---
title: 19. Remove Nth Node From End of List
categories: Leetcode
date: 2023-01-03 13:29:10
tags:
    - Linked List
    - Two Pointers
---

## Solution

```cpp
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *nth = findFromEnd(dummy, n + 1);
        nth->next = nth->next->next;
        return dummy->next;
    }

    ListNode* findFromEnd(ListNode* head, int n) {
        ListNode *p1 = head, *p2 = head;
        for (int i = 0; i < n; i++) {
            p1 = p1->next;
        }
        while (p1) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};
```