---
title: 20. Valid Parentheses
categories: Leetcode
date: 2023-12-08 22:00:06
tags:
    - String
    - Stack
---

# [20\. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)

## Description

Difficulty: **Easy**

Related Topics: [String](https://leetcode.com/tag/https://leetcode.com/tag/string//), [Stack](https://leetcode.com/tag/https://leetcode.com/tag/stack//)

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

**Example 1:**

```bash
Input: s = "()"
Output: true
```

**Example 2:**

```bash
Input: s = "()[]{}"
Output: true
```

**Example 3:**

```bash
Input: s = "(]"
Output: false
```

**Constraints:**

* 1 <= s.length <= 10<sup>4</sup>
* `s` consists of parentheses only `'()[]{}'`.

## Hints/Notes

* stack

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            switch(c) {
                case '(':
                    stk.push(c);
                    break;
                case ')':
                    if (stk.empty() || stk.top() != '(') {
                        return false;
                    } else {
                        stk.pop();
                    }
                    break;
                case '[':
                    stk.push(c);
                    break;
                case ']':
                    if (stk.empty() || stk.top() != '[') {
                        return false;
                    } else {
                        stk.pop();
                    }
                    break;
                case '{':
                    stk.push(c);
                    break;
                case '}':
                    if (stk.empty() || stk.top() != '{') {
                        return false;
                    } else {
                        stk.pop();
                    }
                    break;
            }
        }
        return stk.empty();
    }
};
```
