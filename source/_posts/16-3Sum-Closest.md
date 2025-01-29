---
title: 16. 3Sum Closest
categories: Leetcode
date: 2025-01-29 00:46:29
tags:
    - Array
    - Two Pointers
    - Sorting
---

[16. 3Sum Closest](https://leetcode.com/problems/3sum-closest/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given an integer array `nums` of length `n` and an integer `target`, find three integers in `nums` such that the sum is closest to `target`.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

**Example 1:**

```bash
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```

**Example 2:**

```bash
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
```

**Constraints:**

- `3 <= nums.length <= 500`
- `-1000 <= nums[i] <= 1000`
- `-10^4 <= target <= 10^4`

## Hints/Notes

- 2025/01/28
- two pointers
- [0x3F's solution](https://leetcode.cn/problems/3sum-closest/solutions/2337801/ji-zhi-you-hua-ji-yu-san-shu-zhi-he-de-z-qgqi/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

sort

```C++
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = INT_MAX / 2;
        ranges::sort(nums);
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] + nums[i + 1] + nums[i + 2] >= target) {
                if (abs(nums[i] + nums[i + 1] + nums[i + 2] - target) < abs(res - target)) {
                    res = nums[i] + nums[i + 1] + nums[i + 2];
                }
                break;
            }
            if (nums[i] + nums[n - 2] + nums[n - 1] <= target) {
                if (abs(nums[i] + nums[n - 2] + nums[n - 1] - target) < abs(res - target)) {
                    res = nums[i] + nums[n - 2] + nums[n - 1];
                }
                continue;
            }
            int l = i + 1, r = nums.size() - 1, t = target - nums[i];
            while (l < r) {
                if (nums[l] + nums[r] == t) {
                    return target;
                }
                if (abs(nums[i] + nums[l] + nums[r] - target) < abs(res - target)) {
                   res = nums[i] + nums[l] + nums[r];
                }
                if (nums[l] + nums[r] < t) {
                    l++;
                } else {
                    r--;
                }
            }
            while (i < nums.size() - 2 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        return res;
    }
};
```

O(n^3) solution

```C++
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = INT_MAX / 2;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (abs(sum - target) < abs(res - target)) {
                        res = sum;
                    }
                }
            }
        }
        return res;
    }
};
```