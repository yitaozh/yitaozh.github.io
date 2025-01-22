---
title: 708. Insert into a Sorted Circular Linked List
categories: Leetcode
date: 2025-01-22 01:42:42
tags:
    - Linked List
---

[708. Insert into a Sorted Circular Linked List](https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given a Circular Linked List node, which is sorted in non-descending order, write a function to insert a value `insertVal` into the list such that it remains a sorted circular list. The given node can be a reference to any single node in the list and may not necessarily be the smallest value in the circular list.

If there are multiple suitable places for insertion, you may choose any place to insert the new value. After the insertion, the circular list should remain sorted.

If the list is empty (i.e., the given node is `null`), you should create a new single circular list and return the reference to that single node. Otherwise, you should return the originally given node.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/01/19/example_1_before_65p.jpg" style="width: 250px; height: 149px;"><br>

```bash
Input: head = [3,4,1], insertVal = 2
Output: [3,4,1,2]
```

Explanation: In the figure above, there is a sorted circular list of three elements. You are given a reference to the node with value 3, and we need to insert 2 into the list. The new node should be inserted between node 1 and node 3. After the insertion, the list should look like this, and we should still return node 3.

<img alt="" src="https://assets.leetcode.com/uploads/2019/01/19/example_1_after_65p.jpg" style="width: 250px; height: 149px;">

**Example 2:**

```bash
Input: head = [], insertVal = 1
Output: [1]
```

Explanation: The list is empty (given head is`null`). We create a new single circular list and return the reference to that single node.

**Example 3:**

```bash
Input: head = [1], insertVal = 0
Output: [1,0]
```

**Constraints:**

- The number of nodes in the list is in the range `[0, 5 * 10^4]`.
- `-10^6 <= Node.val, insertVal <= 10^6`

## Hints/Notes

- 2025/01/21
- linked list
- [Leetcode solution](https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            Node* newHead = new Node(insertVal);
            newHead->next = newHead;
            return newHead;
        }
        Node *cur = head->next, *prev = head;
        do {
            bool insert = false;
            if (prev->val <= insertVal && cur->val >= insertVal) {
                insert = true;
            } else if (prev->val > cur->val) {
                if (insertVal >= prev->val || insertVal <= cur->val) {
                    insert = true;
                }
            }
            if (insert) {
                prev->next = new Node(insertVal, cur);
                return head;
            }
            prev = prev->next;
            cur = cur->next;
        } while (prev != head);
        head->next = new Node(insertVal, head->next);
        return head;
    }
};
```

My solution:

```C++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            Node* newHead = new Node(insertVal);
            newHead->next = newHead;
            return newHead;
        }
        Node *cur = head, *maxNode = head;
        int mx = INT_MIN, mi = INT_MAX;
        do {
            if (cur->val > mx) {
                while (cur->val == cur->next->val && cur->next != head) {
                    cur = cur->next;
                }
                mx = cur->val;
                maxNode = cur;
            }
            mi = min(cur->val, mi);
            cur = cur->next;
        } while (cur != head);
        if (insertVal >= mx || insertVal <= mi) {
            Node* tmp = maxNode->next;
            maxNode->next = new Node(insertVal);
            maxNode->next->next = tmp;
        } else {
            while (cur) {
                if (insertVal >= cur->val && insertVal <= cur->next->val) {
                    Node* tmp = cur->next;
                    cur->next = new Node(insertVal);
                    cur->next->next = tmp;
                    break;
                }
                cur = cur->next;
            }
        }
        return head;
    }
};
```
