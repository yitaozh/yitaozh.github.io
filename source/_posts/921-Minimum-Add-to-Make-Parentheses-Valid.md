---
title: 921. Minimum Add to Make Parentheses Valid
categories: Leetcode
date: 2025-01-27 13:18:43
tags:
    - String
    - Stack
    - Greedy
---

[921. Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

A parentheses string is valid if and only if:

- It is the empty string,
- It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are valid strings, or
- It can be written as `(A)`, where `A` is a valid string.

You are given a parentheses string `s`. In one move, you can insert a parenthesis at any position of the string.

- For example, if `s = "()))"`, you can insert an opening parenthesis to be `"(**(** )))"` or a closing parenthesis to be `"())**)** )"`.

Return the minimum number of moves required to make `s` valid.

**Example 1:**

```bash
Input: s = "())"
Output: 1
```

**Example 2:**

```bash
Input: s = "((("
Output: 3
```

**Constraints:**

- `1 <= s.length <= 1000`
- `s[i]` is either `'('` or `')'`.

## Hints/Notes

- 2025/01/27
- greedy
- [Leetcode solution](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minAddToMakeValid(string s) {
        int left = 0, res = 0;
        for (auto& c : s) {
            if (c == '(') {
                left++;
            } else if (c == ')') {
                if (!left) {
                    res++;
                } else {
                    left--;
                }
            }
        }
        res += left;
        return res;
    }
};
```
