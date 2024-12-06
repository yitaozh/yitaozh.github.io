---
title: 3332. Maximum Points Tourist Can Earn
categories: Leetcode
date: 2024-11-20 14:41:35
tags:
    - Array
    - Dynamic Programming
    - Matrix
---

[3332. Maximum Points Tourist Can Earn](https://leetcode.com/problems/maximum-points-tourist-can-earn/description/)

## Description

You are given two integers, `n` and `k`, along with two 2D integer arrays, `stayScore` and `travelScore`.

A tourist is visiting a country with `n` cities, where each city is **directly**  connected to every other city. The tourist's journey consists of **exactly**  `k` **0-indexed**  days, and they can choose **any**  city as their starting point.

Each day, the tourist has two choices:

- **Stay in the current city** : If the tourist stays in their current city `curr` during day `i`, they will earn `stayScore[i][curr]` points.
- **Move to another city** : If the tourist moves from their current city `curr` to city `dest`, they will earn `travelScore[curr][dest]` points.

Return the **maximum**  possible points the tourist can earn.

**Example 1:**

```bash
Input: n = 2, k = 1, stayScore = [[2,3]], travelScore = [[0,2],[1,0]]

Output: 3
```

Explanation:

The tourist earns the maximum number of points by starting in city 1 and staying in that city.

**Example 2:**

```bash
Input: n = 3, k = 2, stayScore = [[3,4,2],[2,1,2]], travelScore = [[0,2,1],[2,0,4],[3,2,0]]

Output: 8
```

Explanation:

The tourist earns the maximum number of points by starting in city 1, staying in that city on day 0, and traveling to city 2 on day 1.

**Constraints:**

- `1 <= n <= 200`
- `1 <= k <= 200`
- `n == travelScore.length == travelScore[i].length == stayScore[i].length`
- `k == stayScore.length`
- `1 <= stayScore[i][j] <= 100`
- `0 <= travelScore[i][j] <= 100`
- `travelScore[i][i] == 0`

## Hints/Notes

- 2024/11/01
- dp
- [0x3F's solution](https://leetcode.cn/problems/maximum-points-tourist-can-earn/solutions/2966805/jiao-ni-yi-bu-bu-si-kao-dpcong-ji-yi-hua-vro4/)(checked)
- Biweekly Contest 142

## Solution

Language: **C++**

```C++
class Solution {
public:
    // the meaning of dp[i][j]: at the start of day j, the traveler is in city i
    // what's the max points he can earn
    vector<vector<int>> dp;
    // learning from the contest: i forget to initialize the global variable
    int n_, k_;

    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        dp.resize(n, vector<int>(k, -1));
        int res = 0;
        k_ = k; n_ = n;
        for (int i = 0; i < n; i++) {
            res = max(res, dfs(i, 0, stayScore, travelScore));
        }
        return res;
    }

    // i is the city index, j is the day index
    int dfs(int i, int j, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        if (j == k_) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int res = stayScore[j][i] + dfs(i, j + 1, stayScore, travelScore);
        for (int k = 0; k < n_; k++) {
            if (k != i) {
                int tmp = travelScore[i][k] + dfs(k, j + 1, stayScore, travelScore);
                res = max(res, tmp);
            }
        }
        dp[i][j] = res;
        return res;
    }
};
```
