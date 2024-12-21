---
title: 46. Permutations
categories: Leetcode
date: 2024-05-23 11:29:13
tags:
    - Array
    - Backtracking
---

[46. Permutations](https://leetcode.com/problems/permutations/description/)

## Description

Given an array `nums` of distinct integers, return all the possible permutations. You can return the answer in **any order** .

**Example 1:**

```bash
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

**Example 2:**

```bash
Input: nums = [0,1]
Output: [[0,1],[1,0]]
```

**Example 3:**

```bash
Input: nums = [1]
Output: [[1]]
```

**Constraints:**

- `1 <= nums.length <= 6`
- `-10 <= nums[i] <= 10`
- All the integers of `nums` are **unique** .

## Hints/Notes

- 2024/02/08
- [0x3F's solution](https://leetcode.cn/problems/permutations/solutions/2079585/hui-su-bu-hui-xie-tao-lu-zai-ci-jing-que-6hrh/)(checked)

## Solution

Language: **C++**

Solution with less time

```C++
class Solution {
public:
    vector<vector<int>> res;
    vector<bool> onPath;
    vector<int> path;

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        onPath.resize(n, false);
        path.resize(n, -1);
        dfs(0, nums);
        return res;
    }

    void dfs(int index, vector<int>& nums) {
        if (index == path.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!onPath[i]) {
                path[index] = nums[i];
                onPath[i] = true;
                dfs(index + 1, nums);
                onPath[i] = false;
            }
        }
    }
};
```

```C++
class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> available;
        for (int num : nums) {
            available.insert(num);
        }
        vector<int> cur;
        dfs(nums, cur, available);
        return res;
    }

    void dfs(vector<int>& nums, vector<int>& cur, unordered_set<int>& available) {
        if (nums.size() == cur.size()) {
            res.push_back(cur);
            return;
        }
        for (int num: nums) {
            if (available.contains(num)) {
                available.erase(num);
                cur.push_back(num);
                dfs(nums, cur, available);
                available.insert(num);
                cur.pop_back();
            }
        }
    }
};
```
