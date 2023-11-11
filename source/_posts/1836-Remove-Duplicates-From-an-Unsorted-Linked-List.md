---
title: 1836. Remove Duplicates From an Unsorted Linked List
categories: Leetcode
date: 2023-11-11 01:17:33
tags:
    - Hash Table
    - Linked List
---

# [1836\. Remove Duplicates From an Unsorted Linked List](https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/)

## Description

Difficulty: **Medium**

Related Topics: [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [Linked List](https://leetcode.com/tag/https://leetcode.com/tag/linked-list//)

Given the `head` of a linked list, find all the values that appear **more than once** in the list and delete the nodes that have any of those values.

Return _the linked list after the deletions._

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/04/21/tmp-linked-list.jpg)

```bash
Input: head = [1,2,3,2]
Output: [1,3]
Explanation: 2 appears twice in the linked list, so all 2's should be deleted. After deleting all 2's, we are left with [1,3].
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/04/21/tmp-linked-list-1.jpg)

```bash
Input: head = [2,1,1,2]
Output: []
Explanation: 2 and 1 both appear twice. All the elements should be deleted.
```

**Example 3:**

![](https://assets.leetcode.com/uploads/2021/04/21/tmp-linked-list-2.jpg)

```bash
Input: head = [3,2,2,1,3,2,4]
Output: [1,4]
Explanation: 3 appears twice and 2 appears three times. After deleting all 3's and 2's, we are left with [1,4].
```

**Constraints:**

* The number of nodes in the list is in the range [1, 10<sup>5</sup>]
* 1 <= Node.val <= 10<sup>5</sup>

## Hints/Notes

* two pointers

## Solution

Language: **C++**

```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        map<int, int> m;
        ListNode *p = head;
        while (p) {
            m[p->val]++;
            p = p->next;
        }
        ListNode dummy(0); p = &dummy;
        ListNode *q = head;
        while (q) {
            if (m[q->val] > 1) {
                q = q->next;
            } else {
                p->next = q;
                p = p->next;
                q = q->next;
            }
        }
        p->next = nullptr;
        return dummy.next;
    }
};
```
