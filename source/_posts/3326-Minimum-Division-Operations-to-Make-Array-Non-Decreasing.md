---
title: 3326. Minimum Division Operations to Make Array Non Decreasing
categories: Leetcode
date: 2024-10-22 14:53:43
tags:
    - Array
    - Math
    - Greedy
    - Number Theory
---

[3326. Minimum Division Operations to Make Array Non Decreasing](https://leetcode.com/problems/minimum-division-operations-to-make-array-non-decreasing/description/)

## Description

You are given an integer array `nums`.

Any **positive**  divisor of a natural number `x` that is **strictly less**  than `x` is called a **proper divisor**  of `x`. For example, 2 is a proper divisor of 4, while 6 is not a proper divisor of 6.

You are allowed to perform an **operation**  any number of times on `nums`, where in each **operation**  you select any one element from `nums` and divide it by its **greatest**  **proper divisor** .

Return the **minimum**  number of **operations**  required to make the array **non-decreasing** .

If it is **not**  possible to make the array non-decreasing using any number of operations, return `-1`.

**Example 1:**

```bash
Input: nums = [25,7]

Output: 1
```

Explanation:

Using a single operation, 25 gets divided by 5 and `nums` becomes `[5, 7]`.

**Example 2:**

```bash
Input: nums = [7,7,6]

Output: -1
```

**Example 3:**

```bash
Input: nums = [1,1,1,1]

Output: 0
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^6`

## Hints/Notes

- greedy
- Weekly Contest 420

## Solution

Language: **C++**

```C++
class Solution {
public:
    unordered_map<int, int> max_divisor;

    int minOperations(vector<int>& nums) {
        for (int num : nums) {
            findMax(num);
        }
        int n = nums.size(), res = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                nums[i] /= max_divisor[nums[i]];
                res++;
                if (nums[i] > nums[i + 1]) {
                    return -1;
                }
            }
        }
        return res;
    }

    void findMax(int num) {
        if (max_divisor.contains(num)) {
            return;
        }
        if (num == 1) {
            max_divisor[1] = -1;
        }
        max_divisor[num] = 1;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                max_divisor[num] = max(max_divisor[num], max(i, num / i));
            }
        }
    }
};
```
