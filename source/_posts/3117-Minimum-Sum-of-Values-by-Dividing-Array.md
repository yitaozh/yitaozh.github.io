---
title: 3117. Minimum Sum of Values by Dividing Array
categories: Leetcode
date: 2024-05-10 13:58:08
tags:
    - Array
    - Binary Search
    - Dynamic Programming
    - Bit Manipulation
    - Segment Tree
    - Queue
---

[3117. Minimum Sum of Values by Dividing Array](https://leetcode.com/problems/minimum-sum-of-values-by-dividing-array/description/)

## Description

You are given two arrays `nums` and `andValues` of length `n` and `m` respectively.

The **value**  of an array is equal to the **last**  element of that array.

You have to divide `nums` into `m` **disjoint contiguous**  subarrays such that for the `i^th` subarray `[li, ri]`, the bitwise `AND` of the subarray elements is equal to `andValues[i]`, in other words, `nums[li] & nums[li + 1] & ... & nums[ri] == andValues[i]` for all `1 <= i <= m`, where `&` represents the bitwise `AND` operator.

Return the **minimum**  possible sum of the **values**  of the `m` subarrays `nums` is divided into. If it is not possible to divide `nums` into `m` subarrays satisfying these conditions, return `-1`.

**Example 1:**

```bash
Input: nums = [1,4,3,3,2], andValues = [0,3,3,2]

Output: 12

Explanation:

The only possible way to divide `nums` is:

- `[1,4]` as `1 & 4 == 0`.
- `[3]` as the bitwise `AND` of a single element subarray is that element itself.
- `[3]` as the bitwise `AND` of a single element subarray is that element itself.
- `[2]` as the bitwise `AND` of a single element subarray is that element itself.

The sum of the values for these subarrays is `4 + 3 + 3 + 2 = 12`.
```

**Example 2:**

```bash
Input: nums = [2,3,5,7,7,7,5], andValues = [0,7,5]

Output: 17

Explanation:

There are three ways to divide `nums`:

- `[[2,3,5],[7,7,7],[5]]` with the sum of the values `5 + 7 + 5 == 17`.
- `[[2,3,5,7],[7,7],[5]]` with the sum of the values `7 + 7 + 5 == 19`.
- `[[2,3,5,7,7],[7],[5]]` with the sum of the values `7 + 7 + 5 == 19`.

The minimum possible sum of the values is `17`.
```

**Example 3:**

```bash
Input: nums = [1,2,3,4], andValues = [2]

Output: -1

Explanation:

The bitwise `AND` of the entire array `nums` is `0`. As there is no possible way to divide `nums` into a single subarray to have the bitwise `AND` of elements `2`, return `-1`.
```

**Constraints:**

- `1 <= n == nums.length <= 10^4`
- `1 <= m == andValues.length <= min(n, 10)`
- `1 <= nums[i] < 10^5`
- `0 <= andValues[j] < 10^5`

## Hints/Notes

- top-down dp

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        vector<vector<map<int, int>>> dp(nums.size() + 1, vector<map<int, int>>(andValues.size() + 1, map<int, int>()));
        int res = traverse(nums, andValues, 0, 0, -1, dp);
        return res >= 1e6 ? -1 : res;
    }

    int traverse(vector<int>& nums, vector<int>& andValues, int i, int j, int cur, vector<vector<map<int, int>>>& dp) {
        if (i == nums.size()) {
            if (j == andValues.size()) {
                return 0;
            } else {
                return 1e6;
            }
        }

        if (j == andValues.size()) {
            return 1e6;
        }

        if (dp[i][j].contains(cur)) return dp[i][j][cur];

        if (cur == -1) {
            cur = nums[i];
        } else {
            cur &= nums[i];
        }

        int ans = 0;
        if (cur == andValues[j]) {
            // we can choose to work on next addValue or not
            ans = min(nums[i] + traverse(nums, andValues, i + 1, j + 1, -1, dp), traverse(nums, andValues, i + 1, j, cur, dp));
        } else {
            ans = traverse(nums, andValues, i + 1, j, cur, dp);
        }
        dp[i][j][cur] = ans;
        return dp[i][j][cur];
    }
};
```
