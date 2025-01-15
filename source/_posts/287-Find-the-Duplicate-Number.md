---
title: 287. Find the Duplicate Number
categories: Leetcode
date: 2025-01-07 17:26:30
tags:
    - Array
    - Two Pointers
    - Binary Search
    - Bit Manipulation
---

[287. Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given an array of integers `nums` containing`n + 1` integers where each integer is in the range `[1, n]` inclusive.

There is only **one repeated number**  in `nums`, return this repeated number.

You must solve the problem **without**  modifying the array `nums`and using only constant extra space.

**Example 1:**

```bash
Input: nums = [1,3,4,2,2]
Output: 2
```

**Example 2:**

```bash
Input: nums = [3,1,3,4,2]
Output: 3
```

**Example 3:**

```bash
Input: nums = [3,3,3,3,3]
Output: 3
```

**Constraints:**

- `1 <= n <= 10^5`
- `nums.length == n + 1`
- `1 <= nums[i] <= n`
- All the integers in `nums` appear only **once**  except for **precisely one integer**  which appears **two or more**  times.

<b>Follow up:</b>

- How can we prove that at least one duplicate number must exist in `nums`?
- Can you solve the problem in linear runtime complexity?

## Hints/Notes

- 2025/01/05
- binary search and count
- rewrite with fast and slow pointers
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size();
        // the result is in (left, right]
        while (left < right) {
            int mid = (left + right) / 2, count = 0;
            for (int num : nums) {
                if (num <= mid) {
                    count++;
                }
            }
            // it means the result is in (0, mid]
            if (count > mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```
