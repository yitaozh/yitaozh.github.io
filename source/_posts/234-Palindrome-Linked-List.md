---
title: 234. Palindrome Linked List
categories: Leetcode
date: 2023-01-17 13:14:25
tags:
    - Linked List
    - Two Pointers
    - Stack
    - Recursion
---

# [234\. Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)

## Description

Difficulty: **Easy**

Related Topics: [Linked List](https://leetcode.com/tag/linked-list/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Stack](https://leetcode.com/tag/stack/), [Recursion](https://leetcode.com/tag/recursion/)

Given the `head` of a singly linked list, return `true` _if it is a_ <span data-keyword="palindrome-sequence">_palindrome_</span> _or_ `false` _otherwise_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg)

```text
Input: head = [1,2,2,1]
Output: true
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg)

```text
Input: head = [1,2]
Output: false
```

**Constraints:**

* The number of nodes in the list is in the range [1, 10<sup>5</sup>].
* `0 <= Node.val <= 9`

**Follow up:** Could you do it in `O(n)` time and `O(1)` space?

## Hints/Notes

* Find the mid point, reverse the right part then compare

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

    bool isPalindrome(ListNode* head) {
        ListNode* left = head, *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) {
            slow = slow->next;
        }
        ListNode* right = reverse(slow);
        while (right) {
            if (left->val != right->val) {
                return false;
            } else {
                right = right->next;
                left = left->next;
            }
        }
        return true;
    }

    ListNode* reverse(ListNode* head) {
        ListNode *cur = head, *prev = nullptr;
        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }

    /* Run time O(N), Space O(N) solution
    ListNode* left;

    bool isPalindrome(ListNode* head) {
        left = head;
        return traverse(head);
    }

    bool traverse(ListNode* right) {
        if (right == nullptr) return true;
        bool res = traverse(right->next);
        res = res && left->val == right->val;
        left = left->next;
        return res;
    }
    */
};
```
