---
title: 622. Design Circular Queue
categories: Leetcode
date: 2023-12-15 18:37:33
tags:
    - Array
    - Linked List
    - Design
    - Queue
---

[622\. Design Circular Queue](https://leetcode.com/problems/design-circular-queue/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Linked List](https://leetcode.com/tag/https://leetcode.com/tag/linked-list//), [Design](https://leetcode.com/tag/https://leetcode.com/tag/design//), [Queue](https://leetcode.com/tag/https://leetcode.com/tag/queue//)

Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle, and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Implement the `MyCircularQueue` class:

* `MyCircularQueue(k)` Initializes the object with the size of the queue to be `k`.
* `int Front()` Gets the front item from the queue. If the queue is empty, return `-1`.
* `int Rear()` Gets the last item from the queue. If the queue is empty, return `-1`.
* `boolean enQueue(int value)` Inserts an element into the circular queue. Return `true` if the operation is successful.
* `boolean deQueue()` Deletes an element from the circular queue. Return `true` if the operation is successful.
* `boolean isEmpty()` Checks whether the circular queue is empty or not.
* `boolean isFull()` Checks whether the circular queue is full or not.

You must solve the problem without using the built-in queue data structure in your programming language.

**Example 1:**

```bash
Input
["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 3, true, true, true, 4]

Explanation
MyCircularQueue myCircularQueue = new MyCircularQueue(3);
myCircularQueue.enQueue(1); // return True
myCircularQueue.enQueue(2); // return True
myCircularQueue.enQueue(3); // return True
myCircularQueue.enQueue(4); // return False
myCircularQueue.Rear();     // return 3
myCircularQueue.isFull();   // return True
myCircularQueue.deQueue();  // return True
myCircularQueue.enQueue(4); // return True
myCircularQueue.Rear();     // return 4
```

**Constraints:**

* `1 <= k <= 1000`
* `0 <= value <= 1000`
* At most `3000` calls will be made to `enQueue`, `deQueue`, `Front`, `Rear`, `isEmpty`, and `isFull`.

## Hints/Notes

* use pointer or queue

## Solution

Language: **C++**

```bash
class MyCircularQueue {
public:
    struct Node {
        Node* next;
        int val;
        Node(int val) : val(val), next(nullptr) {}
    };

    Node *head, *tail;
    int size_;
    int count_;

    MyCircularQueue(int k) {
        head = nullptr;
        tail = nullptr;
        size_ = k;
        count_ = 0;
    }

    bool enQueue(int value) {
        if (count_ >= size_) {
            return false;
        }
        count_++;
        Node* node = new Node(value);
        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = tail->next;
            tail->next = head;
        }
        return true;
    }

    bool deQueue() {
        if (!head) {
            return false;
        }
        count_--;
        Node* tmp = head;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
        }
        delete(tmp);
        return true;
    }

    int Front() {
        return head ? head->val : -1;
    }

    int Rear() {
        return tail ? tail->val : -1;
    }

    bool isEmpty() {
        return count_ == 0;
    }

    bool isFull() {
        return count_ == size_;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
```
