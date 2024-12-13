---
title: 3343. Count Number of Balanced Permutations
categories: Leetcode
date: 2024-11-20 15:15:55
tags:
    - Math
    - String
    - Dynamic Programming
    - Combinatorics
---

[3343. Count Number of Balanced Permutations](https://leetcode.com/problems/count-number-of-balanced-permutations/description/)

## Description

You are given a string `num`. A string of digits is called **balanced** if the sum of the digits at even indices is equal to the sum of the digits at odd indices.

Return the number of **distinct**  **permutations**  of `num` that are **balanced** .

Since the answer may be very large, return it **modulo**  `10^9 + 7`.

A **permutation**  is a rearrangement of all the characters of a string.

**Example 1:**

```bash
Input: num = "123"

Output: 2
```

Explanation:

- The distinct permutations of `num` are `"123"`, `"132"`, `"213"`, `"231"`, `"312"` and `"321"`.
- Among them, `"132"` and `"231"` are balanced. Thus, the answer is 2.

**Example 2:**

```bash
Input: num = "112"

Output: 1
```

Explanation:

- The distinct permutations of `num` are `"112"`, `"121"`, and `"211"`.
- Only `"121"` is balanced. Thus, the answer is 1.

**Example 3:**

```bash
Input: num = "12345"

Output: 0
```

Explanation:

- None of the permutations of `num` are balanced, so the answer is 0.

**Constraints:**

- `2 <= num.length <= 80`
- `num` consists of digits `'0'` to `'9'` only.

## Hints/Notes

- 2024/11/09
- [0x3F's solution](https://leetcode.cn/problems/count-number-of-balanced-permutations/solution/duo-zhong-ji-pai-lie-shu-ji-shu-dppython-42ky/)
- Weekly Contest 422
- Not suitable for interview

## Solution

Language: **C++**

```C++
class Solution {
public:
    const static int MOD = 1'000'000'007;
    const static int MX = 41;
    long long F[MX];
    long long INV_F[MX];
    int count[10]{};
    int total = 0;

    // quick power
    long long pow(long long x, int n) {
        long long res = 1;
        for (; n; n /= 2) {
            if (n % 2) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
        }
        return res;
    }

    // calculate the inverse
    void init() {
        F[0] = 1;
        for (int i = 1; i < MX; i++) {
            F[i] = F[i - 1] * i % MOD;
        }
        INV_F[MX - 1] = pow(F[MX - 1], MOD - 2);
        for (int i = MX - 1; i; i--) {
            INV_F[i - 1] = INV_F[i] * i % MOD;
        }
    }

    vector<vector<vector<int>>> dp;

    int countBalancedPermutations(string num) {
        init();
        for (char& c : num) {
            count[c - '0']++;
            total += c - '0';
        }
        if (total % 2) {
            return 0;
        }
        partial_sum(count, count + 10, count);
        int n = num.size(), n1 = n / 2;
        dp.resize(10, vector<vector<int>>(n1 + 1, vector<int>(total / 2 + 1, -1)));
        return F[n1] * F[n - n1] % MOD * dfs(9, n1, total / 2) % MOD;
    }

    int dfs(int i, int left, int target) {
        if (i < 0) {
            return target == 0;
        }
        if (dp[i][left][target] != -1) {
            return dp[i][left][target];
        }
        int res = 0;
        // recalculate the count[i]
        int c = count[i] - (i ? count[i - 1] : 0);
        // we need to assign the left to 0 ~ i indexes of count, there are count[i] - left holes, and we can take at most this number
        // holes at index i
        for (int k = max(0, c - (count[i] - left)); k <= min(c, left) && k * i <= target; k++) {
            int tmp = dfs(i - 1, left - k, target - k * i);
            res = (res + tmp * INV_F[k] % MOD * INV_F[c - k]) % MOD;
        }
        dp[i][left][target] = res;
        return res;
    }
};
```
