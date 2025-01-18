---
title: 65. Valid Number
categories: Leetcode
date: 2025-01-18 16:13:11
tags:
    - String
---

[65. Valid Number](https://leetcode.com/problems/valid-number/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given a string `s`, return whether `s` is a **valid number**.

For example, all the following are valid numbers: `"2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"`, while the following are not valid numbers: `"abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"`.

Formally, a**valid number**  is defined using one of the following definitions:

- An **integer number**  followed by an **optional exponent** .
- A **decimal number**  followed by an **optional exponent** .

An **integer number**  is defined with an **optional sign**  `'-'` or `'+'` followed by **digits** .

A **decimal number**  is defined with an **optional sign**  `'-'` or `'+'` followed by one of the following definitions:

- **Digits**  followed by a **dot**  `'.'`.
- **Digits**  followed by a **dot**  `'.'` followed by **digits** .
- A **dot**  `'.'` followed by **digits** .

An **exponent**  is defined with an **exponent notation**  `'e'` or `'E'` followed by an **integer number** .

The **digits**  are defined as one or more digits.

**Example 1:**

```bash
Input: s = "0"

Output: true
```

**Example 2:**

```bash
Input: s = "e"

Output: false
```

**Example 3:**

```bash
Input: s = "."

Output: false
```

**Constraints:**

- `1 <= s.length <= 20`
- `s` consists of only English letters (both uppercase and lowercase), digits (`0-9`), plus `'+'`, minus `'-'`, or dot `'.'`.

## Hints/Notes

- 2025/01/18
- string
- [Good solution](https://leetcode.cn/problems/valid-number/solutions/831848/gong-shui-san-xie-zi-fu-chuan-mo-ni-by-a-7cgc/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool isNumber(string s) {
        int idx_e = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'e' || s[i] == 'E') {
                if (idx_e == -1) {
                    idx_e = i;
                } else {
                    return false;
                }
            }
        }
        if (idx_e == -1) {
            return checkNum(s, 0, s.size() - 1, false);
        } else {
            return checkNum(s, 0, idx_e - 1, false) && checkNum(s, idx_e + 1, s.size() - 1, true);
        }
    }

    bool checkNum(string& s, int start, int end, bool mustInt) {
        if (start > end) {
            return false;
        }
        if (s[start] == '+' || s[start] == '-') {
            start++;
        }
        bool decimal = false, isNum = false;
        for (int i = start; i <= end; i++) {
            if (isdigit(s[i])) {
                isNum = true;
                continue;
            } else if (s[i] == '.') {
                if (decimal || mustInt) {
                    return false;
                }
                decimal = true;
            } else {
                return false;
            }
        }
        return isNum;
    }
};
```
