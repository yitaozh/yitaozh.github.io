---
title: 325. Maximum Size Subarray Sum Equals k
categories: Leetcode
date: 2023-11-13 00:52:40
tags:
    - Array
    - Hash Table
    - Prefix Sum
---

[325\. Maximum Size Subarray Sum Equals k](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [Prefix Sum](https://leetcode.com/tag/https://leetcode.com/tag/prefix-sum//)

Given an integer array `nums` and an integer `k`, return _the maximum length of a_<span data-keyword="subarray" class=" cursor-pointer relative text-dark-blue-s text-sm"></span> _subarray that sums to_ `k`. If there is not one, return `0` instead.

**Example 1:**

```bash
Input: nums = [1,-1,5,-2,3], k = 3
Output: 4
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
```

**Example 2:**

```bash
Input: nums = [-2,-1,2,1], k = 1
Output: 2
Explanation: The subarray [-1, 2] sums to 1 and is the longest.
```

**Constraints:**

* 1 <= nums.length <= 2 * 10<sup>5</sup>
* -10<sup>4</sup> <= nums[i] <= 10<sup>4</sup>
* -10<sup>9</sup> <= k <= 10<sup>9</sup>

## Hints/Notes

* 2023/11/09
* preSum + map
* [Leetcode solution](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> preSum(size + 1, 0);
        for (int i = 0; i < size; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        map<long, int> m;
        int res = 0;
        for (int i = 0; i <= size; i++) {
            if (m.count((long)preSum[i] - k)) {
                res = max(res, i - m[preSum[i] - k]);
            }
            if (!m.count(preSum[i])) {
                m[preSum[i]] = i;
            }
        }
        return res;
    }
};
```
