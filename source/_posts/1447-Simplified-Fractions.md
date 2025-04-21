---
title: 1447. Simplified Fractions
categories: Leetcode
date: 2025-03-27 00:41:59
tags:
    - Math
    - String
    - Number Theory
---

[1447. Simplified Fractions](https://leetcode.com/problems/simplified-fractions/description/)

## Description

Given an integer `n`, return a list of all **simplified**  fractions between `0` and `1` (exclusive) such that the denominator is less-than-or-equal-to `n`. You can return the answer in **any order** .

**Example 1:**

```bash
Input: n = 2
Output: ["1/2"]
Explanation: "1/2" is the only unique fraction with a denominator less-than-or-equal-to 2.
```

**Example 2:**

```bash
Input: n = 3
Output: ["1/2","1/3","2/3"]
```

**Example 3:**

```bash
Input: n = 4
Output: ["1/2","1/3","1/4","2/3","3/4"]
Explanation: "2/4" is not a simplified fraction because it can be simplified to "1/2".
```

**Constraints:**

- `1 <= n <= 100`

## Hints/Notes

- 2025/03/23 Q1
- math
- [Leetcode solution](https://leetcode.cn/problems/simplified-fractions/solutions/1250991/zui-jian-fen-shu-by-leetcode-solution-98zy/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        if (n == 1) {
            return {};
        }
        vector<string> res;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (gcd(i, j) == 1) {
                    res.push_back(to_string(j) + "/" + to_string(i));
                }
            }
        }
        return res;
    }
};
```
