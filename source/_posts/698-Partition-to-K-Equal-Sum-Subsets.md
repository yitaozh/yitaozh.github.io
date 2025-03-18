---
title: 698. Partition to K Equal Sum Subsets
categories: Leetcode
date: 2025-03-17 22:28:31
tags:
    - Array
    - Dynamic Programming
    - Backtracking
    - Bit Manipulation
    - Memoization
    - Bitmask
---

[698. Partition to K Equal Sum Subsets](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/?envType=company&envId=linkedin&favoriteSlug=linkedin-three-months)

## Description

Given an integer array `nums` and an integer `k`, return `true` if it is possible to divide this array into `k` non-empty subsets whose sums are all equal.

**Example 1:**

```bash
Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
```

**Example 2:**

```bash
Input: nums = [1,2,3,4], k = 3
Output: false
```

**Constraints:**

- `1 <= k <= nums.length <= 16`
- `1 <= nums[i] <= 10^4`
- The frequency of each element is in the range `[1, 4]`.

## Hints/Notes

- 2025/02/15 Q2
- dp
- No good solution from 0x3F or Leetcode

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> dp;
    int n, avg;

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = reduce(nums.begin(), nums.end(), 0);
        if (sum % k) {
            return false;
        }
        avg = sum / k;
        ranges::sort(nums);
        if (nums.back() > avg) {
            return false;
        }
        n = nums.size();
        dp.resize(1 << n, -1);
        int res = dfs(0, 0, nums);
        return res;
    }

    bool dfs(int state, int sum, vector<int>& nums) {
        if (state == (1 << n) - 1) {
            return true;
        }
        if (dp[state] != -1) {
            return dp[state];
        }
        dp[state] = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] + sum > avg) {
                break;
            }
            if ((state & (1 << i)) == 0) {
                if (dfs(state | (1 << i), (sum + nums[i]) % avg, nums)) {
                    dp[state] = 1;
                    return 1;
                }
            }
        }
        dp[state] = 0;
        return 0;
    }
};
```
