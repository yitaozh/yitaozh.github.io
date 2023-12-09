---
title: 150. Evaluate Reverse Polish Notation
categories: Leetcode
date: 2023-12-08 22:16:12
tags:
    - Array
    - Math
    - Stack
---

# [150\. Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Math](https://leetcode.com/tag/https://leetcode.com/tag/math//), [Stack](https://leetcode.com/tag/https://leetcode.com/tag/stack//)

You are given an array of strings `tokens` that represents an arithmetic expression in a [Reverse Polish Notation](http://en.wikipedia.org/wiki/Reverse_Polish_notation).

Evaluate the expression. Return _an integer that represents the value of the expression_.

**Note** that:

* The valid operators are `'+'`, `'-'`, `'*'`, and `'/'`.
* Each operand may be an integer or another expression.
* The division between two integers always **truncates toward zero**.
* There will not be any division by zero.
* The input represents a valid arithmetic expression in a reverse polish notation.
* The answer and all the intermediate calculations can be represented in a **32-bit** integer.

**Example 1:**

```bash
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
```

**Example 2:**

```bash
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
```

**Example 3:**

```bash
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```

**Constraints:**

* 1 <= tokens.length <= 10<sup>4</sup>
* `tokens[i]` is either an operator: `"+"`, `"-"`, `"*"`, or `"/"`, or an integer in the range `[-200, 200]`.

## Hints/Notes

* stack

## Solution

Language: **C++**

```C++
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string token : tokens) {
            if (token == "+") {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(a + b);
            } else if (token == "-") {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(b - a);
            } else if (token == "*" ) {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(a * b);
            } else if (token == "/") {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(b / a);
            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
```
