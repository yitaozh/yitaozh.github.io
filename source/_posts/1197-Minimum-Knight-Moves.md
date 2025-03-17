---
title: 1197. Minimum Knight Moves
categories: Leetcode
date: 2025-02-21 01:22:05
tags:
    - Breadth-First Search
---

[1197. Minimum Knight Moves](https://leetcode.com/problems/minimum-knight-moves/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

In an **infinite**  chess board with coordinates from `-infinity` to `+infinity`, you have a **knight**  at square `[0, 0]`.

A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.

<img src="https://assets.leetcode.com/uploads/2018/10/12/knight.png" style="height: 250px; width: 250px;">

Return the minimum number of steps needed to move the knight to the square `[x, y]`. It is guaranteed the answer exists.

**Example 1:**

```bash
Input: x = 2, y = 1
Output: 1
Explanation: [0, 0] → [2, 1]
```

**Example 2:**

```bash
Input: x = 5, y = 5
Output: 4
Explanation: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]
```

**Constraints:**

- `-300 <= x, y <= 300`
- `0 <= |x| + |y| <= 300`

## Hints/Notes

- 2025/02/12 Q1
- bfs
- [Leetcode solution](https://leetcode.com/problems/minimum-knight-moves/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    static constexpr int DIRs[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                                       {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    int minKnightMoves(int x, int y) {
        if (x == 0 && y == 0) {
            return 0;
        }
        vector<vector<bool>> visited(601, vector<bool>(601, false));
        x += 300;
        y += 300;
        queue<pair<int, int>> q;
        q.emplace(300, 300);
        visited[300][300] = true;
        int step = 1;
        while (true) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [a, b] = q.front();
                q.pop();
                for (int j = 0; j < 8; j++) {
                    int dx = a + DIRs[j][0], dy = b + DIRs[j][1];
                    if (dx == x && dy == y) {
                        return step;
                    }
                    if (dx >= 0 && dx <= 600 && dy >= 0 && dy <= 600 && !visited[dx][dy]) {
                        visited[dx][dy] = true;
                        q.emplace(dx, dy);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
```
