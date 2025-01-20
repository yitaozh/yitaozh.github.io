---
title: 75. Sort Colors
categories: Leetcode
date: 2025-01-19 14:47:13
tags:
    - Array
    - Two Pointers
    - Sorting
---

[75. Sort Colors](https://leetcode.com/problems/sort-colors/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given an array `nums` with `n` objects colored red, white, or blue, sort them **<a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in-place</a>** so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers `0`, `1`, and `2` to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

**Example 1:**

```bash
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```

**Example 2:**

```bash
Input: nums = [2,0,1]
Output: [0,1,2]
```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 300`
- `nums[i]` is either `0`, `1`, or `2`.

**Follow up:** Could you come up with a one-pass algorithm using only constant extra space?

## Hints/Notes

- 2025/01/18
- two pointers
- [Good solution](https://leetcode.cn/problems/sort-colors/solutions/1868577/by-ac_oier-7lwk/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        for (int i = 0; i <= right; i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[left++]);
            } else if (nums[i] == 2) {
                swap(nums[i], nums[right--]);
                i--;
            }
        }
    }
};
```
