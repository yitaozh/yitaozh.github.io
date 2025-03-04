---
title: 3255. Find the Power of K-Size Subarrays II
categories: Leetcode
date: 2024-10-03 11:10:47
tags:
    - Array
    - Sliding Window
---

[3255. Find the Power of K-Size Subarrays II](https://leetcode.com/problems/find-the-power-of-k-size-subarrays-ii/)

## Description

You are given an array of integers `nums` of length `n` and a positive integer `k`.

The **power**  of an array is defined as:

- Its **maximum**  element if all of its elements are **consecutive**  and **sorted**  in **ascending**  order.
- -1 otherwise.

You need to find the **power**  of all subarrays of `nums` of size `k`.

Return an integer array `results` of size `n - k + 1`, where `results[i]` is the power of `nums[i..(i + k - 1)]`.

**Example 1:**

```bash
Input: nums = [1,2,3,4,3,2,5], k = 3

Output: [3,4,-1,-1,-1]
```

Explanation:

There are 5 subarrays of `nums` of size 3:

- `[1, 2, 3]` with the maximum element 3.
- `[2, 3, 4]` with the maximum element 4.
- `[3, 4, 3]` whose elements are **not**  consecutive.
- `[4, 3, 2]` whose elements are **not**  sorted.
- `[3, 2, 5]` whose elements are **not**  consecutive.

**Example 2:**

```bash
Input: nums = [2,2,2,2,2], k = 4

Output: [-1,-1]
```

**Example 3:**

```bash
Input: nums = [3,2,3,2,3,2], k = 2

Output: [-1,3,-1,3,-1]
```

**Constraints:**

- `1 <= n == nums.length <= 10^5`
- `1 <= nums[i] <= 10^6`
- `1 <= k <= n`

## Hints/Notes

- 2024/08/17
- Sliding window
- The same as 3254
- [0x3F's solution](https://leetcode.cn/problems/find-the-power-of-k-size-subarrays-ii/solutions/2884189/on-jian-ji-xie-fa-pythonjavacgo-by-endle-gtek/)(checked)
- Biweekly Contest 137

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int prev = 0, curLen = 0, right = 0;
        vector<int> res;
        while (right < nums.size()) {
            if (prev == -1 || (prev == nums[right] - 1)) {
                curLen++;
            } else {
                curLen = 0;
            }
            if (right >= k - 1) {
                if (curLen >= k - 1) {
                    res.push_back(nums[right]);
                } else {
                    res.push_back(-1);
                }
            }
            prev = nums[right++];
        }
        return res;
    }
};
```
