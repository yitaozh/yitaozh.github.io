---
title: 3114. Latest Time You Can Obtain After Replacing Characters
categories: Leetcode
date: 2024-05-10 12:00:24
tags:
    - String
    - Enumeration
---

[3114. Latest Time You Can Obtain After Replacing Characters](https://leetcode.com/problems/latest-time-you-can-obtain-after-replacing-characters/description/)

## Description

You are given a string `s` representing a 12-hour format time where some of the digits (possibly none) are replaced with a `"?"`.

12-hour times are formatted as `"HH:MM"`, where `HH` is between `00` and `11`, and `MM` is between `00` and `59`. The earliest 12-hour time is `00:00`, and the latest is `11:59`.

You have to replace **all**  the `"?"` characters in `s` with digits such that the time we obtain by the resulting string is a **valid**  12-hour format time and is the **latest**  possible.

Return the resulting string.

**Example 1:**

```bash
Input: s = "1?:?4"

Output: "11:54"

Explanation: The latest 12-hour format time we can achieve by replacing `"?"` characters is `"11:54"`.
```

**Example 2:**

```bash
Input: s = "0?:5?"

Output: "09:59"

Explanation: The latest 12-hour format time we can achieve by replacing `"?"` characters is `"09:59"`.
```

**Constraints:**

- `s.length == 5`
- `s[2]` is equal to the character `":"`.
- All characters except `s[2]` are digits or `"?"` characters.
- The input is generated such that there is **at least**  one time between `"00:00"` and `"11:59"` that you can obtain after replacing the `"?"` characters.

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    string findLatestTime(string s) {
        string res;
        if (s[0] == '?' && s[1] == '?') {
            res += "11";
        } else if (s[0] == '?') {
            if (s[1] == '0' || s[1] == '1') {
                res = res + "1" + s[1];
            } else {
                res = res + "0" + s[1];
            }
        } else if (s[1] == '?') {
            if (s[0] == '0') {
                res = res + s[0] + "9";
            } else {
                res = res + s[0] + "1";
            }
        } else {
            res = res + s[0] + s[1];
        }

        res += ":";

        if (s[3] == '?') {
            res = res + "5";
        } else {
            res = res + s[3];
        }
        if (s[4] == '?') {
            res = res + "9";
        } else {
            res = res + s[4];
        }

        return res;
    }
};
```
