---
title: 137. Single Number II
categories: Leetcode
date: 2025-03-23 02:11:05
tags:
    - Array
    - Bit Manipulation
---

[137. Single Number II](https://leetcode.com/problems/single-number-ii/description/?envType=study-plan-v2&envId=top-interview-150)

## Description

Given an integer array `nums` where every element appears **three times**  except for one, which appears **exactly once** . Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

**Example 1:**

```bash
Input: nums = [2,2,3,2]
Output: 3
```

**Example 2:**

```bash
Input: nums = [0,1,0,1,0,1,99]
Output: 99
```

**Constraints:**

- `1 <= nums.length <= 3 * 10^4`
- `-2^31 <= nums[i] <= 2^31 - 1`
- Each element in `nums` appears exactly **three times**  except for one element which appears **once** .

## Hints/Notes

- 2025/03/16 Q2
- bit manipulation
- [Leetcode solution](https://leetcode.com/problems/single-number-ii/editorial/?envType=study-plan-v2&envId=top-interview-150)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int loner = 0, n = nums.size();
        for (int i = 0; i < 32; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if ((nums[j] >> i) & 1) {
                    sum++;
                }
            }
            loner |= (sum % 3) << i;
        }
        return loner;
    }
};
```
