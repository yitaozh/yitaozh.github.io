---
title: 166. Fraction to Recurring Decimal
categories: Leetcode
date: 2025-04-08 13:03:39
tags:
    - Hash Table
    - Math
    - String
---

[166. Fraction to Recurring Decimal](https://leetcode.com/problems/fraction-to-recurring-decimal/description/?envType=company&envId=oracle&favoriteSlug=oracle-six-months)

## Description

Given two integers representing the `numerator` and `denominator` of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return **any of them** .

It is **guaranteed**  that the length of the answer string is less than `10^4` for all the given inputs.

**Example 1:**

```bash
Input: numerator = 1, denominator = 2
Output: "0.5"
```

**Example 2:**

```bash
Input: numerator = 2, denominator = 1
Output: "2"
```

**Example 3:**

```bash
Input: numerator = 4, denominator = 333
Output: "0.(012)"
```

**Constraints:**

- `-2^31 <=numerator, denominator <= 2^31 - 1`
- `denominator != 0`

## Hints/Notes

- 2025/04/07 Q1
- map
- [Leetcode solution](https://leetcode.com/problems/fraction-to-recurring-decimal/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        string res;
        if (numerator < 0 ^ denominator < 0) {
            res.push_back('-');
        }
        long dividend = labs(numerator);
        long divisor = labs(denominator);
        res.append(to_string(dividend / divisor));
        if (dividend % divisor == 0) {
            return res;
        }
        dividend = dividend % divisor;
        unordered_map<int, int> previous;
        res.push_back('.');
        int digits = 1;
        while (dividend != 0) {
            if (previous.contains(dividend)) {
                res.insert(previous[dividend], "(");
                res.push_back(')');
                return res;
            }
            previous[dividend] = res.size();
            dividend *= 10;
            res.append(to_string(dividend / divisor));
            dividend %= divisor;
        }
        return res;
    }
};
```
