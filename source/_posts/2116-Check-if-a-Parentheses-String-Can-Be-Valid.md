---
title: 2116. Check if a Parentheses String Can Be Valid
categories: Leetcode
date: 2025-03-14 00:47:21
tags:
    - String
    - Stack
    - Greedy
---

[2116. Check if a Parentheses String Can Be Valid](https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/)

## Description

A parentheses string is a **non-empty**  string consisting only of `'('` and `')'`. It is valid if **any**  of the following conditions is **true** :

- It is `()`.
- It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are valid parentheses strings.
- It can be written as `(A)`, where `A` is a valid parentheses string.

You are given a parentheses string `s` and a string `locked`, both of length `n`. `locked` is a binary string consisting only of `'0'`s and `'1'`s. For **each**  index `i` of `locked`,

- If `locked[i]` is `'1'`, you **cannot**  change `s[i]`.
- But if `locked[i]` is `'0'`, you **can**  change `s[i]` to either `'('` or `')'`.

Return `true` if you can make `s` a valid parentheses string. Otherwise, return `false`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/11/06/eg1.png" style="width: 311px; height: 101px;">

```bash
Input: s = "))()))", locked = "010100"
Output: true
Explanation: locked[1] == '1' and locked[3] == '1', so we cannot change s[1] or s[3].
We change s[0] and s[4] to '(' while leaving s[2] and s[5] unchanged to make s valid.```

**Example 2:**

```bash
Input: s = "()()", locked = "0000"
Output: true
Explanation: We do not need to make any changes because s is already valid.
```

**Example 3:**

```bash
Input: s = ")", locked = "0"
Output: false
Explanation: locked permits us to change s[0].
Changing s[0] to either '(' or ')' will not make s valid.
```

**Example 4:**

```bash
Input: s = "(((())(((())", locked = "111111010111"
Output: true
Explanation: locked permits us to change s[6] and s[8].
We change s[6] and s[8] to ')' to make s valid.
```

**Constraints:**

- `n == s.length == locked.length`
- `1 <= n <= 10^5`
- `s[i]` is either `'('` or `')'`.
- `locked[i]` is either `'0'` or `'1'`.

## Hints/Notes

- 2025/03/05 Q1
- stack
- [Leetcode solution](https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    // locked = '0': we don't care what's the real char here
    // locked = '1': if the s[i] == '(', we need to supply the ')' later
    //
    bool canBeValid(string s, string locked) {
        stack<int> open, flexibility;
        int n = s.size();
        if (n % 2) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {
                flexibility.push(i);
            } else {
                if (s[i] == '(') {
                    open.push(i);
                } else {
                    if (!open.empty()) {
                        open.pop();
                    } else if (!flexibility.empty()) {
                        flexibility.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        while (!open.empty()) {
            if (flexibility.empty() || flexibility.top() < open.top()) {
                return false;
            } else {
                flexibility.pop();
                open.pop();
            }
        }
        return flexibility.size() % 2 == 0;
    }
};
```
