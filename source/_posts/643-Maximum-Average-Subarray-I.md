---
title: 643. Maximum Average Subarray I
categories: Leetcode
date: 2024-10-21 17:50:58
tags:
    - Array
    - Sliding Window
---

[643. Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/description/)

## Description

You are given an integer array `nums` consisting of `n` elements, and an integer `k`.

Find a contiguous subarray whose **length is equal to**  `k` that has the maximum average value and return this value. Any answer with a calculation error less than `10^-5` will be accepted.

**Example 1:**

```bash
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
```

**Example 2:**

```bash
Input: nums = [5], k = 1
Output: 5.00000
```

**Constraints:**

- `n == nums.length`
- `1 <= k <= n <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

## Hints/Notes

- 2024/10/03
- sliding window
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = INT_MIN, sum = 0;
        int right = 0;
        while (right < nums.size()) {
            sum += nums[right];
            if (right >= k - 1) {
                res = max(res, sum / k);
                sum -= nums[right - k + 1];
            }
            right++;
        }
        return res;
    }
};
```
