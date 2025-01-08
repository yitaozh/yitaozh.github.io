---
title: 312. Burst Balloons
categories: Leetcode
date: 2025-01-08 00:36:22
tags:
    - Array
    - Dynamic Programming
---

[312. Burst Balloons](https://leetcode.com/problems/burst-balloons/description/?envType=problem-list-v2&envId=plakya4j)

## Description

You are given `n` balloons, indexed from `0` to `n - 1`. Each balloon is painted with a number on it represented by an array `nums`. You are asked to burst all the balloons.

If you burst the `i^th` balloon, you will get `nums[i - 1] * nums[i] * nums[i + 1]` coins. If `i - 1` or `i + 1` goes out of bounds of the array, then treat it as if there is a balloon with a `1` painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

**Example 1:**

```bash
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
```

**Example 2:**

```bash
Input: nums = [1,5]
Output: 10
```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 300`
- `0 <= nums[i] <= 100`

## Hints/Notes

- 2025/01/06
- dp
- No solution from 0x3F, [good solution](https://leetcode.cn/problems/burst-balloons/solutions/337630/zhe-ge-cai-pu-zi-ji-zai-jia-ye-neng-zuo-guan-jian-/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> dp;
    int n;

    int maxCoins(vector<int>& nums) {
        n = nums.size();
        dp.resize(n + 2, vector<int>(n + 2, -1));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return dfs(0, n + 1, nums);
    }

    int dfs(int start, int end, vector<int>& nums) {
        if (start + 1 == end) {
            return 0;
        }
        if (start + 2 == end) {
            return nums[start] * nums[start + 1] * nums[end];
        }
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        int& res = dp[start][end];
        for (int k = start + 1; k < end; k++) {
            res = max(res, dfs(start, k, nums) + dfs(k, end, nums) + nums[start] * nums[k] * nums[end]);
        }
        return res;
    }
};
```
