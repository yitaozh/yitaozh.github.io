---
title: 442. Find All Duplicates in an Array
categories: Leetcode
date: 2023-12-26 22:02:26
tags:
    - Array
    - Hash Table
---

[442\. Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//)

Given an integer array `nums` of length `n` where all the integers of `nums` are in the range `[1, n]` and each integer appears **once** or **twice**, return _an array of all the integers that appears **twice**_.

You must write an algorithm that runs in `O(n)` time and uses only constant extra space.

**Example 1:**

```bash
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
```

**Example 2:**

```bash
Input: nums = [1,1,2]
Output: [1]
```

**Example 3:**

```bash
Input: nums = [1]
Output: []
```

**Constraints:**

* `n == nums.length`
* 1 <= n <= 10<sup>5</sup>
* `1 <= nums[i] <= n`
* Each element in `nums` appears **once** or **twice**.

## Hints/Notes

* flip the array element(negative) to mark if one element has appeared previously

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int num : nums) {
            if (nums[abs(num) - 1] < 0) {
                res.push_back(abs(num));
            } else {
                nums[abs(num) - 1] *= -1;
            }
        }
        return res;
    }
};
```
