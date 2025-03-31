---
title: 645. Set Mismatch
categories: Leetcode
date: 2025-03-28 00:41:03
tags:
    - Array
    - Hash Table
    - Bit Manipulation
    - Sorting
---

[645. Set Mismatch](https://leetcode.com/problems/set-mismatch/description/)

## Description

You have a set of integers `s`, which originally contains all the numbers from `1` to `n`. Unfortunately, due to some error, one of the numbers in `s` got duplicated to another number in the set, which results in **repetition of one**  number and **loss of another**  number.

You are given an integer array `nums` representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

**Example 1:**

```bash
Input: nums = [1,2,2,4]
Output: [2,3]
```

**Example 2:**

```bash
Input: nums = [1,1]
Output: [1,2]
```

**Constraints:**

- `2 <= nums.length <= 10^4`
- `1 <= nums[i] <= 10^4`

## Hints/Notes

- 2025/03/26 Q1
- bit manipulation
- [Leetcode solution](https://leetcode.com/problems/set-mismatch/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(), xo = 0;
        for (int i = 0; i < n; i++) {
            xo ^= (i + 1) ^ nums[i];
        }
        int rightmost = xo & (-xo);
        int xor1 = 0, xor2 = 0;
        // there are two types of values: rightmost is 1 or 0
        // xor1: all index with rightmost = 0, and all such element
        // xor2: all index with rightmost = 1, and all such element
        for (int i = 0; i < n; i++) {
            if (((i + 1) & rightmost) == 0) {
                xor1 ^= i + 1;
            } else {
                xor2 ^= i + 1;
            }
            if ((nums[i] & rightmost) == 0) {
                xor1 ^= nums[i];
            } else {
                xor2 ^= nums[i];
            }
        }
        for (int num : nums) {
            if (num == xor1) {
                return {xor1, xor2};
            }
        }
        return {xor2, xor1};

    }
};
```
