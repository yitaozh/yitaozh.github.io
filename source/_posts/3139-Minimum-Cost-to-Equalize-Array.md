---
title: 3139. Minimum Cost to Equalize Array
categories: Leetcode
date: 2024-05-17 11:55:00
tags:
    - Array
    - Greedy
    - Enumeration
---

[3139. Minimum Cost to Equalize Array](https://leetcode.com/problems/minimum-cost-to-equalize-array/description/)

## Description

You are given an integer array `nums` and two integers `cost1` and `cost2`. You are allowed to perform **either**  of the following operations **any**  number of times:

- Choose an index `i` from `nums` and **increase**  `nums[i]` by `1` for a cost of `cost1`.
- Choose two **different**  indices `i`, `j`, from `nums` and **increase**  `nums[i]` and `nums[j]` by `1` for a cost of `cost2`.

Return the **minimum**  **cost**  required to make all elements in the array **equal** .

Since the answer may be very large, return it **modulo**  `10^9 + 7`.

**Example 1:**

```bash
Input: nums = [4,1], cost1 = 5, cost2 = 2

Output: 15

Explanation:

The following operations can be performed to make the values equal:

- Increase `nums[1]` by 1 for a cost of 5. `nums` becomes `[4,2]`.
- Increase `nums[1]` by 1 for a cost of 5. `nums` becomes `[4,3]`.
- Increase `nums[1]` by 1 for a cost of 5. `nums` becomes `[4,4]`.

The total cost is 15.
```

**Example 2:**

```bash
Input: nums = [2,3,3,3,5], cost1 = 2, cost2 = 1

Output: 6

Explanation:

The following operations can be performed to make the values equal:

- Increase `nums[0]` and `nums[1]` by 1 for a cost of 1. `nums` becomes `[3,4,3,3,5]`.
- Increase `nums[0]` and `nums[2]` by 1 for a cost of 1. `nums` becomes `[4,4,4,3,5]`.
- Increase `nums[0]` and `nums[3]` by 1 for a cost of 1. `nums` becomes `[5,4,4,4,5]`.
- Increase `nums[1]` and `nums[2]` by 1 for a cost of 1. `nums` becomes `[5,5,5,4,5]`.
- Increase `nums[3]` by 1 for a cost of 2. `nums` becomes `[5,5,5,5,5]`.

The total cost is 6.
```

**Example 3:**

```bash
Input: nums = [3,5,3], cost1 = 1, cost2 = 3

Output: 4

Explanation:

The following operations can be performed to make the values equal:

- Increase `nums[0]` by 1 for a cost of 1. `nums` becomes `[4,5,3]`.
- Increase `nums[0]` by 1 for a cost of 1. `nums` becomes `[5,5,3]`.
- Increase `nums[2]` by 1 for a cost of 1. `nums` becomes `[5,5,4]`.
- Increase `nums[2]` by 1 for a cost of 1. `nums` becomes `[5,5,5]`.

The total cost is 4.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^6`
- `1 <= cost1 <= 10^6`
- `1 <= cost2 <= 10^6`

## Hints/Notes

- need to iterate through the maxDiff value

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        int maxNumber = 0, mod_ = 1e9 + 7;
        for (int num: nums) {
            maxNumber = max(num, maxNumber);
        }
        long long sum = 0, maxDiff = 0;
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = maxNumber - nums[i];
            maxDiff = max(maxDiff, (long long)nums[i]);
            sum += nums[i];
        }
        // the case that we can just use cost1 to do single addition
        if (cost1 * 2 <= cost2) {
            return (sum * cost1) % mod_;
        }
        // there's no need to do the minus one by one, we can just use the sum
        long long res = LLONG_MAX, mx = maxDiff;
        for (; maxDiff <= mx * 2; maxDiff++) {
            long long curRes = 0;
            if (maxDiff * 2 <= sum) {
                curRes = curRes + sum / 2 * cost2;
                curRes = curRes + sum % 2 * cost1;
            } else {
                long long tmp = sum - maxDiff;
                curRes = curRes + tmp * cost2;
                curRes = curRes + (maxDiff - tmp) * cost1;
            }
            res = min(res, curRes);
            sum += nums.size();
        }

        return res % mod_;
    }
};
```
