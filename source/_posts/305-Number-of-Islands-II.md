---
title: 305. Number of Islands II
categories: Leetcode
date: 2025-03-16 15:09:49
tags:
    - Array
    - Hash Table
    - Union Find
---

[305. Number of Islands II](https://leetcode.com/problems/number-of-islands-ii/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

You are given an empty 2D binary grid `grid` of size `m x n`. The grid represents a map where `0`'s represent water and `1`'s represent land. Initially, all the cells of `grid` are water cells (i.e., all the cells are `0`'s).

We may perform an add land operation which turns the water at position into a land. You are given an array `positions` where positions[i] = [r<sub>i</sub>, c<sub>i</sub>] is the position (r<sub>i</sub>, c<sub>i</sub>) at which we should operate the `i^th` operation.

Return an array of integers `answer` where `answer[i]` is the number of islands after turning the cell (r<sub>i</sub>, c<sub>i</sub>) into a land.

An **island**  is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/03/10/tmp-grid.jpg" style="width: 500px; height: 294px;">

```bash
Input: m = 3, n = 3, positions = [[0,0],[0,1],[1,2],[2,1]]
Output: [1,1,2,3]
Explanation:
Initially, the 2d grid is filled with water.
- Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land. We have 1 island.
- Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land. We still have 1 island.
- Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land. We have 2 islands.
- Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land. We have 3 islands.
```

**Example 2:**

```bash
Input: m = 1, n = 1, positions = [[0,0]]
Output: [1]
```

**Constraints:**

- `1 <= m, n, positions.length <= 10^4`
- `1 <= m * n <= 10^4`
- `positions[i].length == 2`
- 0 <= r<sub>i</sub> < m
- 0 <= c<sub>i</sub> < n

**Follow up:**  Could you solve it in time complexity `O(k log(mn))`, where `k == positions.length`?

## Hints/Notes

- 2025/02/07 Q3
- union find
- [Leetcode solution](https://leetcode.com/problems/number-of-islands-ii/editorial/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    // idea: union find
    // 1. for each input point, check its adjacent points
    // 2. if there's no adjacent component, then the new point itself is a new island
    //    if there's one commponent
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> parent(m * n, -1);
        vector<int> res;
        int numIsland = 0;
        for (auto pos : positions) {
            int x = pos[0], y = pos[1], root = -1;
            if (parent[x * n + y] != -1) {
                res.push_back(numIsland);
                continue;
            }
            for (int k = 0; k < 4; k++) {
                int dx = x + dirs[k][0], dy = y + dirs[k][1], encoding = dx * n + dy;
                if (dx >= 0 && dx < m && dy >= 0 && dy < n && findRoot(encoding, parent) != -1) {
                    root = findRoot(encoding, parent);
                    break;
                }
            }
            if (root == -1) {
                numIsland++;
                parent[x * n + y] = x * n + y;
            } else {
                int encoding = x * n + y;
                merge(root, encoding, parent);
                for (int k = 0; k < 4; k++) {
                    int dx = x + dirs[k][0], dy = y + dirs[k][1], encoding = dx * n + dy;
                    if (dx >= 0 && dx < m && dy >= 0 && dy < n) {
                        int curRoot = findRoot(encoding, parent);
                        if (curRoot != -1 && curRoot != root) {
                            merge(root, curRoot, parent);
                            numIsland--;
                        }
                    }
                }
            }
            res.push_back(numIsland);
        }
        return res;
    }

    void merge(int root1, int root2, vector<int>& parent) {
        parent[root2] = root1;
    }

    int findRoot(int enc, vector<int>& parent) {
        if (parent[enc] == -1) {
            return -1;
        }
        if (parent[enc] != enc) {
            parent[enc] = findRoot(parent[enc], parent);
        }
        return parent[enc];
    }
};
```
