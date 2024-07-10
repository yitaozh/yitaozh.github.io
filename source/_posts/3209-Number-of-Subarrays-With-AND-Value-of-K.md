---
title: 3209. Number of Subarrays With AND Value of K
categories: Leetcode
date: 2024-07-10 00:22:19
tags:
    - Array
    - Binary Search
    - Bit Manipulation
    - Segment Tree
---

# [3209. Number of Subarrays With AND Value of K](https://leetcode.com/problems/number-of-subarrays-with-and-value-of-k/description/)

## Description

Given an array of integers `nums` and an integer `k`, return the number of <div aria-expanded="false" data-headlessui-state="" id="headlessui-popover-button-:rj:">subarrays<div style="position: fixed; z-index: 40; inset: 0px auto auto 0px; transform: translate(503px, 214px);"> of `nums` where the bitwise `AND` of the elements of the subarray equals `k`.

**Example 1:**

```bash
Input: nums = [1,1,1], k = 1

Output: 6
```

Explanation:

All subarrays contain only 1's.

**Example 2:**

```bash
Input: nums = [1,1,2], k = 1

Output: 3
```

Explanation:

Subarrays having an `AND` value of 1 are: `[**1** ,1,2]`, `[1,**1** ,2]`, `[**1,1** ,2]`.

**Example 3:**

```bash
Input: nums = [1,2,3], k = 2

Output: 2
```

Explanation:

Subarrays having an `AND` value of 2 are: `[1,<b>2</b>,3]`, `[1,**2,3** ]`.

**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i], k <= 10^9`

## Hints/Notes

- logTrick
- Biweekly Contest 134

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long res = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int j = i - 1; j >= 0; j--) {
                if ((nums[j] & x) == nums[j]) {
                    break;
                }
                nums[j] &= x;
            }
            int left = findLeft(nums, 0, i, k);
            int right = findRight(nums, 0, i, k);
            res += right - left;
        }
        return res;
    }

    int findLeft(vector<int>& nums, int low, int high, int k) {
        int left = low, right = high;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == k) {
                right = mid - 1;
            } else if (nums[mid] < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    int findRight(vector<int>& nums, int low, int high, int k) {
        int left = low, right = high;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == k) {
                left = mid + 1;
            } else if (nums[mid] < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
```
