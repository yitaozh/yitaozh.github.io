---
title: 3190. Find Minimum Operations to Make All Elements Divisible by Three
categories: Leetcode
date: 2024-06-27 23:21:18
tags:
    - Array
    - Math
---

[3190. Find Minimum Operations to Make All Elements Divisible by Three](https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/)

## Description

You are given an integer array `nums`. In one operation, you can add or subtract 1 from **any**  element of `nums`.

Return the **minimum**  number of operations to make all elements of `nums` divisible by 3.

**Example 1:**

```bash
Input: nums = [1,2,3,4]

Output: 3

Explanation:

All array elements can be made divisible by 3 using 3 operations:

- Subtract 1 from 1.
- Add 1 to 2.
- Subtract 1 from 4.
```

**Example 2:**

```bash
Input: nums = [3,6,9]

Output: 0
```

**Constraints:**

- `1 <= nums.length <= 50`
- `1 <= nums[i] <= 50`

## Hints/Notes

- Biweekly Contest 133

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            res += min(num % 3, 3 - num % 3);
        }
        return res;
    }
};
```
