---
title: 20. Valid Parentheses
categories: Leetcode
date: 2023-12-08 22:00:06
tags:
    - String
    - Stack
---

[20\. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)

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

* 2023/11/29
* stack
* [0x3F's solution](https://leetcode.cn/problems/valid-parentheses/solutions/2809539/gua-hao-xiao-xiao-le-san-chong-li-yong-z-2xb3/)

## Solution

Language: **C++**

Cleaner solution:

```C++
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };
        stack<char> stk;
        for (char c : s) {
            if (!m.contains(c)) {
                stk.push(c);
            } else {
                if (stk.empty() || stk.top() != m[c]) {
                    return false;
                } else {
                    stk.pop();
                }
            }
        }
        return stk.empty();
    }
};
```

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
