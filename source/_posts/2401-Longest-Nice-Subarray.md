---
title: 2401. Longest Nice Subarray
categories: Leetcode
date: 2025-03-28 03:01:40
tags:
    - Array
    - Bit Manipulation
    - Sliding Window
---

[2401. Longest Nice Subarray](https://leetcode.com/problems/longest-nice-subarray/description/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days)

## Description

You are given an array `nums` consisting of **positive**  integers.

We call a subarray of `nums` **nice**  if the bitwise **AND**  of every pair of elements that are in **different**  positions in the subarray is equal to `0`.

Return the length of the **longest**  nice subarray.

A **subarray**  is a **contiguous**  part of an array.

**Note**  that subarrays of length `1` are always considered nice.

**Example 1:**

```bash
Input: nums = [1,3,8,48,10]
Output: 3
Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
- 3 AND 8 = 0.
- 3 AND 48 = 0.
- 8 AND 48 = 0.
It can be proven that no longer nice subarray can be obtained, so we return 3.```

**Example 2:**

```bash
Input: nums = [3,1,5,11,13]
Output: 1
Explanation: The length of the longest nice subarray is 1. Any subarray of length 1 can be chosen.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`

## Hints/Notes

- 2025/03/18 Q2
- bit manipulation
- [Leetcode solution](https://leetcode.com/problems/longest-nice-subarray/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0, right = 0, n = nums.size(), curOr = 0, res = 0;
        while (right < n) {
            if ((curOr & nums[right]) == 0) {
                res = max(res, right - left + 1);
                curOr |= nums[right];
                right++;
            } else {
                curOr ^= nums[left];
                left++;
            }
        }
        return res;
    }
};
```
