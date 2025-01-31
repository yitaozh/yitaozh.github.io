---
title: 163. Missing Ranges
categories: Leetcode
date: 2025-01-31 17:37:26
tags:
    - Array
---

[163. Missing Ranges](https://leetcode.com/problems/missing-ranges/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

You are given an inclusive range `[lower, upper]` and a **sorted unique**  integer array `nums`, where all elements are within the inclusive range.

A number `x` is considered **missing**  if `x` is in the range `[lower, upper]` and `x` is not in `nums`.

Return the **shortest sorted**  list of ranges that <b>exactly covers all the missing numbers</b>. That is, no element of `nums` is included in any of the ranges, and each missing number is covered by one of the ranges.

**Example 1:**

```bash
Input: nums = [0,1,3,50,75], lower = 0, upper = 99
Output: [[2,2],[4,49],[51,74],[76,99]]
Explanation: The ranges are:
[2,2]
[4,49]
[51,74]
[76,99]
```

**Example 2:**

```bash
Input: nums = [-1], lower = -1, upper = -1
Output: []
Explanation: There are no missing ranges since there are no missing numbers.
```

**Constraints:**

- `-10^9 <= lower <= upper <= 10^9`
- `0 <= nums.length <= 100`
- `lower <= nums[i] <= upper`
- All the values of `nums` are **unique** .

## Hints/Notes

- 2025/01/31
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> res;
        for (int num : nums) {
            if (num > lower) {
                res.push_back({lower, num - 1});
            }
            lower = num + 1;
        }
        if (lower <= upper) {
            res.push_back({lower, upper});
        }
        return res;
    }
};
```
