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

[23\. Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)

## Description

Difficulty: **Hard**

Related Topics: [Linked List](https://leetcode.com/tag/linked-list/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Merge Sort](https://leetcode.com/tag/merge-sort/)

You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

_Merge all the linked-lists into one sorted linked-list and return it._

**Example 1:**

```bash
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
```

**Example 2:**

```bash
Input: lists = []
Output: []
```

**Example 3:**

```bash
Input: lists = [[]]
Output: []
```

**Constraints:**

* `k == lists.length`
* 0 <= k <= 10<sup>4</sup>
* `0 <= lists[i].length <= 500`
* -10<sup>4</sup> <= `lists[i][j]` <= 10<sup>4</sup>
* `lists[i]` is sorted in **ascending order**.
* The sum of `lists[i].length` will not exceed 10<sup>4</sup>.

---

## Hints/Notes

* cpp priority queue

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
