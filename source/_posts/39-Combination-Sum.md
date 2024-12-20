---
title: 39. Combination Sum
categories: Leetcode
date: 2024-12-20 00:43:34
tags:
    - Array
    - Backtracking
---

[39. Combination Sum](https://leetcode.com/problems/combination-sum/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given an array of **distinct**  integers `candidates` and a target integer `target`, return a list of all **unique combinations**  of `candidates` where the chosen numbers sum to `target`. You may return the combinations in **any order** .

The **same**  number may be chosen from `candidates` an **unlimited number of times** . Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to `target` is less than `150` combinations for the given input.

**Example 1:**

```bash
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
```

**Example 2:**

```bash
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
```

**Example 3:**

```bash
Input: candidates = [2], target = 1
Output: []
```

**Constraints:**

- `1 <= candidates.length <= 30`
- `2 <= candidates[i] <= 40`
- All elements of `candidates` are **distinct** .
- `1 <= target <= 40`

## Hints/Notes

- 2024/12/19
- backtracking
- [0x3F's solution](https://leetcode.cn/problems/combination-sum/solutions/2747858/liang-chong-fang-fa-xuan-huo-bu-xuan-mei-mhf9/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> cur;
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, target);
        return res;
    }

    void dfs(vector<int>& candidates, int i, int target) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (target < 0 || i == candidates.size()) {
            return;
        }
        dfs(candidates, i + 1, target);
        cur.push_back(candidates[i]);
        dfs(candidates, i, target - candidates[i]);
        cur.pop_back();
    }
};
```
