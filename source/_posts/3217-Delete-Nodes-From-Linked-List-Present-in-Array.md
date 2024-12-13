---
title: 3217. Delete Nodes From Linked List Present in Array
categories: Leetcode
date: 2024-07-23 13:54:59
tags:
    - Array
    - Hash Table
    - Linked List
---

[3217. Delete Nodes From Linked List Present in Array](https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/)

## Description

You are given an array of integers `nums` and the `head` of a linked list. Return the `head` of the modified linked list after **removing**  all nodes from the linked list that have a value that exists in `nums`.

**Example 1:**

```bash
Input: nums = [1,2,3], head = [1,2,3,4,5]

Output: [4,5]
```

Explanation:

**<img alt="" src="https://assets.leetcode.com/uploads/2024/06/11/linkedlistexample0.png" style="width: 400px; height: 66px;">**

Remove the nodes with values 1, 2, and 3.

**Example 2:**

```bash
Input: nums = [1], head = [1,2,1,2,1,2]

Output: [2,2,2]
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/06/11/linkedlistexample1.png" style="height: 62px; width: 450px;">

Remove the nodes with value 1.

**Example 3:**

```bash
Input: nums = [5], head = [1,2,3,4]

Output: [1,2,3,4]
```

Explanation:

**<img alt="" src="https://assets.leetcode.com/uploads/2024/06/11/linkedlistexample2.png" style="width: 400px; height: 83px;">**

No node has value 5.

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^5`
- All elements in `nums` are unique.
- The number of nodes in the given list is in the range `[1, 10^5]`.
- `1 <= Node.val <= 10^5`
- The input is generated such that there is at least one node in the linked list that has a value not present in `nums`.

## Hints/Notes

- 2024/07/20
- Linked list
- [0x3F's solution](https://leetcode.cn/problems/delete-nodes-from-linked-list-present-in-array/solutions/2843071/shao-bing-jie-dian-yi-ci-bian-li-pythonj-imre/)(checked)
- Weekly Contest 406

## Solution

Language: **C++**

Solution 1:

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s(nums.begin(), nums.end());
        ListNode dummy(0);
        ListNode* p = &dummy;
        while (head) {
            if (!s.contains(head->val)) {
                p->next = head;
                p = p->next;
            }
            head = head->next;
        }
        p->next = nullptr;
        return dummy.next;
    }
};
```

Solution 2:

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s(nums.begin(), nums.end());
        ListNode dummy(0);
        dummy.next = head;
        ListNode* tmp = &dummy;
        while (tmp->next) {
            if (s.contains(tmp->next->val)) {
                tmp->next = tmp->next->next;
            } else {
                tmp = tmp->next;
            }
        }
        return dummy.next;
    }
};
```
