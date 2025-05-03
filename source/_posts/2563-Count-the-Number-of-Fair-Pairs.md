---
title: 2563. Count the Number of Fair Pairs
categories: Leetcode
date: 2025-05-03 12:45:05
tags:
    - Array
    - Two Pointers
    - Binary Search
    - Sorting
---

[2563. Count the Number of Fair Pairs](https://leetcode.com/problems/count-the-number-of-fair-pairs/description/?envType=company&envId=google&favoriteSlug=google-thirty-days)

## Description

Given a **0-indexed**  integer array <code>nums</code> of size <code>n</code> and two integers <code>lower</code> and <code>upper</code>, return the number of fair pairs.

A pair <code>(i, j)</code> is <b>fair </b>if:

- <code>0 <= i < j < n</code>, and
- <code>lower <= nums[i] + nums[j] <= upper</code>

**Example 1:**

```bash
Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
```

**Example 2:**

```bash
Input: nums = [1,7,9,2,5], lower = 11, upper = 11
Output: 1
Explanation: There is a single fair pair: (2,3).
```

**Constraints:**

- <code>1 <= nums.length <= 10^5</code>
- <code>nums.length == n</code>
- <code>-10^9<= nums[i] <= 10^9</code>
- <code>-10^9<= lower <= upper <= 10^9</code>

## Hints/Notes

- 2025/04/29 Q2
- binary search
- [0x3F's solution](https://leetcode.cn/problems/count-the-number-of-fair-pairs/solutions/2107079/er-fen-cha-zhao-de-ling-huo-yun-yong-by-wplbj/?envType=company&envId=google&favoriteSlug=google-thirty-days)

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ranges::sort(nums);
        int n = nums.size();
        long long res = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] + nums[i + 1] > upper) {
                break;
            }
            int mi = lower - nums[i], mx = upper - nums[i];
            auto low = lower_bound(nums.begin() + i + 1, nums.end(), mi);
            auto high = --lower_bound(nums.begin() + i + 1, nums.end(), mx + 1);
            res += (high - low + 1);
        }
        return res;
    }
};
```
