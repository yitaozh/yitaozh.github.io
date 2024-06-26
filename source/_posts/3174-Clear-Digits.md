---
title: 3174. Clear Digits
categories: Leetcode
date: 2024-06-14 13:55:54
tags:
    - Hash Table
    - String
    - Simulation
---

[3174. Clear Digits](https://leetcode.com/problems/clear-digits/description/)

## Description

You are given a string `s`.

Your task is to remove **all**  digits by doing this operation repeatedly:

- Delete the first digit and the **closest**  <b>non-digit</b> character to its left.

Return the resulting string after removing all digits.

**Example 1:**

```bash
Input: s = "abc"

Output: "abc"

Explanation:

There is no digit in the string.
```

**Example 2:**

```bash
Input: s = "cb34"

Output: ""

Explanation:

First, we apply the operation on `s[2]`, and `s` becomes `"c4"`.

Then we apply the operation on `s[1]`, and `s` becomes `""`.
```

**Constraints:**

- `1 <= s.length <= 100`
- `s` consists only of lowercase English letters and digits.
- The input is generated such that it is possible to delete all digits.

## Hints/Notes

- Biweekly Contest 132

## Solution

Language: **C++**

```C++
class Solution {
public:
    string clearDigits(string s) {
        stack<char> str;
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                str.pop();
            } else {
                str.push(c);
            }
        }
        string res;
        while (!str.empty()) {
            res.push_back(str.top());
            str.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```
