---
title: 1019. Next Greater Node In Linked List
categories: Leetcode
date: 2023-12-15 21:48:13
tags:
    - Array
    - Linked List
    - Stack
    - Monotonic Stack
---

# [1019\. Next Greater Node In Linked List](https://leetcode.com/problems/next-greater-node-in-linked-list/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Linked List](https://leetcode.com/tag/https://leetcode.com/tag/linked-list//), [Stack](https://leetcode.com/tag/https://leetcode.com/tag/stack//), [Monotonic Stack](https://leetcode.com/tag/https://leetcode.com/tag/monotonic-stack//)

You are given the `head` of a linked list with `n` nodes.

For each node in the list, find the value of the **next greater node**. That is, for each node, find the value of the first node that is next to it and has a **strictly larger** value than it.

Return an integer array `answer` where `answer[i]` is the value of the next greater node of the i<sup>th</sup> node (**1-indexed**). If the i<sup>th</sup> node does not have a next greater node, set `answer[i] = 0`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/08/05/linkedlistnext1.jpg)

```bash
Input: head = [2,1,5]
Output: [5,5,0]
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/08/05/linkedlistnext2.jpg)

```bash
Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]
```

**Constraints:**

* The number of nodes in the list is `n`.
* 1 <= n <= 10<sup>4</sup>
* 1 <= Node.val <= 10<sup>9</sup>

## Hints/Notes

* stack

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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        stack<int> s;
        vector<int> res(nums.size(), 0);
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!s.empty() && (s.top() <= nums[i])) {
                s.pop();
            }
            res[i] = s.empty() ? 0 : s.top();
            s.push(nums[i]);
        }
        return res;
    }
};
```
