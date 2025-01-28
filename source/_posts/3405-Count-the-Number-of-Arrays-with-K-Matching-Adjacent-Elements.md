---
title: 3405. Count the Number of Arrays with K Matching Adjacent Elements
categories: Leetcode
date: 2025-01-10 17:03:53
tags:
    - Math
    - Combinatorics
---

[3405. Count the Number of Arrays with K Matching Adjacent Elements](https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/description/)

## Description

You are given three integers `n`, `m`, `k`. A **good array**  `arr` of size `n` is defined as follows:

- Each element in `arr` is in the **inclusive**  range `[1, m]`.
- Exactly `k` indices `i` (where `1 <= i < n`) satisfy the condition `arr[i - 1] == arr[i]`.

Return the number of **good arrays**  that can be formed.

Since the answer may be very large, return it **modulo** `10^9 + 7`.

**Example 1:**

```bash
Input: n = 3, m = 2, k = 1

Output: 4
```

Explanation:

- There are 4 good arrays. They are `[1, 1, 2]`, `[1, 2, 2]`, `[2, 1, 1]` and `[2, 2, 1]`.
- Hence, the answer is 4.

**Example 2:**

```bash
Input: n = 4, m = 2, k = 2

Output: 6
```

Explanation:

- The good arrays are `[1, 1, 1, 2]`, `[1, 1, 2, 2]`, `[1, 2, 2, 2]`, `[2, 1, 1, 1]`, `[2, 2, 1, 1]` and `[2, 2, 2, 1]`.
- Hence, the answer is 6.

**Example 3:**

```bash
Input: n = 5, m = 2, k = 0

Output: 2
```

Explanation:

- The good arrays are `[1, 2, 1, 2, 1]` and `[2, 1, 2, 1, 2]`. Hence, the answer is 2.

**Constraints:**

- `1 <= n <= 10^5`
- `1 <= m <= 10^5`
- `0 <= k <= n - 1`

## Hints/Notes

- 2025/01/11
- Combinatorics
- [0x3F's solution](https://leetcode.cn/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/solutions/3033292/chun-shu-xue-ti-pythonjavacgo-by-endless-mxj7/)(checked)
- Weekly Contest 430

## Solution

Language: **C++**

```C++
class Solution {
public:
    int n;
    const int MOD = 1e9 + 7;
    vector<int> fac, inv;

    // [a good explanation of inv](https://fooage.github.io/fooage/algorithm/2021/02/16/%E4%B9%98%E6%B3%95%E9%80%86%E5%85%83%E4%B8%8E%E7%BB%84%E5%90%88%E6%95%B0%E5%AE%9A%E7%90%86.html)
    void init() {
        for (int i = 1; i < n; i++) {
            fac[i] = (long)fac[i - 1] * i % MOD;
        }
        // now to calculate inv(逆元)
        // 费马小定理：(a / b) mod p = a * b ^(p - 2) mod p (when p is a prime number)
        inv[n - 1] = qpow(fac[n - 1], MOD - 2);
        // now we get the inv of fac[n], to get inv of fac[n - 1]
        // fac[n - 1] = fac[n] / n
        // fac[n] * inv[n] = 1 mod p
        // fac[n - 1] * n * inv[n] = 1 mod p
        // n * inv[n] is inv[n - 1]
        for (int i = n - 2; i >= 1; i--) {
            inv[i] = (long)inv[i + 1] * (i + 1) % MOD;
        }
    }

    int qpow(int b, int n) {
        int res = 1;
        while (n) {
            if (n % 2) {
                res = (long)res * b % MOD;
            }
            b = (long)b * b % MOD;
            n >>= 1;
        }
        return res;
    }

    int countGoodArrays(int n, int m, int k) {
        // there are k indexes with arr[i - 1] = arr[i]
        // which means, among a total of n - 1 intervals
        // there are k different interval with the same number on left and right
        // and there are n - k - 1 intervals with different number on left and right
        // i.e. we need to put n - k - 1 lines in in n - 1 slots
        // C(n - 1, n - k - 1) * m * (m - 1) ^ (n - k - 1)
        // the C number is fac[n - 1] * inv[n - k - 1] * inv[k]
        this->n = n;
        fac.resize(n, 1);
        inv.resize(n, 1);
        init();
        return (long)fac[n - 1] * inv[n - k - 1] % MOD * inv[k] % MOD
                * m % MOD * qpow(m - 1, n - k - 1) % MOD;
    }
};
```
