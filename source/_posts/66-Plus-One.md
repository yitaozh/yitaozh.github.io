---
title: 66. Plus One
categories: Leetcode
date: 2024-12-23 00:15:50
tags:
    - Array
    - Math
---

[66. Plus One](https://leetcode.com/problems/plus-one/description/?envType=problem-list-v2&envId=plakya4j)

## Description

You are given a **large integer**  represented as an integer array `digits`, where each `digits[i]` is the `i^th` digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading `0`'s.

Increment the large integer by one and return the resulting array of digits.

**Example 1:**

```bash
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
```

**Example 2:**

```bash
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
```

**Example 3:**

```bash
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
```

**Constraints:**

- `1 <= digits.length <= 100`
- `0 <= digits[i] <= 9`
- `digits` does not contain any leading `0`'s.

## Hints/Notes

- 2024/12/22
- digits
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), carry = 1;
        for (int i = n - 1; i >= 0; i--) {
            digits[i] += carry;
            if (digits[i] < 10) {
                carry = 0;
                break;
            }
            digits[i] = 0;
        }
        if (carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
```
