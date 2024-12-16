---
title: 3381. Maximum Subarray Sum With Length Divisible by K
categories: Leetcode
date: 2024-12-16 11:44:11
tags:
    - Array
    - Hash Table
    - Prefix Sum
---

[3381. Maximum Subarray Sum With Length Divisible by K](https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/description/)

## Description

You are given an array of integers `nums` and an integer `k`.

Return the **maximum**  sum of a subarray of `nums`, such that the size of the subarray is **divisible**  by `k`.

**Example 1:**

```bash
Input: nums = [1,2], k = 1

Output: 3
```

Explanation:

The subarray `[1, 2]` with sum 3 has length equal to 2 which is divisible by 1.

**Example 2:**

```bash
Input: nums = [-1,-2,-3,-4,-5], k = 4

Output: -10
```

Explanation:

The maximum sum subarray is `[-1, -2, -3, -4]` which has length equal to 4 which is divisible by 4.

**Example 3:**

```bash
Input: nums = [-5,1,2,-3,4], k = 2

Output: 4
```

Explanation:

The maximum sum subarray is `[1, 2, -3, 4]` which has length equal to 4 which is divisible by 2.

**Constraints:**

- `1 <= k <= nums.length <= 2 * 10^5`
- `-10^9 <= nums[i] <= 10^9`

## Hints/Notes

- 2024/12/13
- preSum
- [0x3F's solution](https://leetcode.cn/problems/maximum-subarray-sum-with-length-divisible-by-k/solutions/3013897/qian-zhui-he-mei-ju-you-wei-hu-zuo-pytho-0t8p/)(checked)
- Weekly Contest 427

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long> preSum(k, LLONG_MAX);
        preSum[0] = 0;
        long long sum = 0, res = LLONG_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (preSum[(i + 1) % k] != LLONG_MAX) {
                res = max(res, sum - preSum[(i + 1) % k]);
            }
            preSum[(i + 1) % k] = min(preSum[(i + 1) % k], sum);
        }
        return res;
    }
};
```
