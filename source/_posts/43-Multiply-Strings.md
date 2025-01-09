---
title: 43. Multiply Strings
categories: Leetcode
date: 2024-12-21 01:02:35
tags:
    - Math
    - String
    - Simulation
---

[43. Multiply Strings](https://leetcode.com/problems/multiply-strings/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given two non-negative integers `num1` and `num2` represented as strings, return the product of `num1` and `num2`, also represented as a string.

**Note:** You must not use any built-in BigInteger library or convert the inputs to integer directly.

**Example 1:**

```bash
Input: num1 = "2", num2 = "3"
Output: "6"
```

**Example 2:**

```bash
Input: num1 = "123", num2 = "456"
Output: "56088"
```

**Constraints:**

- `1 <= num1.length, num2.length <= 200`
- `num1` and `num2` consist of digits only.
- Both `num1` and `num2`do not contain any leading zero, except the number `0` itself.

## Hints/Notes

- 2024/12/20
- string
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        ranges::reverse(num1);
        ranges::reverse(num2);
        string num(m + n, '0');
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int v1 = num1[i] - '0', v2 = num2[j] - '0';
                int val = num[i + j] - '0' + v1 * v2;
                num[i + j] = val % 10 + '0';
                num[i + j + 1] += val / 10;
            }
        }
        ranges::reverse(num);
        num.erase(0, num.find_first_not_of('0'));
        return num.empty() ? "0" : num;
    }
};
```
