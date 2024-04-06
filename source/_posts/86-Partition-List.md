---
title: 86. Partition List
categories: Leetcode
date: 2023-01-03 11:59:35
tags:
    - Linked List
    - Two Pointers
---

[86\. Partition List](https://leetcode.com/problems/partition-list/)

## Description

Difficulty: **Medium**

Related Topics: [Linked List](https://leetcode.com/tag/linked-list/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

Given the `head` of a linked list and a value `x`, partition it such that all nodes **less than** `x` come before nodes **greater than or equal** to `x`.

You should **preserve** the original relative order of the nodes in each of the two partitions.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/04/partition.jpg)

```bash
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
```

**Example 2:**

```bash
Input: head = [2,1], x = 2
Output: [1,2]
```

**Constraints:**

* The number of nodes in the list is in the range `[0, 200]`.
* `-100 <= Node.val <= 100`
* `-200 <= x <= 200`

---

## Hints/Notes

* Use two lists
* Break the link after the node is added to a new list

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
            // break the next link, otherwise the p2 may link to previous
            // content(resulting in circle)
            ListNode* tmp = p->next;
            p->next = nullptr;
            p = tmp;
        }
        p1->next = dummy2->next;
        return dummy1->next;
    }
};
```
