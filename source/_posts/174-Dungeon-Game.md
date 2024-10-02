---
title: 174. Dungeon Game
categories: Leetcode
date: 2024-08-02 00:39:20
tags:
    - Array
    - Dynamic Programming
    - Matrix
---

[174. Dungeon Game](https://leetcode.com/problems/dungeon-game/description/)

## Description

The demons had captured the princess and imprisoned her in **the bottom-right corner**  of a `dungeon`. The `dungeon` consists of `m x n` rooms laid out in a 2D grid. Our valiant knight was initially positioned in **the top-left room**  and must fight his way through `dungeon` to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to `0` or below, he dies immediately.

Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).

To reach the princess as quickly as possible, the knight decides to move only **rightward**  or **downward**  in each step.

Return the knight's minimum initial health so that he can rescue the princess.

**Note**  that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/03/13/dungeon-grid-1.jpg" style="width: 253px; height: 253px;">

```bash
Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
Output: 7
Explanation: The initial health of the knight must be at least 7 if he follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.
```

**Example 2:**

```bash
Input: dungeon = [[0]]
Output: 1
```

**Constraints:**

- `m == dungeon.length`
- `n == dungeon[i].length`
- `1 <= m, n <= 200`
- `-1000 <= dungeon[i][j] <= 1000`

## Hints/Notes

- dp

## Solution

Language: **C++**

```C++
class Solution {
public:
    // the meaning of dp[i][j]:
    //  the number need at i,j to make the knight survive,
    //  not only in this cell but also in the later cells
    vector<vector<int>> dp;
    int m, n;

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        dp.resize(m, vector<int>(n, INT_MIN));
        int res = traverse(0, 0, dungeon);
        return res;
    }

    int traverse(int i, int j, vector<vector<int>>& dungeon) {
        if (i >= m || j >= n) {
            return INT_MAX;
        }
        if (i == m - 1 && j == n - 1) {
            return max(1, -dungeon[i][j] + 1);
        }
        if (dp[i][j] != INT_MIN) {
            return dp[i][j];
        }
        int down = traverse(i + 1, j, dungeon);
        int right = traverse(i, j + 1, dungeon);
        int res = max(1, min(down, right) - dungeon[i][j]);
        dp[i][j] = res;
        return res;
    }
};
```
