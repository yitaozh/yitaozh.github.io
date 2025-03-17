---
title: 61. Rotate List
categories: Leetcode
date: 2025-03-17 02:05:34
tags:
    - Linked List
    - Two Pointers
---

[61. Rotate List](https://leetcode.com/problems/rotate-list/description/?envType=company&envId=linkedin&favoriteSlug=linkedin-three-months)

## Description

Given the `head` of a linkedlist, rotate the list to the right by `k` places.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/rotate1.jpg" style="width: 450px; height: 191px;">

```bash
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/roate2.jpg" style="width: 305px; height: 350px;">

```bash
Input: head = [0,1,2], k = 4
Output: [2,0,1]
```

**Constraints:**

- The number of nodes in the list is in the range `[0, 500]`.
- `-100 <= Node.val <= 100`
- `0 <= k <= 2 * 10^9`

## Hints/Notes

- 2025/02/14 Q2
- linked list
- [Leetcode solution](https://leetcode.com/problems/rotate-list/editorial/?envType=company&envId=linkedin&favoriteSlug=linkedin-three-months)

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return head;
        }
        int n = 1;
        ListNode* cur = head;
        while (cur->next) {
            n++;
            cur = cur->next;
        }
        ListNode* old_tail = cur;
        k = k % n;
        if (!k) {
            return head;
        }
        k = n - k - 1;
        cur = head;
        while (k) {
            k--;
            cur = cur->next;
        }
        ListNode* newHead = cur->next;
        cur->next = nullptr;
        old_tail->next = head;
        return newHead;
    }
};
```
