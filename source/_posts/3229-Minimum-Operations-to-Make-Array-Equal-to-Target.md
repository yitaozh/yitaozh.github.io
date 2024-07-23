---
title: 3229. Minimum Operations to Make Array Equal to Target
categories: Leetcode
date: 2024-07-23 14:03:53
tags:
    - Array
    - Dynamic Programming
    - Stack
    - Greedy
    - Monotonic Stack
---

[3229. Minimum Operations to Make Array Equal to Target](https://leetcode.com/problems/minimum-operations-to-make-array-equal-to-target/description/)

## Description

You are given two positive integer arrays `nums` and `target`, of the same length.

In a single operation, you can select any subarray of `nums` and increment or decrement each element within that subarray by 1.

Return the **minimum**  number of operations required to make `nums` equal to the array `target`.

**Example 1:**

```bash
Input: nums = [3,5,1,2], target = [4,6,2,4]

Output: 2
```

Explanation:

We will perform the following operations to make `nums` equal to `target`:

- Increment`nums[0..3]` by 1, `nums = [4,6,2,3]`.
- Increment`nums[3..3]` by 1, `nums = [4,6,2,4]`.

**Example 2:**

```bash
Input: nums = [1,3,2], target = [2,1,4]

Output: 5
```

Explanation:

We will perform the following operations to make `nums` equal to `target`:

- Increment`nums[0..0]` by 1, `nums = [2,3,2]`.
- Decrement`nums[1..1]` by 1, `nums = [2,2,2]`.
- Decrement`nums[1..1]` by 1, `nums = [2,1,2]`.
- Increment`nums[2..2]` by 1, `nums = [2,1,3]`.
- Increment`nums[2..2]` by 1, `nums = [2,1,4]`.

**Constraints:**

- `1 <= nums.length == target.length <= 10^5`
- `1 <= nums[i], target[i] <= 10^8`

## Hints/Notes

- diff array
- Weekly Contest 407

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        vector<int> gap;
        for (int i = 0; i < nums.size(); i++) {
            gap.push_back(target[i] - nums[i]);
        }
        vector<int> diff;
        diff.push_back(gap[0]);
        for (int i = 1; i < nums.size(); i++) {
            diff.push_back(gap[i] - gap[i - 1]);
        }
        int cur = 0;
        long long res = 0;
        for (int i = 0; i < diff.size(); i++) {
            if ((cur >= 0 && diff[i] >= 0) || (cur <= 0 && diff[i] <= 0)) {
                res += abs(diff[i]);
            } else {
                if (abs(cur) < abs(diff[i])) {
                    res += abs(diff[i] + cur);
                }
            }
            cur += diff[i];
        }
        return res;
    }
};
```
