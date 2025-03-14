---
title: 2348. Number of Zero-Filled Subarrays
categories: Leetcode
date: 2025-03-14 01:58:25
tags:
    - Array
    - Math
---

[2348. Number of Zero-Filled Subarrays](https://leetcode.com/problems/number-of-zero-filled-subarrays/description/)

## Description

Given an integer array `nums`, return the number of **subarrays**  filled with `0`.

A **subarray**  is a contiguous non-empty sequence of elements within an array.

**Example 1:**

```bash
Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
Explanation:
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.```

**Example 2:**

```bash
Input: nums = [0,0,0,2,0,0]
Output: 9
**Explanation:
** There are 5 occurrences of [0] as a subarray.
There are 3 occurrences of [0,0] as a subarray.
There is 1 occurrence of [0,0,0] as a subarray.
There is no occurrence of a subarray with a size more than 3 filled with 0. Therefore, we return 9.
```

**Example 3:**

```bash
Input: nums = [2,10,2019]
Output: 0
Explanation: There is no subarray filled with 0. Therefore, we return 0.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

## Hints/Notes

- 2025/03/05 Q3
- math
- [0x3F's solution](https://leetcode.cn/problems/number-of-zero-filled-subarrays/solutions/1693356/by-endlesscheng-men8/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    // [0]: 1
    // [0, 0]: 3
    // [0, 0, 0]:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> numZeroArrays(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            numZeroArrays[i] = i + numZeroArrays[i - 1];
        }
        long long res = 0;
        for (int i = 0; i < n; ) {
            if (nums[i] == 0) {
                int start = i;
                while (i < n && nums[i] == 0) {
                    i++;
                }
                int numOfZero =  i - start;
                res += numZeroArrays[numOfZero];
            } else {
                i++;
            }
        }
        return res;
    }
};
```
