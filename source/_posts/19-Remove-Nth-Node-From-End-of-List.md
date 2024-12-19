---
title: 19. Remove Nth Node From End of List
categories: Leetcode
date: 2023-01-03 13:29:10
tags:
    - Linked List
    - Two Pointers
---

[19\. Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

## Description

Difficulty: **Medium**

Related Topics: [Linked List](https://leetcode.com/tag/linked-list/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

Given the `head` of a linked list, remove the n<sup>th</sup> node from the end of the list and return its head.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg)

```bash
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
```

**Example 2:**

```bash
Input: head = [1], n = 1
Output: []
```

**Example 3:**

```bash
Input: head = [1,2], n = 1
Output: [1]
```

**Constraints:**

* The number of nodes in the list is `sz`.
* `1 <= sz <= 30`
* `0 <= Node.val <= 100`
* `1 <= n <= sz`

**Follow up:** Could you do this in one pass?

---

## Hints/Notes

* 2023/08/01
* Use 2 pointers to get the Nth from the end first, helper function
* Use dummy to avoid the nullptr corner case
* [0x3F's solution](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/solutions/2004057/ru-he-shan-chu-jie-dian-liu-fen-zhong-ga-xpfs/)(checked)

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
