---
title: 24. Swap Nodes in Pairs
categories: Leetcode
date: 2025-03-14 02:25:00
tags:
    - Linked List
    - Recursion
---

[24. Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/description/)

## Description

Given alinked list, swap every two adjacent nodes and return its head. You must solve the problem withoutmodifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

**Example 1:**

```bash
Input: head = [1,2,3,4]

Output: [2,1,4,3]
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg" style="width: 422px; height: 222px;">

**Example 2:**

```bash
Input: head = []

Output: []
```

**Example 3:**

```bash
Input: head = [1]

Output: [1]
```

**Example 4:**

```bash
Input: head = [1,2,3]

Output: [2,1,3]
```

**Constraints:**

- The number of nodes in thelistis in the range `[0, 100]`.
- `0 <= Node.val <= 100`

## Hints/Notes

- 2025/03/09 Q1
- linked list
- [0x3F's solution](https://leetcode.cn/problems/swap-nodes-in-pairs/solutions/2374872/tu-jie-die-dai-di-gui-yi-zhang-tu-miao-d-51ap/)

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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = &dummy;
        while (cur->next && cur->next->next) {
            ListNode* prev = cur;
            ListNode* next1 = cur->next;
            ListNode* next2 = cur->next->next;
            ListNode* next = next2->next;
            prev->next = next2;
            next2->next = next1;
            next1->next = next;
            cur = next1;
        }
        return dummy.next;
    }
};
```
