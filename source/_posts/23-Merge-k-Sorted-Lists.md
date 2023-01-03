---
title: 23. Merge k Sorted Lists
categories: Leetcode
date: 2023-01-03 13:08:54
tags:
    - Linked List
    - Divide and Conquer
    - Heap (Priority Queue)
    - Merge Sort
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
#include <queue>

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy = new ListNode();
        if (lists.size() == 0) {
            return dummy->next;
        }
        auto cmp = [](const ListNode* l1, const ListNode* l2) { return l1->val > l2->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for(auto head: lists) {
            if (head) {
                pq.push(head);
            }
        }
        ListNode *p = dummy;
        while (pq.size() != 0) {
            ListNode *tmp = pq.top();
            p->next = tmp;
            p = p->next;
            pq.pop();
            if (tmp->next) {
                pq.push(tmp->next);
            }
        }
        return dummy->next;
    }
};
```