---
title: 2376. Count Special Integers
categories: Leetcode
date: 2024-11-26 17:49:25
tags:
    - Math
    - Dynamic Programming
---

[2376. Count Special Integers](https://leetcode.com/problems/count-special-integers/description/)

## Description

We call a positive integer **special**  if all of its digits are **distinct** .

Given a **positive**  integer `n`, return the number of special integers that belong to the interval `[1, n]`.

**Example 1:**

```bash
Input: n = 20
Output: 19
Explanation: All the integers from 1 to 20, except 11, are special. Thus, there are 19 special integers.
```

**Example 2:**

```bash
Input: n = 5
Output: 5
Explanation: All the integers from 1 to 5 are special.
```

**Example 3:**

```bash
Input: n = 135
Output: 110
Explanation: There are 110 integers from 1 to 135 that are special.
Some of the integers that are not special are: 22, 114, and 131.
```

**Constraints:**

- `1 <= n <= 2 * 10^9`

## Hints/Notes

- 2024/11/14
- digit dp
- [0x3F's solution](https://leetcode.cn/problems/count-special-integers/solutions/1746956/shu-wei-dp-mo-ban-by-endlesscheng-xtgx/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string s;
    vector<vector<int>> dp;

    int countSpecialNumbers(int n) {
        s = to_string(n);
        dp.resize(s.size(), vector<int>(1024, -1));
        int res = dfs(0, 0, true, false);
        return res;
    }

    int dfs(int index, int mask, bool isLimit, bool isNum) {
        if (index == s.size()) {
            return isNum;
        }
        if (!isLimit && isNum && dp[index][mask] != -1) {
            return dp[index][mask];
        }
        int res = isNum ? 0 : dfs(index + 1, mask, false, false);
        int up = isLimit ? s[index] - '0' : 9;
        // if we start from 0 here when isNum is false, we are taking
        // 0 as a value answer
        for (int i = 1 - isNum; i <= up; i++) {
            if ((mask >> i & 1) == 0) {
                res += dfs(index + 1, mask | (1 << i), isLimit && i == up, true);
            }
        }
        // check status during read and write memo both
        if (!isLimit && isNum) {
            dp[index][mask] = res;
        }
        return res;
    }
};
```
