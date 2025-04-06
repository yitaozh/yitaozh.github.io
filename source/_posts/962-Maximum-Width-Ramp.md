---
title: 962. Maximum Width Ramp
categories: Leetcode
date: 2025-04-05 18:49:15
tags:
    - Array
    - Two Pointers
    - Stack
    - Monotonic Stack
---

[962. Maximum Width Ramp](https://leetcode.com/problems/maximum-width-ramp/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-six-months)

## Description

A **ramp**  in an integer array `nums` is a pair `(i, j)` for which `i < j` and `nums[i] <= nums[j]`. The **width**  of such a ramp is `j - i`.

Given an integer array `nums`, return the maximum width of a **ramp**  in `nums`. If there is no **ramp**  in `nums`, return `0`.

**Example 1:**

```bash
Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.
```

**Example 2:**

```bash
Input: nums = [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.
```

**Constraints:**

- `2 <= nums.length <= 5 * 10^4`
- `0 <= nums[i] <= 5 * 10^4`

## Hints/Notes

- 2025/04/02 Q3
- monotonic queue
- [Leetcode solution](https://leetcode.com/problems/maximum-width-ramp/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> monotonic;
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            if (monotonic.empty() || nums[i] < nums[monotonic.back()]) {
                monotonic.push_back(i);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!monotonic.empty() && nums[monotonic.back()] <= nums[i]) {
                res = max(res, i - monotonic.back());
                monotonic.pop_back();
            }
        }
        return res;
    }
};
```
