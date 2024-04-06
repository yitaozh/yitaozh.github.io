---
title: 523. Continuous Subarray Sum
categories: Leetcode
date: 2023-11-12 23:59:25
tags:
    - Array
    - Hash Table
    - Math
    - Prefix Sum
---

[523\. Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [Math](https://leetcode.com/tag/https://leetcode.com/tag/math//), [Prefix Sum](https://leetcode.com/tag/https://leetcode.com/tag/prefix-sum//)

Given an integer array nums and an integer k, return `true` _if_ `nums` _has a **good subarray** or_ `false` _otherwise_.

A **good subarray** is a subarray where:

* its length is **at least two**, and
* the sum of the elements of the subarray is a multiple of `k`.

**Note** that:

* A **subarray** is a contiguous part of the array.
* An integer `x` is a multiple of `k` if there exists an integer `n` such that `x = n * k`. `0` is **always** a multiple of `k`.

**Example 1:**

```bash
Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
```

**Example 2:**

```bash
Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
```

**Example 3:**

```bash
Input: nums = [23,2,6,4,7], k = 13
Output: false
```

**Constraints:**

* 1 <= nums.length <= 10<sup>5</sup>
* 0 <= nums[i] <= 10<sup>9</sup>
* 0 <= sum(nums[i]) <= 2<sup>31</sup> - 1
* 1 <= k <= 2<sup>31</sup> - 1

## Hints/Notes

* preSum + map

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> preSum(size + 1, 0);
        for (int i = 0; i < size; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        map<int, int> m;
        for (int i = 0; i <= size; i++) {
            if (m.count(preSum[i] % k)) {
                int idx = m[preSum[i] % k];
                if (i - idx > 1) {
                    return true;
                }
            } else {
                m[preSum[i] % k] = i;
            }
        }
        return false;
    }
};
```
