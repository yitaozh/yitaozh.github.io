---
title: 494. Target Sum
categories: Leetcode
date: 2024-07-31 23:44:12
tags:
    - Array
    - Dynamic Programming
    - Backtracking
---

[494. Target Sum](https://leetcode.com/problems/target-sum/description/)

## Description

You are given an integer array `nums` and an integer `target`.

You want to build an **expression** out of nums by adding one of the symbols `'+'` and `'-'` before each integer in nums and then concatenate all the integers.

- For example, if `nums = [2, 1]`, you can add a `'+'` before `2` and a `'-'` before `1` and concatenate them to build the expression `"+2-1"`.

Return the number of different **expressions** that you can build, which evaluates to `target`.

**Example 1:**

```bash
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
```

**Example 2:**

```bash
Input: nums = [1], target = 1
Output: 1
```

**Constraints:**

- `1 <= nums.length <= 20`
- `0 <= nums[i] <= 1000`
- `0 <= sum(nums[i]) <= 1000`
- `-1000 <= target <= 1000`

## Hints/Notes

- dp

## Solution

Language: **C++**

```C++
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // the problem can be transformed into subA - subB = target
        // subA = target + subB => 2subA = target + sum
        // subA = (target + sum) / 2
        int sum = 0;
        for (int& num : nums) {
            sum += num;
        }
        int res = (target + sum) / 2;
        if ((target + sum) % 2 || (target + sum) < 0) {
            return 0;
        }
        vector<vector<int>> dp(nums.size() + 1, vector<int>(res + 1, 0));
        dp[0][0] = 1;
        // the meaning of dp[i][j]: with the first 0 ~ i items, how many ways we
        // can form j to get to dp[i][j], we need dp[i][j - nums[i]] and dp[i -
        // 1][j] when i = 0, the only way to form j is then nums[0] == j
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j <= res; j++) {
                if (j >= nums[i - 1]) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
                dp[i][j] += dp[i - 1][j];
            }
        }
        return dp[nums.size()][res];
    }
};
```
