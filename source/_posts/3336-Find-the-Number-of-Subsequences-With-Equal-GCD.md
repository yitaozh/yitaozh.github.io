---
title: 3336. Find the Number of Subsequences With Equal GCD
categories: Leetcode
date: 2024-11-20 14:59:58
tags:
    - Array
    - Math
    - Dynamic Programming
    - Number Theory
---

[3336. Find the Number of Subsequences With Equal GCD](https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/description/)

## Description

You are given an integer array `nums`.

Your task is to find the number of pairs of **non-empty** subsequences `(seq1, seq2)` of `nums` that satisfy the following conditions:

- The subsequences `seq1` and `seq2` are **disjoint** , meaning **no index**  of `nums` is common between them.
- The GCD of the elements of `seq1` is equal to the GCD of the elements of `seq2`.

Return the total number of such pairs.

Since the answer may be very large, return it **modulo**  `10^9 + 7`.

**Example 1:**

```bash
Input: nums = [1,2,3,4]

Output: 10
```

Explanation:

The subsequence pairs which have the GCD of their elements equal to 1 are:

- ([**1**, 2, 3, 4], [1, **2**, **3**, 4])
- ([**1**, 2, 3, 4], [1, **2**, **3**, **4**])
- ([**1**, 2, 3, 4], [1, 2, **3**, **4**])
- ([**1**, **2**, 3, 4], [1, 2, **3**, **4**])
- ([**1**, 2, 3, **4**], [1, **2**, **3**, 4])
- ([1, **2**, **3**, 4], [**1**, 2, 3, 4])
- ([1, **2**, **3**, 4], [**1**, 2, 3, **4**])
- ([1, **2**, **3**, **4**], [**1**, 2, 3, 4])
- ([1, 2, **3**, **4**], [**1**, 2, 3, 4])
- ([1, 2, **3**, **4**], [**1**, **2**, 3, 4])

**Example 2:**

```bash
Input: nums = [10,20,30]

Output: 2
```

Explanation:

The subsequence pairs which have the GCD of their elements equal to 10 are:

- ([**10**, 20, 30], [10, **20**, **30**])
- ([10, **20**, **30**], [**10**, 20, 30])

**Example 3:**

```bash
Input: nums = [1,1,1,1]

Output: 50
```

**Constraints:**

- `1 <= nums.length <= 200`
- `1 <= nums[i] <= 200`

## Hints/Notes

- 2024/11/05
- [0x3F's solution](https://leetcode.cn/problems/find-the-number-of-subsequences-with-equal-gcd/solution/duo-wei-dppythonjavacgo-by-endlesscheng-5pk3/)
- Weekly Contest 421

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<vector<int>>> dp;
    int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {
        dp.resize(nums.size(), vector<vector<int>>(201, vector<int>(201, -1)));
        int res = dfs(0, 0, 0, nums);
        return res;
    }

    int dfs(int idx, int g1, int g2, vector<int>& nums) {
        if (idx == nums.size()) {
            return g1 == g2 && g1 != 0;
        }
        if (dp[idx][g1][g2] != -1) {
            return dp[idx][g1][g2];
        }
        int res = ((long)dfs(idx + 1, g1, g2, nums) +
                   dfs(idx + 1, gcd(g1, nums[idx]), g2, nums) +
                   dfs(idx + 1, g1, gcd(g2, nums[idx]), nums)) %
                  MOD;
        dp[idx][g1][g2] = res;
        return res;
    }
};
```
