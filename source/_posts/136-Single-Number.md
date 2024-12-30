---
title: 136. Single Number
categories: Leetcode
date: 2024-12-29 23:17:10
tags:
    - Array
    - Bit Manipulation
---

[136. Single Number](https://leetcode.com/problems/single-number/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given a **non-empty** array of integers `nums`, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

**Example 1:**

```bash
Input: nums = [2,2,1]
Output: 1
```

**Example 2:**

```bash
Input: nums = [4,1,2,1,2]
Output: 4
```

**Example 3:**

```bash
Input: nums = [1]
Output: 1
```

**Constraints:**

- `1 <= nums.length <= 3 * 10^4`
- `-3 * 10^4 <= nums[i] <= 3 * 10^4`
- Each element in the array appears twice except for one element which appears only once.

## Hints/Notes

- 2024/12/29
- bit manipulation
- [0x3F's solution](https://leetcode.cn/problems/single-number/solutions/2481594/li-yong-yi-huo-de-xing-zhi-fu-ti-dan-pyt-oizc/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int& num : nums) {
            res ^= num;
        }
        return res;
    }
};
```
