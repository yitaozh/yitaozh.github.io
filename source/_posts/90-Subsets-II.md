---
title: 90. Subsets II
categories: Leetcode
date: 2024-12-26 01:56:00
tags:
    - Array
    - Backtracking
    - Bit Manipulation
---

[90. Subsets II](https://leetcode.com/problems/subsets-ii/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given an integer array `nums` that may contain duplicates, return all possible subsets (the power set).

The solution set **must not**  contain duplicate subsets. Return the solution in **any order** .

**Example 1:**

```bash
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
```

**Example 2:**

```bash
Input: nums = [0]
Output: [[],[0]]
```

**Constraints:**

- `1 <= nums.length <= 10`
- `-10 <= nums[i] <= 10`

## Hints/Notes

- 2024/12/25
- backtracking
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ranges::sort(nums);
        dfs(0, nums);
        return res;
    }

    void dfs(int index, vector<int>& nums) {
        if (index == nums.size()) {
            res.push_back(path);
            return;
        }
        path.push_back(nums[index]);
        dfs(index + 1, nums);
        path.pop_back();
        int start = index + 1;
        while (start < nums.size() && nums[start] == nums[index]) {
            start++;
        }
        dfs(start, nums);
    }
};
```
