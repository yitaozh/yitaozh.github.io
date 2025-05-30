---
title: 1474. Delete N Nodes After M Nodes of a Linked List
categories: Leetcode
date: 2025-05-30 17:21:57
tags:
    - Linked List
---

[1474. Delete N Nodes After M Nodes of a Linked List](https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/description/?envType=weekly-question&envId=2025-05-29)

## Description

You are given the <code>head</code> of a linked list and two integers <code>m</code> and <code>n</code>.

Traverse the linked list and remove some nodes in the following way:

- Start with the head as the current node.
- Keep the first <code>m</code> nodes starting with the current node.
- Remove the next <code>n</code> nodes
- Keep repeating steps 2 and 3 until you reach the end of the list.

Return the head of the modified list after removing the mentioned nodes.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/06/06/sample_1_1848.png" style="width: 600px; height: 95px;">

```bash
Input: head = [1,2,3,4,5,6,7,8,9,10,11,12,13], m = 2, n = 3
Output: [1,2,6,7,11,12]
Explanation: Keep the first (m = 2) nodes starting from the head of the linked List  (1 ->2) show in black nodes.
Delete the next (n = 3) nodes (3 -> 4 -> 5) show in read nodes.
Continue with the same procedure until reaching the tail of the Linked List.
Head of the linked list after removing nodes is returned.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/06/06/sample_2_1848.png" style="width: 600px; height: 123px;">

```bash
Input: head = [1,2,3,4,5,6,7,8,9,10,11], m = 1, n = 3
Output: [1,5,9]
Explanation: Head of linked list after removing nodes is returned.
```

**Constraints:**

- The number of nodes in the list is in the range <code>[1, 10^4]</code>.
- <code>1 <= Node.val <= 10^6</code>
- <code>1 <= m, n <= 1000</code>

**Follow up:**  Could you solve this problem by modifying the list in-place?

## Hints/Notes

- 2025/05/09 Q1
- linked list
- [Leetcode solution](https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/editorial)

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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* p = &dummy;
        int k = 0;
        while (p->next && k < m) {
            p = p->next;
            k++;
        }
        if (!p->next) {
            return head;
        }
        ListNode* tail = p;
        k = 0;
        while (p->next && k < n) {
            p = p->next;
            k++;
        }
        tail->next = deleteNodes(p->next, m, n);
        return head;
    }
};
```
