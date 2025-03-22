---
title: 3471. Find the Largest Almost Missing Integer
categories: Leetcode
date: 2025-03-10 02:30:50
tags:
    - Array
    - Hash Table
---

[3471. Find the Largest Almost Missing Integer](https://leetcode.com/problems/find-the-largest-almost-missing-integer/description/)

## Description

You are given an integer array `nums` and an integer `k`.

An integer `x` is **almost missing**  from `nums` if `x` appears in exactly one subarray of size `k` within `nums`.

Return the **largest almost missing** integer from `nums`. If no such integer exists, return `-1`.
A **subarray**  is a contiguous sequence of elements within an array.

**Example 1:**

```bash
Input: nums = [3,9,2,1,7], k = 3

Output: 7
```

Explanation:

- 1 appears in 2 subarrays of size 3: `[9, 2, 1]` and `[2, 1, 7]`.
- 2 appears in 3 subarrays of size 3: `[3, 9, 2]`, `[9, 2, 1]`, `[2, 1, 7]`.
- 3 appears in 1 subarray of size 3: `[3, 9, 2]`.
- 7 appears in 1 subarray of size 3: `[2, 1, 7]`.
- 9 appears in 2 subarrays of size 3: `[3, 9, 2]`, and `[9, 2, 1]`.

We return 7 since it is the largest integer that appears in exactly one subarray of size `k`.

**Example 2:**

```bash
Input: nums = [3,9,7,2,1,7], k = 4

Output: 3
```

Explanation:

- 1 appears in 2 subarrays of size 4: `[9, 7, 2, 1]`, `[7, 2, 1, 7]`.
- 2 appears in 3 subarrays of size 4: `[3, 9, 7, 2]`, `[9, 7, 2, 1]`, `[7, 2, 1, 7]`.
- 3 appears in 1 subarray of size 4: `[3, 9, 7, 2]`.
- 7 appears in 3 subarrays of size 4: `[3, 9, 7, 2]`, `[9, 7, 2, 1]`, `[7, 2, 1, 7]`.
- 9 appears in 2 subarrays of size 4: `[3, 9, 7, 2]`, `[9, 7, 2, 1]`.

We return 3 since it is the largest and only integer that appears in exactly one subarray of size `k`.

**Example 3:**

```bash
Input: nums = [0,0], k = 1

Output: -1
```

Explanation:

There is no integer that appears in only one subarray of size 1.

**Constraints:**

- `1 <= nums.length <= 50`
- `0 <= nums[i] <= 50`
- `1 <= k <= nums.length`

## Hints/Notes

- 2025/02/28 Q1
- brain teaser
- [0x3F's solution](https://leetcode.cn/problems/find-the-largest-almost-missing-integer/solutions/3591774/on-zuo-fa-nao-jin-ji-zhuan-wan-pythonjav-y0q3/)
- Weekly Contest 439

## Solution

Language: **C++**

```C++
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size(), res = -1;
        unordered_map<int, int> m;
        for (int i = 0; i < n - k + 1; i++) {
            unordered_set<int> s;
            for (int j = i; j < i + k; j++) {
                s.insert(nums[j]);
            }
            for (auto& k : s) {
                m[k]++;
            }
        }
        for (auto& [k, v] : m) {
            if (v == 1) {
                res = max(res, k);
            }
        }
        return res;
    }
};
```
