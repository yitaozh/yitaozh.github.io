---
title: 62. Unique Paths
categories: Leetcode
date: 2024-12-23 00:00:27
tags:
    - Math
    - Dynamic Programming
    - Combinatorics
---

[62. Unique Paths](https://leetcode.com/problems/unique-paths/description/?envType=problem-list-v2&envId=plakya4j)

## Description

There is a robot on an `m x n` grid. The robot is initially located at the **top-left corner**  (i.e., `grid[0][0]`). The robot tries to move to the **bottom-right corner**  (i.e., `grid[m - 1][n - 1]`). The robot can only move either down or right at any point in time.

Given the two integers `m` and `n`, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to `2 * 10^9`.

**Example 1:**

<img src="https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png" style="width: 400px; height: 183px;">

```bash
Input: m = 3, n = 7
Output: 28
```

**Example 2:**

```bash
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
```

**Constraints:**

- `1 <= m, n <= 100`

## Hints/Notes

- 2024/12/22
- dp or combinatorics
- [Leetcode solution](https://leetcode.com/problems/unique-paths/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = (dp[j] + dp[j - 1]);
            }
        }
        return dp[n - 1];
    }
};
```

combinations:

```C++
class Solution {
public:
    int uniquePaths(int m, int n) {
        long res = 1;
        // it's C(m + n - 2, n - 1)
        for (int i = 1; i < n; i++) {
            res = res * (m + i - 1) / i;
        }
        return res;
    }
};
```
