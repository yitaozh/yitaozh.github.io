---
title: 560. Subarray Sum Equals K
categories: Leetcode
date: 2023-11-13 00:22:31
tags:
    - Array
    - Hash Table
    - Prefix Sum
---

[560\. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [Prefix Sum](https://leetcode.com/tag/https://leetcode.com/tag/prefix-sum//)

Given an array of integers `nums` and an integer `k`, return _the total number of subarrays whose sum equals to_ `k`.

A subarray is a contiguous **non-empty** sequence of elements within an array.

**Example 1:**

```bash
Input: nums = [1,1,1], k = 2
Output: 2
```

**Example 2:**

```bash
Input: nums = [1,2,3], k = 3
Output: 2
```

**Constraints:**

* 1 <= nums.length <= 2 * 10<sup>4</sup>
* `-1000 <= nums[i] <= 1000`
* -10<sup>7</sup> <= k <= 10<sup>7</sup>

## Hints/Notes

* preSum + map

## Solution

Language: **C++**

```C++
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> preSum(size + 1, 0);
        for (int i = 0; i < size; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        map<int, int> m;
        int res = 0;
        for (int i = 0; i <= size; i++) {
            int val = preSum[i];
            if (m.count(val - k)) {
                res += m[val - k];
            }
            m[val]++;
        }
        return res;
    }
};
```
