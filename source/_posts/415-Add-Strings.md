---
title: 415. Add Strings
categories: Leetcode
date: 2025-01-23 10:48:35
tags:
    - Math
    - String
    - Simulation
---

[415. Add Strings](https://leetcode.com/problems/add-strings/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given two non-negative integers, `num1` and `num2` represented as string, return the sum of `num1` and `num2` as a string.

You must solve the problem without using any built-in library for handling large integers (such as `BigInteger`). You must also not convert the inputs to integers directly.

**Example 1:**

```bash
Input: num1 = "11", num2 = "123"
Output: "134"
```

**Example 2:**

```bash
Input: num1 = "456", num2 = "77"
Output: "533"
```

**Example 3:**

```bash
Input: num1 = "0", num2 = "0"
Output: "0"
```

**Constraints:**

- `1 <= num1.length, num2.length <= 10^4`
- `num1` and `num2` consist of only digits.
- `num1` and `num2` don't have any leading zeros except for the zero itself.

## Hints/Notes

- 2025/01/23
- string
- [Leetcode solution](https://leetcode.com/problems/add-strings/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string addStrings(string num1, string num2) {
        int l1 = num1.size() - 1, l2 = num2.size() - 1, carry = 0;
        string res;
        while (l1 >= 0 || l2 >= 0 || carry) {
            if (l1 >= 0) {
                carry += num1[l1--] - '0';
            }
            if (l2 >= 0) {
                carry += num2[l2--] - '0';
            }
            res.push_back(carry % 10 + '0');
            carry /= 10;
        }
        ranges::reverse(res);
        return res;
    }
};
```
