---
title: 3130. Find All Possible Stable Binary Arrays II
categories: Leetcode
date: 2024-05-16 00:34:38
tags:
    - Dynamic Programming
    - Prefix Sum
---

[3130. Find All Possible Stable Binary Arrays II](https://leetcode.com/problems/find-all-possible-stable-binary-arrays-ii/description/)

You are given 3 positive integers `zero`, `one`, and `limit`.

A binary array `arr` is called **stable**  if:

- The number of occurrences of 0 in `arr` is **exactly** `zero`.
- The number of occurrences of 1 in `arr` is **exactly**  `one`.
- Each subarray of `arr` with a size greater than `limit` must contain **both** 0 and 1.

Return the total number of **stable**  binary arrays.

Since the answer may be very large, return it **modulo**  `10^9 + 7`.

**Example 1:**

```bash
Input: zero = 1, one = 1, limit = 2

Output: 2

Explanation:

The two possible stable binary arrays are `[1,0]` and `[0,1]`.
```

**Example 2:**

```bash
Input: zero = 1, one = 2, limit = 1

Output: 1

Explanation:

The only possible stable binary array is `[1,0,1]`.
```

**Example 3:**

```bash
Input: zero = 3, one = 3, limit = 2

Output: 14

Explanation:

All the possible stable binary arrays are `[0,0,1,0,1,1]`, `[0,0,1,1,0,1]`, `[0,1,0,0,1,1]`, `[0,1,0,1,0,1]`, `[0,1,0,1,1,0]`, `[0,1,1,0,0,1]`, `[0,1,1,0,1,0]`, `[1,0,0,1,0,1]`, `[1,0,0,1,1,0]`, `[1,0,1,0,0,1]`, `[1,0,1,0,1,0]`, `[1,0,1,1,0,0]`, `[1,1,0,0,1,0]`, and `[1,1,0,1,0,0]`.
```

**Constraints:**

- `1 <= zero, one, limit <= 1000`

## Hints/Notes

- need to find the O(1) state transition equation for dp

## Solution

Language: **C++**

```C++
class Solution {
public:
    int limit_;
    int mod_;
    vector<vector<vector<int>>> dp;

    int numberOfStableArrays(int zero, int one, int limit) {
        limit_ = limit;
        mod_ = 1e9 + 7;
        dp = vector<vector<vector<int>>>(
            2, vector<vector<int>>(1001, vector<int>(1001, -1)));
        return ((traverse(0, zero, one) + traverse(1, zero, one)) % mod_ + mod_) % mod_;
    }

    int traverse(int end, int zero, int one) {
        if (zero == 0 && one == 0) {
            return 1;
        }
        if (zero == 0) {
            if (end == 1 && one <= limit_) {
                return 1;
            } else {
                return 0;
            }
        }
        if (one == 0) {
            if (end == 0 && zero <= limit_) {
                return 1;
            } else {
                return 0;
            }
        }
        if (zero < 0 || one < 0) {
            return 0;
        }
        if (dp[end][zero][one] != -1) {
            return dp[end][zero][one];
        }
        if (dp[1 - end][one][zero] != -1) {
            dp[end][zero][one] = dp[1 - end][one][zero];
            return dp[end][zero][one];
        }
        long long ans = 0;
        if (end == 0) {
            ans = ((long)traverse(0, zero - 1, one) % mod_ - traverse(1, zero - limit_ - 1, one) % mod_ + traverse(1, zero - 1, one) % mod_) % mod_;
        } else {
            ans = ((long)traverse(1, zero, one - 1) % mod_ - traverse(0, zero, one - limit_ - 1) % mod_ + traverse(0, zero, one - 1) % mod_) % mod_;
        }
        dp[end][zero][one] = (ans + mod_) % mod_;
        return ans;
    }
};
```
