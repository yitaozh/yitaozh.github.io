---
title: 86. Partition List
categories: Leetcode
date: 2023-01-03 11:59:35
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode();
        ListNode* dummy2 = new ListNode();
        ListNode *p1 = dummy1, *p2 = dummy2, *p = head;
        while (p) {
            if (p->val >= x) {
                p2->next = p;
                p2 = p2->next;
            } else {
                p1->next = p;
                p1 = p1->next;
            }
            ListNode* tmp = p->next;
            p->next = nullptr;
            p = tmp;
        }
        p1->next = dummy2->next;
        return dummy1->next;
    }
};
```