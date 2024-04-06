---
title: 1670. Design Front Middle Back Queue
categories: Leetcode
date: 2023-12-15 21:16:06
tags:
    - Array
    - Linked List
    - Design
    - Queue
    - Data Stream
---

[1670\. Design Front Middle Back Queue](https://leetcode.com/problems/design-front-middle-back-queue/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Linked List](https://leetcode.com/tag/https://leetcode.com/tag/linked-list//), [Design](https://leetcode.com/tag/https://leetcode.com/tag/design//), [Queue](https://leetcode.com/tag/https://leetcode.com/tag/queue//), [Data Stream](https://leetcode.com/tag/https://leetcode.com/tag/data-stream//)

Design a queue that supports `push` and `pop` operations in the front, middle, and back.

Implement the `FrontMiddleBack` class:

* `FrontMiddleBack()` Initializes the queue.
* `void pushFront(int val)` Adds `val` to the **front** of the queue.
* `void pushMiddle(int val)` Adds `val` to the **middle** of the queue.
* `void pushBack(int val)` Adds `val` to the **back** of the queue.
* `int popFront()` Removes the **front** element of the queue and returns it. If the queue is empty, return `-1`.
* `int popMiddle()` Removes the **middle** element of the queue and returns it. If the queue is empty, return `-1`.
* `int popBack()` Removes the **back** element of the queue and returns it. If the queue is empty, return `-1`.

**Notice** that when there are **two** middle position choices, the operation is performed on the **frontmost** middle position choice. For example:

* Pushing `6` into the middle of `[1, 2, 3, 4, 5]` results in `[1, 2, <u>6</u>, 3, 4, 5]`.
* Popping the middle from `[1, 2, <u>3</u>, 4, 5, 6]` returns `3` and results in `[1, 2, 4, 5, 6]`.

**Example 1:**

```bash
Input:
["FrontMiddleBackQueue", "pushFront", "pushBack", "pushMiddle", "pushMiddle", "popFront", "popMiddle", "popMiddle", "popBack", "popFront"]
[[], [1], [2], [3], [4], [], [], [], [], []]
Output:
[null, null, null, null, null, 1, 3, 4, 2, -1]

Explanation:
FrontMiddleBackQueue q = new FrontMiddleBackQueue();
q.pushFront(1);   // [1]
q.pushBack(2);    // [1, 2]
q.pushMiddle(3);  // [1, 3, 2]
q.pushMiddle(4);  // [1, 4, 3, 2]
q.popFront();     // return 1 -> [4, 3, 2]
q.popMiddle();    // return 3 -> [4, 2]
q.popMiddle();    // return 4 -> [2]
q.popBack();      // return 2 -> []
q.popFront();     // return -1 -> [] (The queue is empty)
```

**Constraints:**

* 1 <= val <= 10<sup>9</sup>
* At most `1000` calls will be made to `pushFront`, `pushMiddle`, `pushBack`, `popFront`, `popMiddle`, and `popBack`.

## Hints/Notes

* use 2 queues

## Solution

Language: **C++**

```C++
class FrontMiddleBackQueue {
public:
    deque<int> left;
    deque<int> right;

    FrontMiddleBackQueue() {

    }

    void pushFront(int val) {
        left.push_front(val);
        if (left.size() > right.size()) {
            right.push_front(left.back());
            left.pop_back();
        }
    }

    void pushMiddle(int val) {
        if (left.size() == right.size()) {
            right.push_front(val);
        } else {
            left.push_back(val);
        }
    }

    void pushBack(int val) {
        right.push_back(val);
        if (left.size() + 2 == right.size()) {
            left.push_back(right.front());
            right.pop_front();
        }
    }

    int popFront() {
        if (right.empty()) {
            return -1;
        }
        if (left.empty()) {
            int result = right.front();
            right.pop_front();
            return result;
        }
        int result = left.front();
        left.pop_front();
        if (left.size() + 2 == right.size()) {
            int tmp = right.front();
            right.pop_front();
            left.push_back(tmp);
        }
        return result;
    }

    int popMiddle() {
        if (right.empty()) {
            return -1;
        }
        if (right.size() > left.size()) {
            int result = right.front();
            right.pop_front();
            return result;
        }
        int result = left.back();
        left.pop_back();
        return result;
    }

    int popBack() {
        if (right.empty()) {
            return -1;
        }
        int result = right.back();
        right.pop_back();
        if (right.size() < left.size()) {
            right.push_front(left.back());
            left.pop_back();
        }
        return result;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
```
