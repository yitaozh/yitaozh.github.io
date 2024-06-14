---
title: 3176. Find the Maximum Length of a Good Subsequence I
categories: Leetcode
date: 2024-06-14 13:59:14
tags:
    - Array
    - Hash Table
    - Dynamic Programming
---

[3176. Find the Maximum Length of a Good Subsequence I](https://leetcode.com/problems/find-the-maximum-length-of-a-good-subsequence-i/description/)

## Description

You are given an integer array `nums` and a **non-negative**  integer `k`. A sequence of integers `seq` is called **good**  if there are **at most**  `k` indices `i` in the range `[0, seq.length - 2]` such that `seq[i] != seq[i + 1]`.

Return the **maximum**  possible length of a **good** subsequence of `nums`.

**Example 1:**

```bash
Input: nums = [1,2,1,1,3], k = 2

Output: 4

Explanation:

The maximum length subsequence is `[1,2,1,1,3]`.
```

**Example 2:**

```bash
Input: nums = [1,2,3,4,5,1], k = 0

Output: 2

Explanation:

The maximum length subsequence is `[1,2,3,4,5,1]`.
```

**Constraints:**

- `1 <= nums.length <= 500`
- `1 <= nums[i] <= 10^9`
- `0 <= k <= min(nums.length, 25)`

## Hints/Notes

- Biweenly Contest 132
- dp

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> dp;

    int maximumLength(vector<int>& nums, int k) {
        int size = nums.size();
        dp.resize(size, vector<int>(k + 1, INT_MIN));
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res = max(res, traverse(i, k, nums));
        }
        return res;
    }

    int traverse(int curIndex, int remaining, vector<int>& nums) {
        if (remaining < 0) {
            return 0;
        }
        if (curIndex == nums.size()) {
            return 0;
        }
        if (curIndex == nums.size() - 1) {
            return 1;
        }
        if (dp[curIndex][remaining] != INT_MIN) {
            return dp[curIndex][remaining];
        }
        int res = 0;
        for (int i = curIndex + 1; i < nums.size(); i++) {
            if (nums[curIndex] == nums[i]) {
                res = max(res, traverse(i, remaining, nums) + 1);
            } else {
                res = max(res, traverse(i, remaining - 1, nums) + 1);
            }
        }
        dp[curIndex][remaining] = res;
        return res;
    }
};
```
