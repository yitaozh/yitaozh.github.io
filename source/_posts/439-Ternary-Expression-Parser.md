---
title: 439. Ternary Expression Parser
categories: Leetcode
date: 2025-04-20 17:11:21
tags:
    - String
    - Stack
    - Recursion
---

[439. Ternary Expression Parser](https://leetcode.com/problems/ternary-expression-parser/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

Given a string `expression` representing arbitrarily nested ternary expressions, evaluate the expression, and return the result of it.

You can always assume that the given expression is valid and only contains digits, `'?'`, `':'`, `'T'`, and `'F'` where `'T'` is true and `'F'` is false. All the numbers in the expression are **one-digit**  numbers (i.e., in the range `[0, 9]`).

The conditional expressions group right-to-left (as usual in most languages), and the result of the expression will always evaluate to either a digit, `'T'` or `'F'`.

**Example 1:**

```bash
Input: expression = "T?2:3"
Output: "2"
Explanation: If true, then result is 2; otherwise result is 3.
```

**Example 2:**

```bash
Input: expression = "F?1:T?4:5"
Output: "4"
Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:
"(F ? 1 : (T ? 4 : 5))" --> "(F ? 1 : 4)" --> "4"
or "(F ? 1 : (T ? 4 : 5))" --> "(T ? 4 : 5)" --> "4"
```

**Example 3:**

```bash
Input: expression = "T?T?F:5:3"
Output: "F"
Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:
"(T ? (T ? F : 5) : 3)" --> "(T ? F : 3)" --> "F"
"(T ? (T ? F : 5) : 3)" --> "(T ? F : 5)" --> "F"
```

**Constraints:**

- `5 <= expression.length <= 10^4`
- `expression` consists of digits, `'T'`, `'F'`, `'?'`, and `':'`.
- It is **guaranteed**  that `expression` is a valid ternary expression and that each number is a **one-digit number** .

## Hints/Notes

- 2025/04/20 Q3
- stack
- [0x3F's solution](https://leetcode.com/problems/ternary-expression-parser/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string parseTernary(string expression) {
        stack<char> stk;
        int n = expression.size();
        for (int i = n - 1; i >= 0; i--) {
            char& c = expression[i];
            if (c != '?') {
                stk.push(c);
            } else {
                i--;
                char op = expression[i];
                char first = stk.top(); stk.pop();
                stk.pop(); char second = stk.top(); stk.pop();
                char res;
                if (op == 'T') {
                    res = first;
                } else {
                    res = second;
                }
                stk.push(res);
            }
        }
        return string(1, stk.top());
    }
};
```
