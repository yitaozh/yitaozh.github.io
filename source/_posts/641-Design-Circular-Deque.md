---
title: 641. Design Circular Deque
categories: Leetcode
date: 2023-12-15 18:53:34
tags:
    - Array
    - Linked List
    - Design
    - Queue
---

# [641\. Design Circular Deque](https://leetcode.com/problems/design-circular-deque/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Linked List](https://leetcode.com/tag/https://leetcode.com/tag/linked-list//), [Design](https://leetcode.com/tag/https://leetcode.com/tag/design//), [Queue](https://leetcode.com/tag/https://leetcode.com/tag/queue//)

Design your implementation of the circular double-ended queue (deque).

Implement the `MyCircularDeque` class:

* `MyCircularDeque(int k)` Initializes the deque with a maximum size of `k`.
* `boolean insertFront()` Adds an item at the front of Deque. Returns `true` if the operation is successful, or `false` otherwise.
* `boolean insertLast()` Adds an item at the rear of Deque. Returns `true` if the operation is successful, or `false` otherwise.
* `boolean deleteFront()` Deletes an item from the front of Deque. Returns `true` if the operation is successful, or `false` otherwise.
* `boolean deleteLast()` Deletes an item from the rear of Deque. Returns `true` if the operation is successful, or `false` otherwise.
* `int getFront()` Returns the front item from the Deque. Returns `-1` if the deque is empty.
* `int getRear()` Returns the last item from Deque. Returns `-1` if the deque is empty.
* `boolean isEmpty()` Returns `true` if the deque is empty, or `false` otherwise.
* `boolean isFull()` Returns `true` if the deque is full, or `false` otherwise.

**Example 1:**

```bash
Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4
```

**Constraints:**

* `1 <= k <= 1000`
* `0 <= value <= 1000`
* At most `2000` calls will be made to `insertFront`, `insertLast`, `deleteFront`, `deleteLast`, `getFront`, `getRear`, `isEmpty`, `isFull`.

## Hints/Notes

* use pointer or queue

## Solution

Language: **C++**

```C++
class MyCircularDeque {
public:
    struct Node {
        int val;
        Node* prev;
        Node* next;
        Node(int val) : val(val), prev(nullptr), next(nullptr) {}
    };
    int size;
    int count;
    Node* head;
    Node* tail;

    MyCircularDeque(int k) {
        size = k;
        count = 0;
        head = nullptr;
        tail = nullptr;
    }

    bool insertFront(int value) {
        if (count == size) {
            return false;
        }
        count++;
        Node* node = new Node(value);
        if (!head) {
            head = node;
            tail = node;
        } else {
            head->prev = node;
            node->next = head;
            head = head->prev;
        }
        return true;
    }

    bool insertLast(int value) {
        if (count == size) {
            return false;
        }
        count++;
        Node* node = new Node(value);
        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = tail->next;
        }
        return true;
    }

    bool deleteFront() {
        if (!head) {
            return false;
        }
        count--;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            Node* tmp = head;
            head = head->next;
            head->prev = nullptr;
            delete(tmp);
        }
        return true;
    }

    bool deleteLast() {
        if (!tail) {
            return false;
        }
        count--;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            Node* tmp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete(tmp);
        }
        return true;
    }

    int getFront() {
        return head ? head->val : -1;
    }

    int getRear() {
        return tail ? tail->val : -1;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return size == count;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
```
