---
title: 3352. Count K-Reducible Numbers Less Than N
categories: Leetcode
date: 2024-12-03 17:12:55
tags:
    - Math
    - String
    - Dynamic Programming
    - Combinatorics
---

[3352. Count K-Reducible Numbers Less Than N](https://leetcode.com/problems/count-k-reducible-numbers-less-than-n/description/)

## Description

You are given a **binary**  string `s` representing a number `n` in its binary form.

You are also given an integer `k`.

An integer `x` is called **k-reducible** if performing the following operation **at most**  `k` times reduces it to 1:

- Replace `x` with the **count**  of set bits in its binary representation.

For example, the binary representation of 6 is `"110"`. Applying the operation once reduces it to 2 (since `"110"` has two set bits). Applying the operation again to 2 (binary `"10"`) reduces it to 1 (since `"10"` has one set bit).

Return an integer denoting the number of positive integers **less**  than `n` that are **k-reducible** .

Since the answer may be too large, return it **modulo**  `10^9 + 7`.

**Example 1:**

<div class="example-block">
Input: s = "111", k = 1

Output: 3

Explanation:

`n = 7`. The 1-reducible integers less than 7 are 1, 2, and 4.

**Example 2:**

<div class="example-block">
Input: s = "1000", k = 2

Output: 6

Explanation:

`n = 8`. The 2-reducible integers less than 8 are 1, 2, 3, 4, 5, and 6.

**Example 3:**

<div class="example-block">
Input: s = "1", k = 3

Output: 0

Explanation:

There are no positive integers less than `n = 1`, so the answer is 0.

**Constraints:**

- `1 <= s.length <= 800`
- `s` has no leading zeros.
- `s` consists only of the characters `'0'` and `'1'`.
- `1 <= k <= 5`

## Hints/Notes

- 2024/11/26
- digit dp
- [0x3F's solution](https://leetcode.cn/problems/count-k-reducible-numbers-less-than-n/solutions/2983541/xian-xing-dp-shu-wei-dppythonjavacgo-by-yw0dl/)
- Weekly Contest 423

## Solution

Language: **C++**

```C++
class Solution {
public:
    string s;
    vector<bool> reducible;
    vector<vector<int>> dp;
    int MOD = 1'000'000'007;

    int countKReducibleNumbers(string s, int k) {
        this->s = s;
        reducible.resize(s.size() + 1, false);
        reducible[1] = true;
        for (int i = 0; i < k - 1; i++) {
            for (int j = s.size(); j > 1; j--) {
                reducible[j] = reducible[j] || reducible[__builtin_popcount(j)];
            }
        }
        dp.resize(s.size(), vector<int>(s.size() + 1, -1));
        int res = dfs(0, 0, true);
        return res;
    }

    int dfs(int index, int count, bool isLimit) {
        if (index == s.size()) {
            return reducible[count] && !isLimit;
        }
        if (!isLimit && dp[index][count] != -1) {
            return dp[index][count];
        }
        long res = 0;
        int up = isLimit ? s[index] - '0' : 1;
        for (int i = 0; i <= up; i++) {
            res = (res + dfs(index + 1, count + i, isLimit && i == up)) % MOD;
        }
        if (!isLimit) {
            dp[index][count] = res;
        }
        return res;
    }
};
```
