---
title: 155. Min Stack
categories: Leetcode
date: 2023-12-13 19:02:52
tags:
    - Stack
    - Design
---

[155\. Min Stack](https://leetcode.com/problems/min-stack/)

## Description

Difficulty: **Medium**

Related Topics: [Stack](https://leetcode.com/tag/https://leetcode.com/tag/stack//), [Design](https://leetcode.com/tag/https://leetcode.com/tag/design//)

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the `MinStack` class:

* `MinStack()` initializes the stack object.
* `void push(int val)` pushes the element `val` onto the stack.
* `void pop()` removes the element on the top of the stack.
* `int top()` gets the top element of the stack.
* `int getMin()` retrieves the minimum element in the stack.

You must implement a solution with `O(1)` time complexity for each function.

**Example 1:**

```bash
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
```

**Constraints:**

* -2<sup>31</sup> <= val <= 2<sup>31</sup> - 1
* Methods `pop`, `top` and `getMin` operations will always be called on **non-empty** stacks.
* At most 3 * 10<sup>4</sup> calls will be made to `push`, `pop`, `top`, and `getMin`.

## Hints/Notes

* use a stack to record the min element

## Solution

Language: **C++**

```C++
class MinStack {
public:
    int min;
    stack<int> stk;
    stack<int> minStk;

    MinStack() {
        min = INT_MAX;
    }
    
    void push(int val) {
        stk.push(val);
        if (val <= min) {
            min = val;
            minStk.push(min);
        }
    }
    
    void pop() {
        if (stk.top() == min) {
            minStk.pop();
            min = minStk.empty() ? INT_MAX : minStk.top();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
```
