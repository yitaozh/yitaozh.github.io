---
title: 525. Contiguous Array
categories: Leetcode
date: 2023-11-12 23:50:31
tags:
    - Array
    - Hash Table
    - Prefix Sum
---

# [525\. Contiguous Array](https://leetcode.com/problems/contiguous-array/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [Prefix Sum](https://leetcode.com/tag/https://leetcode.com/tag/prefix-sum//)

Given a binary array `nums`, return _the maximum length of a contiguous subarray with an equal number of_ `0` _and_ `1`.

**Example 1:**

```bash
Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
```

**Example 2:**

```bash
Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
```

**Constraints:**

* 1 <= nums.length <= 10<sup>5</sup>
* `nums[i]` is either `0` or `1`.

## Hints/Notes

* change 0 to -1 and make the range sum to be 0

## Solution

Language: **C++**

```C++
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int size = nums.size();
        vector<int> preSum(size + 1, 0);
        for (int i = 0; i < size; i++) {
            preSum[i + 1] = preSum[i] + (nums[i] == 1 ? 1 : -1);
        }
        map<int, int> m;
        int res = 0;
        for (int i = 0; i <= size; i++) {
            if (!m.count(preSum[i])) {
                m[preSum[i]] = i;
            } else {
                res = max(res, i - m[preSum[i]]);
            }
        }
        return res;
    }
};
```
