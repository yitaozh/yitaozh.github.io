---
title: 3428. Maximum and Minimum Sums of at Most Size K Subsequences
categories: Leetcode
date: 2025-01-27 12:45:58
tags:
    - Array
    - Math
    - Dynamic Programming
    - Sorting
    - Combinatorics
---

[3428. Maximum and Minimum Sums of at Most Size K Subsequences](https://leetcode.com/problems/maximum-and-minimum-sums-of-at-most-size-k-subsequences/description/)

## Description

You are given an integer array `nums` and a positive integer `k`. Return the sum of the **maximum**  and **minimum**  elements of all **subsequences**  of `nums` with **at most**  `k` elements.

Since the answer may be very large, return it **modulo**  `10^9 + 7`.

**Example 1:**

```bash
Input: nums = [1,2,3], k = 2

Output: 24
```

Explanation:

The subsequences of `nums` with at most 2 elements are:

<table style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left=""><tbody><tr><th style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left=""><b>Subsequence </b></th><th style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">Minimum</th><th style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">Maximum</th><th style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">Sum</th></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">[1]</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">1</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">1</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">2</td></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">[2]</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">2</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">2</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">4</td></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">[3]</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">3</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">3</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">6</td></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">[1, 2]</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">1</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">2</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">3</td></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">[1, 3]</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">1</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">3</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">4</td></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">[2, 3]</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">2</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">3</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">5</td></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">Final Total</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left=""></td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left=""></td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">24</td></tr></tbody></table>

The output would be 24.

**Example 2:**

<div class="example-block">
Input: nums = [5,0,6], k = 1

Output: 22

Explanation:

For subsequences with exactly 1 element, the minimum and maximum values are the element itself. Therefore, the total is `5 + 5 + 0 + 0 + 6 + 6 = 22`.

**Example 3:**

<div class="example-block">
Input: nums = [1,1,1], k = 2

Output: 12

Explanation:

The subsequences `[1, 1]` and `[1]` each appear 3 times. For all of them, the minimum and maximum are both 1. Thus, the total is 12.

**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^9`
- `1 <= k <= min(70, nums.length)`

## Hints/Notes

- 2025/01/25
- combinatorics
- [0x3F's solution](https://leetcode.cn/problems/maximum-and-minimum-sums-of-at-most-size-k-subsequences/solutions/3051549/gong-xian-fa-zu-he-shu-xue-pythonjavacgo-0jod/)
- Weekly Contest 433

## Solution

Language: **C++**

```C++
class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> fac, inv;
    int n;

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

    int minMaxSums(vector<int>& nums, int k) {
        n = nums.size();
        fac.resize(n, 1);
        inv.resize(n, 1);
        init();
        // look at each number, how many times it's taken as smallest number
        // and how many times it's taken as maximum number
        // sort first
        // for nums[0], it's taken as smallest number in
        // k = 1, with C(n - 1, 0)
        // k = 2, with C(n - 1, 1)
        // k = 3, with C(n - 1, 2)
        // k = 4, with C(n - 1, 3)
        // ...
        // k = k, with C(n - 1, k - 1)
        // for nums[1], it's taken as smallest number in
        // k = 1, with C(n - 2, 0),
        // k = 2, with C(n - 2, 1),
        // ...
        // k = k, with C(n - 2, k - 1)
        // for one number, how many times does it been taken as maximum number?
        // it's the same as maximum number
        long res = 0;
        ranges::sort(nums);
        for (int i = 0; i < n; i++) {
            // n - 1 - i - j >= 0, j <= n - 1 - i => j < n - i
            for (int j = 0; j < min(k, n - i); j++) {
                res = (res + (long)fac[n - 1 - i] * inv[j] % MOD * inv[n - 1 - i - j] % MOD * nums[i] % MOD) % MOD;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < min(k, i + 1); j++) {
                res = (res + (long)fac[i] * inv[j] % MOD * inv[i - j] % MOD * nums[i] % MOD) % MOD;
            }
        }
        return res;
    }
};
```
