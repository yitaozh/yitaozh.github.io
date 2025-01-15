---
title: 227. Basic Calculator II
categories: Leetcode
date: 2025-01-15 00:48:25
tags:
    - Math
    - String
    - Stack
---

[227. Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given a string `s` which represents an expression, evaluate this expression and return its value.

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of `[-2^31, 2^31 - 1]`.

**Note:**  You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as `eval()`.

**Example 1:**

```bash
Input: s = "3+2*2"
Output: 7
```

**Example 2:**

```bash
Input: s = " 3/2 "
Output: 1
```

**Example 3:**

```bash
Input: s = " 3+5 / 2 "
Output: 5
```

**Constraints:**

- `1 <= s.length <= 3 * 10^5`
- `s` consists of integers and operators `('+', '-', '*', '/')` separated by some number of spaces.
- `s` represents **a valid expression** .
- All the integers in the expression are non-negative integers in the range `[0, 2^31 - 1]`.
- The answer is **guaranteed**  to fit in a **32-bit integer**.

## Hints/Notes

- 2025/01/14
- string
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    int calculate(string s) {
        stack<long> stk;
        s = '+' + s;
        int n = s.size();
        for (int i = 0; i < n; ) {
            while (i < n && s[i] == ' ') {
                i++;
            }
            if (i == n) break;
            char op = s[i];
            i++;
            while (i < n && s[i] == ' ') {
                i++;
            }
            int start = i;
            while (i < n && isdigit(s[i])) {
                i++;
            }
            int num = stoi(s.substr(start, i - start));
            if (op == '+') {
                stk.push(num);
            } else if (op == '-') {
                stk.push(-num);
            } else if (op == '*') {
                int tmp = stk.top() * num;
                stk.pop();
                stk.push(tmp);
            } else {
                int tmp = stk.top() / num;
                stk.pop();
                stk.push(tmp);
            }
        }
        long long res = 0;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};
```
