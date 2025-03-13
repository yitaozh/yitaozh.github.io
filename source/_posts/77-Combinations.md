---
title: 77. Combinations
categories: Leetcode
date: 2025-03-13 13:06:04
tags:
    - Backtracking
---

[77. Combinations](https://leetcode.com/problems/combinations/description/)

## Description

Given two integers `n` and `k`, return all possible combinations of `k` numbers chosen from the range `[1, n]`.

You may return the answer in **any order** .

**Example 1:**

```bash
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
```

**Example 2:**

```bash
Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.
```

**Constraints:**

- `1 <= n <= 20`
- `1 <= k <= n`

## Hints/Notes

- 2025/03/01 Q3
- backtracking
- [0x3F's solution](https://leetcode.cn/problems/combinations/solutions/2071017/hui-su-bu-hui-xie-tao-lu-zai-ci-pythonja-65lh/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return res;
    }

    void dfs(int index, int n, int k) {
        if (k == 0) {
            res.push_back(cur);
            return;
        }
        // when we are at index, we can pick at most n - index + 1 numbers
        // while we need to pick k numbers
        if (k < n - index + 1) {
            // we can skip this number and go to next directly
            dfs(index + 1, n, k);
        }
        cur.push_back(index);
        dfs(index + 1, n, k - 1);
        cur.pop_back();
    }
};
```
