---
title: 416. Partition Equal Subset Sum
categories: Leetcode
date: 2024-07-26 18:35:49
tags:
    - Array
    - Dynamic Programming
---

[416. Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/description/)

## Description

Given an integer array `nums`, return `true` if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or `false` otherwise.

**Example 1:**

```bash
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
```

**Example 2:**

```bash
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
```

**Constraints:**

- `1 <= nums.length <= 200`
- `1 <= nums[i] <= 100`

## Hints/Notes

- 0/1 knapsack

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int& num : nums) {
            sum += num;
        }
        if (sum % 2) {
            return false;
        }
        vector<bool> dp(sum / 2 + 1, false);
        // the dp definition:
        //  dp[i][j] = true: the first i items can form a value of j
        //  dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]]
        // compress dimension:
        //  dp[i][j] only requires data from dp[i - 1][j] and dp[i - 1][j - nums[i]]
        for (int i = 0; i < nums.size(); i++) {
            for (int j = sum / 2; j >= 0; j--) {
                if (!j) {
                    dp[j] = true;
                    continue;
                }
                if (!i) {
                    dp[j] = nums[i] == j;
                } else {
                    if (j >= nums[i]) {
                        dp[j] = dp[j] || dp[j - nums[i]];
                    }
                }
            }
        }
        return dp[sum / 2];
    }
};
```
