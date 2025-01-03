---
title: 198. House Robber
categories: Leetcode
date: 2025-01-02 23:45:09
tags:
    - Array
    - Dynamic Programming
---

[198. House Robber](https://leetcode.com/problems/house-robber/description/?envType=problem-list-v2&envId=plakya4j)

## Description

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and <b>it will automatically contact the police if two adjacent houses were broken into on the same night</b>.

Given an integer array `nums` representing the amount of money of each house, return the maximum amount of money you can rob tonight <b>without alerting the police</b>.

**Example 1:**

```bash
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```

**Example 2:**

```bash
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
```

**Constraints:**

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 400`

## Hints/Notes

- 2025/01/01
- dp
- [0x3F's solution](https://leetcode.com/problems/house-robber/submissions/1495833615/?envType=problem-list-v2&envId=plakya4j)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> dp;

    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1);
        return dfs(0, nums);
    }

    int dfs(int index, vector<int>& nums) {
        if (index >= nums.size()) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int& res = dp[index];
        res = max(dfs(index + 1, nums), dfs(index + 2, nums) + nums[index]);
        return res;
    }
};
```
