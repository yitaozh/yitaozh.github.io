---
title: 40. Combination Sum II
categories: Leetcode
date: 2024-12-20 01:26:05
tags:
    - Array
    - Backtracking
---

[40. Combination Sum II](https://leetcode.com/problems/combination-sum-ii/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates`where the candidate numbers sum to `target`.

Each number in `candidates`may only be used **once**  in the combination.

**Note:** The solution set must not contain duplicate combinations.

**Example 1:**

```bash
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
```

**Example 2:**

```bash
Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]
```

**Constraints:**

- `1 <=candidates.length <= 100`
- `1 <=candidates[i] <= 50`
- `1 <= target <= 30`

## Hints/Notes

- 2024/12/19
- backtracking
- review together with 3sum
- [Leetcode solution](https://leetcode.com/problems/combination-sum-ii/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> cur;
    vector<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return res;
    }

    void dfs(vector<int>& candidates, int start, int target) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (target < 0 || start == candidates.size()) {
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] > target) {
                break;
            }
            cur.push_back(candidates[i]);
            dfs(candidates, i + 1, target - candidates[i]);
            cur.pop_back();
        }
    }
};
```
