---
title: 3251. Find the Count of Monotonic Pairs II
categories: Leetcode
date: 2024-08-15 00:07:46
tags:
    - Array
    - Math
    - Dynamic Programming
    - Combinatorics
    - Prefix Sum
---

[3251. Find the Count of Monotonic Pairs II](https://leetcode.com/problems/find-the-count-of-monotonic-pairs-ii/description/)

## Description

You are given an array of **positive**  integers `nums` of length `n`.

We call a pair of **non-negative**  integer arrays `(arr1, arr2)` **monotonic**  if:

- The lengths of both arrays are `n`.
- `arr1` is monotonically **non-decreasing** , in other words, `arr1[0] <= arr1[1] <= ... <= arr1[n - 1]`.
- `arr2` is monotonically **non-increasing** , in other words, `arr2[0] >= arr2[1] >= ... >= arr2[n - 1]`.
- `arr1[i] + arr2[i] == nums[i]` for all `0 <= i <= n - 1`.

Return the count of **monotonic**  pairs.

Since the answer may be very large, return it **modulo**  `10^9 + 7`.

**Example 1:**

```bash
Input: nums = [2,3,2]

Output: 4
```

Explanation:

The good pairs are:

- `([0, 1, 1], [2, 2, 1])`
- `([0, 1, 2], [2, 2, 0])`
- `([0, 2, 2], [2, 1, 0])`
- `([1, 2, 2], [1, 1, 0])`

**Example 2:**

```bash
Input: nums = [5,5,5,5]

Output: 126
```

**Constraints:**

- `1 <= n == nums.length <= 2000`
- `1 <= nums[i] <= 1000`

## Hints/Notes

- dp
- preSum
- Weekly Contest 410

## Solution

Language: **C++**

```C++
class Solution {
public:
    // dp[index][arr1]: at index, when the num1 is equal to arr1, the number of
    // valid monotonic pairs
    vector<vector<int>> dp;
    int MOD = 1000000007;

    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, vector<int>(1001, 0));
        vector<long> preSum(1002, 0);
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = 0; j <= nums[i]; j++) {
                if (i == nums.size() - 1) {
                    dp[i][j] = 1;
                    continue;
                }
                long long res = 0;
                // at index i, assume the number is j, the transition is:
                // at i + 1, the arr1 value k must be >= j,
                // i.e. k >= j
                // at i + 1, the arr2 value nums[i + 1] - k must be <= nums[i] -
                // j and the arr2 value must be >= 0 i.e 1. nums[i + 1] - k <=
                // nums[i] - j
                //     => k >= nums[i + 1] - nums[i] + j
                //     2. nums[i + 1] - k >= 0
                //     => k <= nums[i + 1]
                int start = max(j, nums[i + 1] - nums[i] + j);
                int end = nums[i + 1];
                dp[i][j] =
                    end >= start
                        ? ((preSum[end + 1] - preSum[start]) % MOD + MOD) % MOD
                        : 0;
            }
            for (int j = 0; j < dp[i].size(); j++) {
                preSum[j + 1] = (preSum[j] + dp[i][j]) % MOD;
            }
        }
        long long res = 0;
        for (int i = 0; i <= 1000; i++) {
            res = (res + dp[0][i]) % 1000000007;
        }
        return res;
    }
};
```
