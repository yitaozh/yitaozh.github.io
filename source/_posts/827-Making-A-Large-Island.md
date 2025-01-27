---
title: 827. Making A Large Island
categories: Leetcode
date: 2025-01-27 13:02:31
tags:
    - Array
    - Depth-First Search
    - Breadth-First Search
    - Union Find
    - Matrix
---

[827. Making A Large Island](https://leetcode.com/problems/making-a-large-island/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

You are given an `n x n` binary matrix `grid`. You are allowed to change **at most one**  `0` to be `1`.

Return the size of the largest **island**  in `grid` after applying this operation.

An **island**  is a 4-directionally connected group of `1`s.

**Example 1:**

```bash
Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
```

**Example 2:**

```bash
Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
```

**Example 3:**

```bash
Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
```

**Constraints:**

- `n == grid.length`
- `n == grid[i].length`
- `1 <= n <= 500`
- `grid[i][j]` is either `0` or `1`.

## Hints/Notes

- 2025/01/26
- dfs + union find
- [0x3F's solution](https://leetcode.cn/problems/making-a-large-island/solutions/2808887/jian-ji-gao-xiao-ji-suan-dao-yu-de-mian-ab4h7/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    static constexpr int DIRs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> roots(m * n);
        vector<int> sizes(m * n);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        iota(roots.begin(), roots.end(), 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] && !visited[i][j]) {
                    int curRoot = i * n + j;
                    int size = 1;
                    queue<pair<int, int>> q;
                    visited[i][j] = 1;
                    q.emplace(i, j);
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int dx = x + DIRs[k][0], dy = y + DIRs[k][1];
                            if (dx >= 0 && dx < m && dy >= 0 && dy < n && grid[dx][dy] == 1 && !visited[dx][dy]) {
                                visited[dx][dy] = true;
                                roots[dx * n + dy] = curRoot;
                                size++;
                                q.emplace(dx, dy);
                            }
                        }
                    }
                    sizes[curRoot] = size;
                }
            }
        }
        int res = ranges::max(sizes);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) {
                    unordered_set<int> neighbors;
                    for (int k = 0; k < 4; k++) {
                        int x = i + DIRs[k][0], y = j + DIRs[k][1];
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y]) {
                            neighbors.insert(roots[x * n + y]);
                        }
                    }
                    int cur = 1;
                    for (int n : neighbors) {
                        cur += sizes[n];
                    }
                    res = max(res, cur);
                }
            }
        }
        return res;
    }
};
```
