---
title: 974. Subarray Sums Divisible by K
categories: Leetcode
date: 2023-01-19 18:20:04
tags:
    - Array
    - Hash Table
    - Prefix Sum
---

# [1016\. Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

Given an integer array `nums` and an integer `k`, return _the number of non-empty **subarrays** that have a sum divisible by_ `k`.

A **subarray** is a **contiguous** part of an array.

**Example 1:**

```
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
```

**Example 2:**

```
Input: nums = [5], k = 9
Output: 0
```

**Constraints:**

*   1 <= nums.length <= 3 * 10<sup>4</sup>
*   -10<sup>4</sup> <= nums[i] <= 10<sup>4</sup>
*   2 <= k <= 10<sup>4</sup>

## Solution

Language: **C++**

```C++
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> preSumMod(k, 0);
        int res = 0, preSum = 0;
        preSumMod[0] = 1;
        for (int num : nums) {
            preSum = (num % k + k + preSum) % k;
            res += preSumMod[preSum];
            preSumMod[preSum]++;
        }
        return res;
    }
};
```