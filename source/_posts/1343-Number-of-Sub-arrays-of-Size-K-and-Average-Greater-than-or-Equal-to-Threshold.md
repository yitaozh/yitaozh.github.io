---
title: >-
  1343. Number of Sub-arrays of Size K and Average Greater than or Equal to
  Threshold
categories: Leetcode
date: 2024-10-21 17:55:13
tags:
  - Array
  - Sliding Window
---

# [1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/)

## Description

Given an array of integers `arr` and two integers `k` and `threshold`, return the number of sub-arrays of size `k` and average greater than or equal to `threshold`.

**Example 1:**

```bash
Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
Output: 3
Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).
```

**Example 2:**

```bash
Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
Output: 6
Explanation: The first 6 sub-arrays of size 3 have averages greater than 5. Note that averages are not integers.
```

**Constraints:**

- `1 <= arr.length <= 10^5`
- `1 <= arr[i] <= 10^4`
- `1 <= k <= arr.length`
- `0 <= threshold <= 10^4`

## Hints/Notes

- sliding window

## Solution

Language: **C++**

```C++
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int target = k * threshold, right = 0, sum = 0, res = 0;
        while (right < arr.size()) {
            sum += arr[right];
            if (right >= k - 1) {
                if (sum >= target) {
                    res++;
                }
                sum -= arr[right - k + 1];
            }
            right++;
        }
        return res;
    }
};
```
