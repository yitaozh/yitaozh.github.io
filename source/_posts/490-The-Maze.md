---
title: 490. The Maze
categories: Leetcode
date: 2025-02-20 17:41:31
tags:
    - Array
    - Depth-First Search
    - Breadth-First Search
    - Matrix
---

[490. The Maze](https://leetcode.com/problems/the-maze/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

There is a ball in a `maze` with empty spaces (represented as `0`) and walls (represented as `1`). The ball can go through the empty spaces by rolling **up, down, left or right** , but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the `m x n` `maze`, the ball's `start` position and the `destination`, where start = [start<sub>row</sub>, start<sub>col</sub>] and destination = [destination<sub>row</sub>, destination<sub>col</sub>], return `true` if the ball can stop at the destination, otherwise return `false`.

You may assume that **the borders of the maze are all walls**  (see examples).

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/03/31/maze1-1-grid.jpg" style="width: 573px; height: 573px;">

```bash
Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/03/31/maze1-2-grid.jpg" style="width: 573px; height: 573px;">

```bash
Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
Output: false
Explanation: There is no way for the ball to stop at the destination. Notice that you can pass through the destination but you cannot stop there.
```

**Example 3:**

```bash
Input: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
Output: false
```

**Constraints:**

- `m == maze.length`
- `n == maze[i].length`
- `1 <= m, n <= 100`
- `maze[i][j]` is `0` or `1`.
- `start.length == 2`
- `destination.length == 2`
- 0 <= start<sub>row</sub>, destination<sub>row</sub> < m
- 0 <= start<sub>col</sub>, destination<sub>col</sub> < n
- Both the ball and the destination exist in an empty space, and they will not be in the same position initially.
- The maze contains **at least 2 empty spaces** .

## Hints/Notes

- 2025/02/08
- DFS
- [Leetcode solution](https://leetcode.com/problems/the-maze/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    static constexpr int DIRs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        if (start == destination) {
            return true;
        }
        queue<pair<int, int>> q;
        q.emplace(start[0], start[1]);
        maze[start[0]][start[1]] = -1;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int j = 0; j < 4; j++) {
                int dx = x, dy = y;
                while (dx >= 0 && dx < m && dy >= 0 && dy < n && maze[dx][dy] != 1) {
                    dx += DIRs[j][0];
                    dy += DIRs[j][1];
                }
                dx -= DIRs[j][0]; dy -= DIRs[j][1];
                if (dx == destination[0] && dy == destination[1]) {
                    return true;
                }
                if (maze[dx][dy] == 0) {
                    maze[dx][dy] = -1;
                    q.emplace(dx, dy);
                }
            }
        }
        return false;
    }
};
```
