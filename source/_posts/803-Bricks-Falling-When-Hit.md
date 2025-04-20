---
title: 803. Bricks Falling When Hit
categories: Leetcode
date: 2025-04-20 16:45:38
tags:
    - Array
    - Union Find
    - Matrix
---

[803. Bricks Falling When Hit](https://leetcode.com/problems/bricks-falling-when-hit/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-thirty-days)

## Description

You are given an `m x n` binary `grid`, where each `1` represents a brick and `0` represents an empty space. A brick is **stable**  if:

- It is directly connected to the top of the grid, or
- At least one other brick in its four adjacent cells is **stable** .

You are also given an array `hits`, which is a sequence of erasures we want to apply. Each time we want to erase the brick at the location hits[i] = (row<sub>i</sub>, col<sub>i</sub>). The brick on that location(if it exists) will disappear. Some other bricks may no longer be stable because of that erasure and will **fall** . Once a brick falls, it is **immediately**  erased from the `grid` (i.e., it does not land on other stable bricks).

Return an array `result`, where each `result[i]` is the number of bricks that will **fall**  after the `i^th` erasure is applied.

**Note**  that an erasure may refer to a location with no brick, and if it does, no bricks drop.

**Example 1:**

```bash
Input: grid = [[1,0,0,0],[1,1,1,0]], hits = [[1,0]]
Output: [2]
Explanation: Starting with the grid:
[[1,0,0,0],
 [1,1,1,0]]
We erase the underlined brick at (1,0), resulting in the grid:
[[1,0,0,0],
 [0,1,1,0]]
The two underlined bricks are no longer stable as they are no longer connected to the top nor adjacent to another stable brick, so they will fall. The resulting grid is:
[[1,0,0,0],
 [0,0,0,0]]
Hence the result is [2].
```

**Example 2:**

```bash
Input: grid = [[1,0,0,0],[1,1,0,0]], hits = [[1,1],[1,0]]
Output: [0,0]
Explanation: Starting with the grid:
[[1,0,0,0],
 [1,1,0,0]]
We erase the underlined brick at (1,1), resulting in the grid:
[[1,0,0,0],
 [1,0,0,0]]
All remaining bricks are still stable, so no bricks fall. The grid remains the same:
[[1,0,0,0],
 [1,0,0,0]]
Next, we erase the underlined brick at (1,0), resulting in the grid:
[[1,0,0,0],
 [0,0,0,0]]
Once again, all remaining bricks are still stable, so no bricks fall.
Hence the result is [0,0].
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 200`
- `grid[i][j]` is `0` or `1`.
- `1 <= hits.length <= 4 * 10^4`
- `hits[i].length == 2`
- `0 <= x<sub>i</sub><= m - 1`
- `0 <=y<sub>i</sub> <= n - 1`
- All (x<sub>i</sub>, y<sub>i</sub>) are unique.

## Hints/Notes

- 2025/04/20 Q2
- union find
- [Leetcode solution](https://leetcode.cn/problems/bricks-falling-when-hit/solutions/561849/803-da-zhuan-kuai-by-leetcode-r5kf/?envType=company&envId=snapchat&favoriteSlug=snapchat-thirty-days)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int m, n;
    static constexpr int DIRs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    unordered_map<int, pair<int, int>> roots;

    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        m = grid.size(); n = grid[0].size();
        set<pair<int, int>> h;
        for (int i = 0; i < hits.size(); i++) {
            int x = hits[i][0], y = hits[i][1];
            h.insert({x, y});
        }
        // previous 1, hit -> -1
        // previous 0, hit -> 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (h.contains({i, j})) {
                    if (grid[i][j]) {
                        grid[i][j] = -1;
                    }
                }
                if (grid[i][j] == 1) {
                    roots[encode(i, j)] = {encode(i, j), 1};
                }
            }
        }
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    visited[i][j] = true;
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int dx = x + DIRs[k][0], dy = y + DIRs[k][1];
                            if (dx >= 0 && dx < m && dy >= 0 && dy < n && grid[dx][dy] == 1 && !visited[dx][dy]) {
                                visited[dx][dy] = 1;
                                q.emplace(dx, dy);
                                roots[encode(dx, dy)] = {encode(i, j), -1};
                                roots[encode(i, j)].second++;
                            }
                        }
                    }
                }
            }
        }
        vector<int> res;
        for (int i = hits.size() - 1; i >= 0; i--) {
            int x = hits[i][0], y = hits[i][1];
            if (grid[x][y] == 0) {
                res.push_back(0);
                continue;
            }
            set<pair<int, int>> neighbors;
            for (int k = 0; k < 4; k++) {
                int dx = x + DIRs[k][0], dy = y + DIRs[k][1];
                if (dx >= 0 && dx < m && dy >= 0 && dy < n && grid[dx][dy] == 1) {
                    auto root = findRoot(encode(dx, dy));
                    neighbors.insert(root);
                }
            }
            int cur = 0;
            if (neighbors.empty()) {
                roots[encode(x, y)] = {encode(x, y), 1};
            } else if (neighbors.size() == 1) {
                auto it = neighbors.begin();
                if (it->first < n) {
                    roots[encode(x, y)] = {it->first, -1};
                    roots[it->first].second++;
                } else {
                    int enc = it->first, num = it->second;
                    roots[enc] = {encode(x, y), -1};
                    roots[encode(x, y)] = {encode(x, y), 1 + num};
                    if (x == 0) {
                        cur = num;
                    }
                }

            } else {
                vector<pair<int, int>> v(neighbors.begin(), neighbors.end());
                int potential_root = -1;
                for (auto root: v) {
                    if (root.first < n) {
                        potential_root = root.first;
                        break;
                    }
                }
                if (potential_root != -1) {
                    roots[encode(x, y)] = {potential_root, -1};
                    roots[potential_root].second++;
                    for (auto [root, num] : v) {
                        if (root != potential_root) {
                            roots[root] = {potential_root, -1};
                            roots[potential_root].second += num;
                            if (root >= n) {
                                cur += num;
                            }
                        }
                    }
                } else {
                    potential_root = v[0].first;
                    roots[encode(x, y)] = {potential_root, -1};
                    roots[potential_root].second++;
                    for (auto [root, num] : v) {
                        if (root != potential_root) {
                            roots[root] = {potential_root, -1};
                            roots[potential_root].second += num;
                        }
                    }
                }
            }
            res.push_back(cur);
            grid[x][y] = 1;
        }
        ranges::reverse(res);
        return res;
    }

    int encode(int i, int j) {
        return i * n + j;
    }

    pair<int, int> findRoot(int code) {
        if (roots[code].first != code) {
            roots[code] = findRoot(roots[code].first);
        }
        return roots[code];
    }
};
```
