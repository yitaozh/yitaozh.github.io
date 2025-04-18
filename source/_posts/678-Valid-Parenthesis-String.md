---
title: 678. Valid Parenthesis String
categories: Leetcode
date: 2024-12-30 13:32:58
tags:
    - String
    - Dynamic Programming
    - Stack
    - Greedy
---

[678. Valid Parenthesis String](https://leetcode.com/problems/valid-parenthesis-string/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given a string `s` containing only three types of characters: `'('`, `')'` and `'*'`, return `true` if `s` is **valid** .

The following rules define a **valid**  string:

- Any left parenthesis `'('` must have a corresponding right parenthesis `')'`.
- Any right parenthesis `')'` must have a corresponding left parenthesis `'('`.
- Left parenthesis `'('` must go before the corresponding right parenthesis `')'`.
- `'*'` could be treated as a single right parenthesis `')'` or a single left parenthesis `'('` or an empty string `""`.

**Example 1:**

```bash
Input: s = "()"
Output: true
```

**Example 2:**

```bash
Input: s = "(*)"
Output: true
```

**Example 3:**

```bash
Input: s = "(*))"
Output: true
```

**Constraints:**

- `1 <= s.length <= 100`
- `s[i]` is `'('`, `')'` or `'*'`.

## Hints/Notes

- 2024/12/30
- stack
- No solution from 0x3F

## Solution

Language: **C++**

More intuitive solution with stack

```C++
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> star, left;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                left.push(i);
            } else if (s[i] == '*') {
                star.push(i);
            } else {
                if (!left.empty()) {
                    left.pop();
                } else if (!star.empty()) {
                    star.pop();
                } else {
                    return false;
                }
            }
        }
        while (!left.empty()) {
            int l = left.top(); left.pop();
            if (star.empty()) return false;
            int st = star.top(); star.pop();
            if (st < l) return false;
        }
        return true;
    }
};
```

```C++
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size(), open = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ')') {
                open--;
            } else {
                open++;
            }
            if (open < 0) return false;
        }
        open = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(') {
                open--;
            } else {
                open++;
            }
            if (open < 0) return false;
        }
        return true;
    }
};
```
