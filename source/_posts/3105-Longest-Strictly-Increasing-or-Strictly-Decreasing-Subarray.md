---
title: 3105. Longest Strictly Increasing or Strictly Decreasing Subarray
categories: Leetcode
date: 2024-05-07 23:47:15
tags:
    - Array
---

[3105. Longest Strictly Increasing or Strictly Decreasing Subarray](https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/)

You are given an array of integers `nums`. Return the length of the **longest**  subarray of `nums` which is either **strictly increasing**  or **strictly decreasing**.

**Example 1:**

```bash
Input: nums = [1,4,3,3,2]

Output: 2

Explanation:

The strictly increasing subarrays of `nums` are `[1]`, `[2]`, `[3]`, `[3]`, `[4]`, and `[1,4]`.

The strictly decreasing subarrays of `nums` are `[1]`, `[2]`, `[3]`, `[3]`, `[4]`, `[3,2]`, and `[4,3]`.

Hence, we return `2`.
```

**Example 2:**

```bash
Input: nums = [3,3,3,3]

Output: 1

Explanation:

The strictly increasing subarrays of `nums` are `[3]`, `[3]`, `[3]`, and `[3]`.

The strictly decreasing subarrays of `nums` are `[3]`, `[3]`, `[3]`, and `[3]`.

Hence, we return `1`.
```

**Example 3:**

```bash
Input: nums = [3,2,1]

Output: 3

Explanation:

The strictly increasing subarrays of `nums` are `[3]`, `[2]`, and `[1]`.

The strictly decreasing subarrays of `nums` are `[3]`, `[2]`, `[1]`, `[3,2]`, `[2,1]`, and `[3,2,1]`.

Hence, we return `3`.
```

**Constraints:**

- `1 <= nums.length <= 50`
- `1 <= nums[i] <= 50`

## Hints/Notes

- iterate the array twice

## Solution

Language: **C++**

```C++
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 1;
        int curLen = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                curLen += 1;
                res = max(res, curLen);
            } else {
                curLen = 1;
            }
        }
        curLen = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                curLen += 1;
                res = max(res, curLen);
            } else {
                curLen = 1;
            }
        }
        return res;
    }
};
```
