---
title: 1249. Minimum Remove to Make Valid Parentheses
categories: Leetcode
date: 2025-01-15 00:36:24
tags:
    - String
    - Stack
---

[1249. Minimum Remove to Make Valid Parentheses](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given a string s of `'('` , `')'` and lowercase English characters.

Your task is to remove the minimum number of parentheses ( `'('` or `')'`, in any positions ) so that the resulting parentheses string is valid and return **any**  valid string.

Formally, a parentheses string is valid if and only if:

- It is the empty string, contains only lowercase characters, or
- It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are valid strings, or
- It can be written as `(A)`, where `A` is a valid string.

**Example 1:**

```bash
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
```

**Example 2:**

```bash
Input: s = "a)b(c)d"
Output: "ab(c)d"
```

**Example 3:**

```bash
Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `s[i]` is either`'('` , `')'`, or lowercase English letter.

## Hints/Notes

- 2025/01/13
- stack
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int> remove;
        stack<int> stk;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                if (!stk.empty()) {
                    stk.pop();
                } else {
                    remove.insert(i);
                }
            }
        }
        while (!stk.empty()) {
            remove.insert(stk.top());
            stk.pop();
        }
        string res;
        for (int i = 0; i < n; i++) {
            if (!remove.contains(i)) {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};
```
