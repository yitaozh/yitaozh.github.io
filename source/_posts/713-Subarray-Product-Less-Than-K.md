---
title: 713. Subarray Product Less Than K
categories: Leetcode
date: 2023-12-04 22:23:10
tags:
    - Array
    - Sliding Window
---

# [713\. Subarray Product Less Than K](https://leetcode.com/problems/subarray-product-less-than-k/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Sliding Window](https://leetcode.com/tag/https://leetcode.com/tag/sliding-window//)

Given an array of integers `nums` and an integer `k`, return _the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than_ `k`.

**Example 1:**

```bash
Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
```

**Example 2:**

```bash
Input: nums = [1,2,3], k = 0
Output: 0
```

**Constraints:**

* 1 <= nums.length <= 3 * 10<sup>4</sup>
* `1 <= nums[i] <= 1000`
* 0 <= k <= 10<sup>6</sup>

## Hints/Notes

* Sliding window
* How to calculate the subArray

## Solution

Language: **C++**

```C++
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, right = 0, res = 0;
        long prod = 1;
        while (right < nums.size()) {
            prod *= nums[right];
            if (prod >= k) {
                while (left <= right && prod >= k) {
                    prod /= nums[left++];
                }
            }
            res += right - left + 1;
            right++;
        }
        return res;
    }
};
```
