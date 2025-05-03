---
title: 368. Largest Divisible Subset
categories: Leetcode
date: 2025-05-03 17:25:04
tags:
    - Array
    - Math
    - Dynamic Programming
    - Sorting
---

[368. Largest Divisible Subset](https://leetcode.com/problems/largest-divisible-subset/description/?envType=company&envId=google&favoriteSlug=google-thirty-days)

## Description

Given a set of **distinct**  positive integers <code>nums</code>, return the largest subset <code>answer</code> such that every pair <code>(answer[i], answer[j])</code> of elements in this subset satisfies:

- <code>answer[i] % answer[j] == 0</code>, or
- <code>answer[j] % answer[i] == 0</code>

If there are multiple solutions, return any of them.

**Example 1:**

```bash
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
```

**Example 2:**

```bash
Input: nums = [1,2,4,8]
Output: [1,2,4,8]
```

**Constraints:**

- <code>1 <= nums.length <= 1000</code>
- <code>1 <= nums[i] <= 2 * 10^9</code>
- All the integers in <code>nums</code> are **unique** .

## Hints/Notes

- 2025/05/01 Q1
- dp
- [0x3F's solution](https://leetcode.cn/problems/largest-divisible-subset/?envType=company&envId=google&favoriteSlug=google-thirty-days)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> dp, from;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        dp.resize(n, 0);
        from.resize(n, -1);
        int max_f = 0, max_idx = 0;
        for (int i = 0; i < n; i++) {
            int f = dfs(i, nums);
            if (f > max_f) {
                max_f = f;
                max_idx = i;
            }
        }
        vector<int> path;
        for (int i = max_idx; i >= 0; i = from[i]) {
            path.push_back(nums[i]);
        }
        return path;
    }

    int dfs(int idx, vector<int>& nums) {
        int& res = dp[idx];
        if (res) {
            return res;
        }
        for (int j = 0; j < idx; j++) {
            if (nums[idx] % nums[j]) {
                continue;
            }
            int f = dfs(j, nums);
            if (f > res) {
                res = f;
                from[idx] = j;
            }
        }
        res++;
        return res;
    }
};
```
