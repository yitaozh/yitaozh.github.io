---
title: 254. Factor Combinations
categories: Leetcode
date: 2025-04-11 23:49:23
tags:
    - Backtracking
---

[254. Factor Combinations](https://leetcode.com/problems/factor-combinations/description/?envType=company&envId=linkedin&favoriteSlug=linkedin-six-months)

## Description

Numbers can be regarded as the product of their factors.

- For example, `8 = 2 x 2 x 2 = 2 x 4`.

Given an integer `n`, return all possible combinations of its factors. You may return the answer in **any order** .

**Note**  that the factors should be in the range `[2, n - 1]`.

**Example 1:**

```bash
Input: n = 1
Output: []
```

**Example 2:**

```bash
Input: n = 12
Output: [[2,6],[3,4],[2,2,3]]
```

**Example 3:**

```bash
Input: n = 37
Output: []
```

**Constraints:**

- `1 <= n <= 10^7`

## Hints/Notes

- 2025/04/09 Q3
- backtracking
- [Leetcode solution](https://leetcode.com/problems/factor-combinations/editorial/?envType=company&envId=linkedin&favoriteSlug=linkedin-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int n;
    vector<vector<int>> res;

    vector<vector<int>> getFactors(int n) {
        this->n = n;
        vector<int> cur;
        helper(n, cur, 2);
        return res;
    }

    void helper(int val, vector<int>& cur, int prev) {
        if (val == 1) {
            if (!cur.empty()) {
                res.push_back(cur);
            }
            return;
        }
        for (int i = prev; i <= min(val, n - 1); i++) {
            if (val % i == 0) {
                cur.push_back(i);
                helper(val / i, cur, i);
                cur.pop_back();
            }
        }
    }
};
```
