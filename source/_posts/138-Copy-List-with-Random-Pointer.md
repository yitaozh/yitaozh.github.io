---
title: 138. Copy List with Random Pointer
categories: Leetcode
date: 2023-12-18 18:04:43
tags:
    - Hash Table
    - Linked List
---

[138\. Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/)

## Description

Difficulty: **Medium**

Related Topics: [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [Linked List](https://leetcode.com/tag/https://leetcode.com/tag/linked-list//)

A linked list of length `n` is given such that each node contains an additional random pointer, which could point to any node in the list, or `null`.

Construct a [**deep copy**](https://en.wikipedia.org/wiki/Object_copying#Deep_copy) of the list. The deep copy should consist of exactly `n` **brand new** nodes, where each new node has its value set to the value of its corresponding original node. Both the `next` and `random` pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. **None of the pointers in the new list should point to nodes in the original list**.

For example, if there are two nodes `X` and `Y` in the original list, where `X.random --> Y`, then for the corresponding two nodes `x` and `y` in the copied list, `x.random --> y`.

Return _the head of the copied linked list_.

The linked list is represented in the input/output as a list of `n` nodes. Each node is represented as a pair of `[val, random_index]` where:

* `val`: an integer representing `Node.val`
* `random_index`: the index of the node (range from `0` to `n-1`) that the `random` pointer points to, or `null` if it does not point to any node.

Your code will **only** be given the `head` of the original linked list.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/12/18/e1.png)

```bash
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2019/12/18/e2.png)

```bash
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
```

**Example 3:**

**![](https://assets.leetcode.com/uploads/2019/12/18/e3.png)**

```bash
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
```

**Constraints:**

* `0 <= n <= 1000`
* -10<sup>4</sup> <= Node.val <= 10<sup>4</sup>
* `Node.random` is `null` or is pointing to some node in the linked list.

## Hints/Notes

* 2023/12/18
* map
* [0x3F's solution](https://leetcode.cn/problems/copy-list-with-random-pointer/solutions/2993775/bu-yong-ha-xi-biao-de-zuo-fa-pythonjavac-nzdo/)(checked)

## Solution

Language: **C++**

O(1) space solution

```C++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        Node* p = head;
        while (p) {
            p->next = new Node(p->val, p->next, nullptr);
            p = p->next->next;
        }
        p = head;
        while (p) {
            if (p->random) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
        p = head;
        Node* newHead = head->next;
        while (p->next->next) {
            Node* nxt = p->next;
            p->next = p->next->next;
            p = p->next;
            nxt->next = p->next;
        }
        p->next = nullptr;
        return newHead;
    }
};
```

```C++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> m;
        Node* p = head;
        while (p) {
            Node* tmp = new Node(p->val);
            m[p] = tmp;
            p = p->next;
        }
        p = head;
        while (p) {
            Node* curr = m[p];
            Node* next = m[p->next];
            Node* rand = m[p->random];
            curr->next = next;
            curr->random = rand;
            p = p->next;
        }
        return head ? m[head] : nullptr;
    }
};
```
