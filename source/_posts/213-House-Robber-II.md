---
title: 213. House Robber II
categories: Leetcode
date: 2025-01-03 00:54:46
tags:
    - Array
    - Dynamic Programming
---

[213. House Robber II](https://leetcode.com/problems/house-robber-ii/description/?envType=problem-list-v2&envId=plakya4j)

## Description

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are **arranged in a circle.**  That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and<b>it will automatically contact the police if two adjacent houses were broken into on the same night</b>.

Given an integer array `nums` representing the amount of money of each house, return the maximum amount of money you can rob tonight **without alerting the police** .

**Example 1:**

```bash
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
```

**Example 2:**

```bash
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```

**Example 3:**

```bash
Input: nums = [1,2,3]
Output: 3
```

**Constraints:**

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 1000`

## Hints/Notes

- 2025/01/02
- dp
- [0x3F's solution](https://leetcode.cn/problems/house-robber-ii/solutions/2445622/jian-ji-xie-fa-zhi-jie-diao-yong-198-ti-qhvri/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> dp;

    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1);
        int res1 = dfs(1, nums);
        fill(dp.begin(), dp.end(), -1);
        if (nums.size() > 1) {
            nums.pop_back();
        }
        return max(dfs(0, nums), res1);
    }

    int dfs(int index, vector<int>& nums) {
        if (index >= nums.size()) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int& res = dp[index];
        res = max(dfs(index + 2, nums) + nums[index], dfs(index + 1, nums));
        return res;
    }
};
```
