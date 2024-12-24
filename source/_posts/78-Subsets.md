---
title: 78. Subsets
categories: Leetcode
date: 2024-12-24 02:02:46
tags:
---

[78. Subsets](https://leetcode.com/problems/subsets/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given an integer array `nums` of **unique**  elements, return all possible subsets(the power set).

The solution set **must not**  contain duplicate subsets. Return the solution in **any order** .

**Example 1:**

```bash
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```

**Example 2:**

```bash
Input: nums = [0]
Output: [[],[0]]
```

**Constraints:**

- `1 <= nums.length <= 10`
- `-10 <= nums[i] <= 10`
- All the numbers of`nums` are **unique** .

## Hints/Notes

- 2024/12/23
- backtracking
- [0x3F's solution](https://leetcode.cn/problems/subsets/solutions/2059409/hui-su-bu-hui-xie-tao-lu-zai-ci-pythonja-8tkl/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }

    void dfs(int index, vector<int>& nums) {
        if (index == nums.size()) {
            res.push_back(path);
            return;
        }
        dfs(index + 1, nums);
        path.push_back(nums[index]);
        dfs(index + 1, nums);
        path.pop_back();
    }
};
```
