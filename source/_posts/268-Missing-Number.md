---
title: 268. Missing Number
categories: Leetcode
date: 2025-01-07 16:36:11
tags:
    - Array
    - Hash Table
    - Math
    - Binary Search
    - Bit Manipulation
    - Sorting
---

[268. Missing Number](https://leetcode.com/problems/missing-number/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array.

**Example 1:**

```bash
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
```

**Example 2:**

```bash
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
```

**Example 3:**

```bash
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 10^4`
- `0 <= nums[i] <= n`
- All the numbers of `nums` are **unique** .

**Follow up:**  Could you implement a solution using only `O(1)` extra space complexity and `O(n)` runtime complexity?

## Hints/Notes

- 2025/01/04
- bit operation
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            res ^= i;
            res ^= nums[i];
        }
        res ^= n;
        return res;
    }
};
```
