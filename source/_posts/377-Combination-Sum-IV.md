---
title: 377. Combination Sum IV
categories: Leetcode
date: 2025-03-19 02:03:36
tags:
    - Array
    - Dynamic Programming
---

[377. Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/description/)

## Description

Given an array of **distinct**  integers `nums` and a target integer `target`, return the number of possible combinations that add up to`target`.

The test cases are generated so that the answer can fit in a **32-bit**  integer.

**Example 1:**

```bash
Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
```

**Example 2:**

```bash
Input: nums = [9], target = 3
Output: 0
```

**Constraints:**

- `1 <= nums.length <= 200`
- `1 <= nums[i] <= 1000`
- All the elements of `nums` are **unique** .
- `1 <= target <= 1000`

**Follow up:**  What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?

## Hints/Notes

- 2025/02/20 Q2
- dp
- [Leetcode solution](https://leetcode.com/problems/combination-sum-iv/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> dp;

    int combinationSum4(vector<int>& nums, int target) {
        ranges::sort(nums);
        int n = nums.size();
        dp.resize(target + 1, -1);
        int res = dfs(target, nums);
        return res;
    }

    int dfs(int target, vector<int>& nums) {
        if (target == 0) {
            return 1;
        }
        if (dp[target] != -1) {
            return dp[target];
        }
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (target >= nums[i]) {
                res += dfs(target - nums[i], nums);
            }
        }
        dp[target] = res;
        return res;
    }
};
```
