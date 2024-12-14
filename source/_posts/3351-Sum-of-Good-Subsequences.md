---
title: 3351. Sum of Good Subsequences
categories: Leetcode
date: 2024-12-03 17:06:30
tags:
    - Array
    - Hash Table
    - Dynamic Programming
---

[3351. Sum of Good Subsequences](https://leetcode.com/problems/sum-of-good-subsequences/description/)

## Description

You are given an integer array `nums`. A **good** subsequence is defined as a subsequence of `nums` where the absolute difference between any **two** consecutive elements in the subsequence is **exactly** 1.

Return the **sum** of all possible **good subsequences** of `nums`.

Since the answer may be very large, return it **modulo** `10^9 + 7`.

**Note** that a subsequence of size 1 is considered good by definition.

**Example 1:**

```bash
Input: nums = [1,2,1]

Output: 14
```

Explanation:

- Good subsequences are: `[1]`, `[2]`, `[1]`, `[1,2]`, `[2,1]`, `[1,2,1]`.
- The sum of elements in these subsequences is 14.

**Example 2:**

```bash
Input: nums = [3,4,5]

Output: 40
```

Explanation:

- Good subsequences are: `[3]`, `[4]`, `[5]`, `[3,4]`, `[4,5]`, `[3,4,5]`.
- The sum of elements in these subsequences is 40.

**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^5`

## Hints/Notes

- 2024/11/25
- dp
- [0x3F's solution](https://leetcode.cn/problems/sum-of-good-subsequences/solutions/2983496/te-shu-zi-xu-lie-dppythonjavacgo-by-endl-vv7e/)(checked)
- Weekly Contest 423

## Solution

Language: **C++**

```C++
class Solution {
public:
    int MOD = 1'000'000'007;
    int sumOfGoodSubsequences(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, long> count, sum;
        for (int num : nums) {
            count[num] += (count[num - 1] + count[num + 1] + 1) % MOD;
            sum[num] += (sum[num - 1] + sum[num + 1]) % MOD;
            sum[num] += (long)(count[num - 1] + count[num + 1] + 1) % MOD  * num % MOD;
        }
        long res = 0;
        for (auto& [_, s] : sum) {
            res = (res + s) % MOD;
        }
        return res;
    }
};
```
