---
title: 225. Implement Stack using Queues
categories: Leetcode
date: 2023-11-07 23:19:56
tags:
    - Stack
    - Design
    - Queue
---

# [225\. Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/)

## Description

Difficulty: **Easy**

Related Topics: [Stack](https://leetcode.com/tag/https://leetcode.com/tag/stack//), [Design](https://leetcode.com/tag/https://leetcode.com/tag/design//), [Queue](https://leetcode.com/tag/https://leetcode.com/tag/queue//)

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (`push`, `top`, `pop`, and `empty`).

Implement the `MyStack` class:

* `void push(int x)` Pushes element x to the top of the stack.
* `int pop()` Removes the element on the top of the stack and returns it.
* `int top()` Returns the element on the top of the stack.
* `boolean empty()` Returns `true` if the stack is empty, `false` otherwise.

**Notes:**

* You must use **only** standard operations of a queue, which means that only `push to back`, `peek/pop from front`, `size` and `is empty` operations are valid.
* Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.

**Example 1:**

```bash
Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
```

**Constraints:**

* `1 <= x <= 9`
* At most `100` calls will be made to `push`, `pop`, `top`, and `empty`.
* All the calls to `pop` and `top` are valid.

**Follow-up:** Can you implement the stack using only one queue?

## Hints/Notes

* pop and re-enqueue all previous elements when trying to access the last element

## Solution

Language: **C++**

```C++
class MyStack {
public:
    queue<int> q;
    int head;

    MyStack() {
        
    }
    
    void push(int x) {
        head = x;
        q.push(x);
    }
    
    int pop() {
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            int num = q.front();
            q.pop();
            q.push(num);
            head = num;
        }
        int res = q.front();
        q.pop();
        return res;
    }
    
    int top() {
        return head;
    }
    
    bool empty() {
        return q.empty();   
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
```
