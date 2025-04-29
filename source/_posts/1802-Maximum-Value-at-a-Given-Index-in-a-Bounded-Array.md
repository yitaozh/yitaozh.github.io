---
title: 1802. Maximum Value at a Given Index in a Bounded Array
categories: Leetcode
date: 2025-04-05 20:28:29
tags:
    - Binary Search
    - Greedy
---

[1802. Maximum Value at a Given Index in a Bounded Array](https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-six-months)

## Description

You are given three positive integers:`n`, `index`, and `maxSum`. You want to construct an array `nums` (**0-indexed**) that satisfies the following conditions:

- `nums.length == n`
- `nums[i]` is a **positive**  integer where `0 <= i < n`.
- `abs(nums[i] - nums[i+1]) <= 1` where `0 <= i < n-1`.
- The sum of all the elements of `nums` does not exceed `maxSum`.
- `nums[index]` is **maximized** .

Return `nums[index]` of the constructed array.

Note that `abs(x)` equals `x` if `x >= 0`, and `-x` otherwise.

**Example 1:**

```bash
Input: n = 4, index = 2,  maxSum = 6
Output: 2
```

Explanation: nums = [1,2,**2** ,1] is one array that satisfies all the conditions.
There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2].

**Example 2:**

```bash
Input: n = 6, index = 1,  maxSum = 10
Output: 3
```

**Constraints:**

- `1 <= n <= maxSum <= 10^9`
- `0 <= index < n`

## Hints/Notes

- 2025/04/03 Q1
- binary search
- [Leetcode solution](https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int left = 0, right = maxSum + 1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            // check returns true: with mid as value at index
            // the total sum is <= maxSum
            if (check(n, index, maxSum, mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }

    bool check(int n, int index, int maxSum, int val) {
        long sum = val, num_before = index, num_after = n - index - 1;
        if (val > num_before) {
            // it means we need to calculate [val - num_before, val - 1]
            sum += (long)(val * 2 - 1 - num_before) * num_before / 2;
        } else {
            // it means we need to calculate [1, val - 1], with other numbers equal to 1
            sum += (long)val * (val - 1) / 2 + (num_before - val + 1);
        }
        if (val > num_after) {
            // [val - 1, val - num_after]
            sum += (long)(val * 2 - 1 - num_after) * num_after / 2;
        } else {
            sum += (long)val * (val - 1) / 2 + (num_after - val + 1);
        }
        return sum <= maxSum;
    }
};
```
