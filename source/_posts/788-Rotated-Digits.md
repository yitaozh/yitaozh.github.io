---
title: 788. Rotated Digits
categories: Leetcode
date: 2024-11-30 12:56:46
tags:
    - Math
    - Dynamic Programming
---

[788. Rotated Digits](https://leetcode.com/problems/rotated-digits/description/)

## Description

An integer `x` is a **good**  if after rotating each digit individually by 180 degrees, we get a valid number that is different from `x`. Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. For example:

- `0`, `1`, and `8` rotate to themselves,
- `2` and `5` rotate to each other (in this case they are rotated in a different direction, in other words, `2` or `5` gets mirrored),
- `6` and `9` rotate to each other, and
- the rest of the numbers do not rotate to any other number and become invalid.

Given an integer `n`, return the number of **good**  integers in the range `[1, n]`.

**Example 1:**

```bash
Input: n = 10
Output: 4
Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
```

**Example 2:**

```bash
Input: n = 1
Output: 0
```

**Example 3:**

```bash
Input: n = 2
Output: 1
```

**Constraints:**

- `1 <= n <= 10^4`

## Hints/Notes

- 2024/11/21
- digit dp with is_num
- [0x3F's solution](https://leetcode.cn/problems/rotated-digits/solutions/1847409/by-endlesscheng-9b96/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> dp;
    string s;

    int rotatedDigits(int n) {
        s = to_string(n);
        dp.resize(s.size(), -1);
        int res = dfs(0, true, false);
        return res;
    }

    int dfs(int index, bool isLimit, bool is_num) {
        if (index == s.size()) {
            return is_num;
        }
        if (!isLimit && is_num && dp[index] != -1) {
            return dp[index];
        }
        int res = 0;
        int up = isLimit ? s[index] - '0' : 9;
        for (int i = 0; i <= up; i++) {
            switch (i) {
                case 0:
                case 1:
                case 8:
                    res += dfs(index + 1, isLimit && i == up, is_num);
                    break;
                case 2:
                case 5:
                case 6:
                case 9:
                    res += dfs(index + 1, isLimit && i == up, true);
                default:
                    continue;
            }
        }
        // check status during read and write memo both
        if (!isLimit && is_num) {
            dp[index] = res;
        }
        return res;
    }
};
```
