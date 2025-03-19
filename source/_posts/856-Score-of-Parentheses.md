---
title: 856. Score of Parentheses
categories: Leetcode
date: 2025-03-18 22:01:14
tags:
    - String
    - Stack
---

[856. Score of Parentheses](https://leetcode.com/problems/score-of-parentheses/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

Given a balanced parentheses string `s`, return the **score**  of the string.

The **score**  of a balanced parentheses string is based on the following rule:

- `"()"` has score `1`.
- `AB` has score `A + B`, where `A` and `B` are balanced parentheses strings.
- `(A)` has score `2 * A`, where `A` is a balanced parentheses string.

**Example 1:**

```bash
Input: s = "()"
Output: 1
```

**Example 2:**

```bash
Input: s = "(())"
Output: 2
```

**Example 3:**

```bash
Input: s = "()()"
Output: 2
```

**Constraints:**

- `2 <= s.length <= 50`
- `s` consists of only `'('` and `')'`.
- `s` is a balanced parentheses string.

## Hints/Notes

- 2025/02/19 Q3
- stack
- [Leetcode solution](https://leetcode.com/problems/score-of-parentheses/editorial/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<string> stk;
        for (char& c : s) {
            if (c == '(') {
                stk.push({c});
            } else {
                int sum = 0;
                while (stk.top() != "(") {
                    sum += stoi(stk.top());
                    stk.pop();
                }
                // pop out the "("
                stk.pop();
                if (sum == 0) sum = 1; else sum *= 2;
                stk.push(to_string(sum));
            }
        }
        int res = 0;
        while (!stk.empty()) {
            res += stoi(stk.top());
            stk.pop();
        }
        return res;
    }
};
```
