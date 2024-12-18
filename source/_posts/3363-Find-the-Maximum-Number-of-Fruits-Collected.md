---
title: 3363. Find the Maximum Number of Fruits Collected
categories: Leetcode
date: 2024-12-03 21:13:21
tags:
    - Array
    - Dynamic Programming
    - Matrix
---

[3363. Find the Maximum Number of Fruits Collected](https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/description/)

## Description

There is a game dungeon comprised of`n x n` rooms arranged in a grid.

You are given a 2D array `fruits` of size `n x n`, where `fruits[i][j]` represents the number of fruits in the room `(i, j)`. Three children will play in the game dungeon, with **initial**  positions at the corner rooms `(0, 0)`, `(0, n - 1)`, and `(n - 1, 0)`.

The children will make **exactly**  `n - 1` moves according to the following rules to reach the room `(n - 1, n - 1)`:

- The child starting from `(0, 0)` must move from their current room `(i, j)` to one of the rooms `(i + 1, j + 1)`, `(i + 1, j)`, and `(i, j + 1)` if the target room exists.
- The child starting from `(0, n - 1)` must move from their current room `(i, j)` to one of the rooms `(i + 1, j - 1)`, `(i + 1, j)`, and `(i + 1, j + 1)` if the target room exists.
- The child starting from `(n - 1, 0)` must move from their current room `(i, j)` to one of the rooms `(i - 1, j + 1)`, `(i, j + 1)`, and `(i + 1, j + 1)` if the target room exists.

When a child enters a room, they will collect all the fruits there. If two or more children enter the same room, only one child will collect the fruits, and the room will be emptied after they leave.

Return the **maximum**  number of fruits the children can collect from the dungeon.

**Example 1:**

```bash
Input: fruits = [[1,2,3,4],[5,6,8,7],[9,10,11,12],[13,14,15,16]]

Output: 100
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/10/15/example_1.gif" style="width: 250px; height: 214px;">

In this example:

- The 1^st child (green) moves on the path `(0,0) -> (1,1) -> (2,2) -> (3, 3)`.
- The 2^nd child (red) moves on the path `(0,3) -> (1,2) -> (2,3) -> (3, 3)`.
- The 3^rd child (blue) moves on the path `(3,0) -> (3,1) -> (3,2) -> (3, 3)`.

In total they collect `1 + 6 + 11 + 16 + 4 + 8 + 12 + 13 + 14 + 15 = 100` fruits.

**Example 2:**

```bash
Input: fruits = [[1,1],[1,1]]

Output: 4
```

Explanation:

In this example:

- The 1^st child moves on the path `(0,0) -> (1,1)`.
- The 2^nd child moves on the path `(0,1) -> (1,1)`.
- The 3^rd child moves on the path `(1,0) -> (1,1)`.

In total they collect `1 + 1 + 1 + 1 = 4` fruits.

**Constraints:**

- `2 <= n == fruits.length == fruits[i].length <= 1000`
- `0 <= fruits[i][j] <= 1000`

## Hints/Notes

- 2024/12/02
- brain teaser
- [0x3F's solution](https://leetcode.cn/problems/find-the-maximum-number-of-fruits-collected/solutions/2998667/nao-jin-ji-zhuan-wan-wang-ge-tu-dppython-gjcm/)(checked)
- Biweekly Contest 144

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> dp;
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int res = 0, n = fruits.size();
        for (int i = 0; i < n; i++) {
            res += fruits[i][i];
        }
        dp.resize(n, vector<int>(n, -1));
        res += dfs(n - 2, n - 1, fruits);
        rotate(fruits);
        dp.clear();
        dp.resize(n, vector<int>(n, -1));
        res += dfs(n - 2, n - 1, fruits);
        return res;
    }

    void rotate(vector<vector<int>>& fruits) {
        int n = fruits.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int tmp = fruits[i][j];
                fruits[i][j] = fruits[j][i];
                fruits[j][i] = tmp;
            }
        }
    }

    int dfs(int i, int j, vector<vector<int>>& fruits) {
        int n = fruits.size();
        if (j < n - 1 - i || j >= n) {
            return INT_MIN;
        }
        if (i == 0) {
            return fruits[i][j];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int res = 0;
        res = max(dfs(i - 1, j, fruits),
                  max(dfs(i - 1, j - 1, fruits), dfs(i - 1, j + 1, fruits))) +
              fruits[i][j];
        dp[i][j] = res;
        return res;
    }
};
```
