---
title: 224. Basic Calculator
categories: Leetcode
date: 2025-02-20 16:39:17
tags:
    - Math
    - String
    - Stack
    - Recursion
---

[224. Basic Calculator](https://leetcode.com/problems/basic-calculator/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given a string `s` representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

**Note:**  You are **not**  allowed to use any built-in function which evaluates strings as mathematical expressions, such as `eval()`.

**Example 1:**

```bash
Input: s = "1 + 1"
Output: 2
```

**Example 2:**

```bash
Input: s = " 2-1 + 2 "
Output: 3
```

**Example 3:**

```bash
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
```

**Constraints:**

- `1 <= s.length <= 3 * 10^5`
- `s` consists of digits, `'+'`, `'-'`, `'('`, `')'`, and `' '`.
- `s` represents a valid expression.
- `'+'` is **not**  used as a unary operation (i.e., `"+1"` and `"+(2 + 3)"` is invalid).
- `'-'` could be used as a unary operation (i.e., `"-1"` and `"-(2 + 3)"` is valid).
- There will be no two consecutive operators in the input.
- Every number and running calculation will fit in a signed 32-bit integer.

## Hints/Notes

- 2025/02/07
- stack
- [Leetcode solution](https://leetcode.com/problems/basic-calculator/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int calculate(string s) {
        s = '(' + s + ')';
        stack<string> stk;
        for (int i = 0; i < s.size(); ) {
            if (s[i] != ' ') {
                if (s[i] == '(' || s[i] == '+' || s[i] == '-') {
                    string tmp{s[i]};
                    stk.push(tmp);
                    i++;
                } else if (isdigit(s[i])) {
                    int cur = 0;
                    while (isdigit(s[i])) {
                        cur = cur * 10 + (s[i++] - '0');
                    }
                    stk.push(to_string(cur));
                } else {
                    int sum = 0, cur = 0;
                    while (stk.top() != "(") {
                        string c = stk.top();
                        stk.pop();
                        if (c == "+") {
                            sum += cur;
                            cur = 0;
                        } else if (c == "-"){
                            sum -= cur;
                            cur = 0;
                        } else {
                            cur = stoi(c);
                        }
                    }
                    i++;
                    sum += cur;
                    stk.pop();
                    stk.push(to_string(sum));
                }
            } else {
                i++;
            }
        }
        return stoi(stk.top());
    }
};
```
