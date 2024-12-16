---
title: 2. Add Two Numbers
categories: Leetcode
date: 2024-12-16 12:16:04
tags:
    - Linked List
    - Math
    - Recursion
---

[2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/description/?envType=problem-list-v2&envId=plakya4j&)

## Description

You are given two **non-empty**  linked lists representing two non-negative integers. The digits are stored in **reverse order** , and each of their nodes contains a single digit. Add the two numbers and return the sumas a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg" style="width: 483px; height: 342px;">

```bash
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
```

**Example 2:**

```bash
Input: l1 = [0], l2 = [0]
Output: [0]
```

**Example 3:**

```bash
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
```

**Constraints:**

- The number of nodes in each linked list is in the range `[1, 100]`.
- `0 <= Node.val <= 9`
- It is guaranteed that the list represents a number that does not have leading zeros.

## Hints/Notes

- 2024/12/14
- linked list
- [0x3F's solution](https://leetcode.cn/problems/add-two-numbers/solutions/2327008/dong-hua-jian-ji-xie-fa-cong-di-gui-dao-oe0di/)

## Solution

Language: **C++**

Recursive:

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int prev = 0) {
        if (!l1 && !l2) {
            return prev ? new ListNode(prev) : nullptr;
        }
        if (!l1) {
            swap(l1, l2);
        }
        int sum = l1->val + (l2 ? l2->val : 0) + prev;
        ListNode* node = new ListNode(sum % 10);
        node->next = addTwoNumbers(l1->next, l2 ? l2->next : l2, sum / 10);
        return node;
    }
};
```

Iterative:

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* head = &dummy;
        int prev = 0;
        while (l1 || l2 || prev) {
            if (l1) {
                prev += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                prev += l2->val;
                l2 = l2->next;
            }
            head->next = new ListNode(prev % 10);
            prev /= 10;
            head = head->next;
        }
        return dummy.next;
    }
};
```
