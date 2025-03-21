---
title: 772. Basic Calculator III
categories: Leetcode
date: 2025-03-20 20:42:27
tags:
    - Math
    - String
    - Stack
    - Recursion
---

[772. Basic Calculator III](https://leetcode.com/problems/basic-calculator-iii/description/)

## Description

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, `'+'`, `'-'`, `'*'`, `'/'` operators, and open `'('` and closing parentheses `')'`. The integer division should **truncate toward zero** .

You may assume that the given expression is always valid. All intermediate results will be in the range of `[-2^31, 2^31 - 1]`.

**Note:**  You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as `eval()`.

**Example 1:**

```bash
Input: s = "1+1"
Output: 2
```

**Example 2:**

```bash
Input: s = "6-4/2"
Output: 4
```

**Example 3:**

```bash
Input: s = "2*(5+5*2)/3+(6/2+8)"
Output: 21
```

**Constraints:**

- `1 <= s <= 10^4`
- `s` consists of digits, `'+'`, `'-'`, `'*'`, `'/'`, `'('`,and`')'`.
- `s` is a **valid**  expression.

## Hints/Notes

- 2025/02/25 Q3
- stack
- [Leetcode solution](https://leetcode.com/problems/basic-calculator-iii/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    unordered_map<char, int> op_priority = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2}
    };

    stack<char> ops;
    stack<long long> nums;

    int calculate(string s) {
        nums.push(0);
        int n = s.size();
        for (int i = 0; i < n; ) {
            if (s[i] == ' ') {
                i++;
                continue;
            } else if (s[i] == '(') {
                ops.push('(');
                if (s[i + 1] == '-') {
                    i++;
                    nums.push(0);
                    ops.push('-');
                }
                i++;
            } else if (s[i] == ')') {
                while (ops.top() != '(') {
                    cal();
                }
                ops.pop();
                i++;
            } else if (s[i] >= '0' && s[i] <= '9') {
                int l = i;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    i++;
                }
                nums.push(stoi(s.substr(l, i - l)));
            } else {
                while (!ops.empty() && ops.top() != '(' && op_priority[ops.top()] >= op_priority[s[i]]) {
                    cal();
                }
                ops.push(s[i]);
                i++;
            }
        }
        while (!ops.empty() && ops.top() != '(') {
            cal();
        }
        return nums.top();
    }

    void cal() {
        long long b = nums.top(); nums.pop();
        long long a = nums.top(); nums.pop();
        char op = ops.top(); ops.pop();
        long long res;
        switch (op) {
            case '+': res = a + b; break;
            case '-': res = a - b; break;
            case '*': res = a * b; break;
            case '/': res = a / b; break;
        }
        nums.push(res);
    }
};
```
