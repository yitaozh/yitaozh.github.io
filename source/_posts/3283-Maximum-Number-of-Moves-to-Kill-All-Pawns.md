---
title: 3283. Maximum Number of Moves to Kill All Pawns
categories: Leetcode
date: 2024-10-08 15:58:55
tags:
    - Array
    - Math
    - Bit Manipulation
    - Breadth-First Search
    - Game Theory
    - Bitmask
---

[3283. Maximum Number of Moves to Kill All Pawns](https://leetcode.com/problems/maximum-number-of-moves-to-kill-all-pawns/description/)

## Description

There is a `50 x 50` chessboard with **one**  knight and some pawns on it. You are given two integers `kx` and `ky` where `(kx, ky)` denotes the position of the knight, and a 2D array `positions` where positions[i] = [x<sub>i</sub>, y<sub>i</sub>] denotes the position of the pawns on the chessboard.

Alice and Bob play a turn-based game, where Alice goes first. In each player's turn:

- The player selects a pawn that still exists on the board and captures it with the knight in the **fewest**  possible **moves** . **Note**  that the player can select **any**  pawn, it **might not**  be one that can be captured in the **least**  number of moves.
- In the process of capturing the selected pawn, the knight **may**  pass other pawns **without**  capturing them. **Only**  the selected pawn can be captured in this turn.

Alice is trying to **maximize**  the **sum**  of the number of moves made by both players until there are no more pawns on the board, whereas Bob tries to **minimize**  them.

Return the **maximum**  total number of moves made during the game that Alice can achieve, assuming both players play **optimally** .

Note that in one **move**, a chess knight has eight possible positions it can move to, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.

<img src="https://assets.leetcode.com/uploads/2024/08/01/chess_knight.jpg" style="width: 275px; height: 273px;">

**Example 1:**

```bash
Input: kx = 1, ky = 1, positions = [[0,0]]

Output: 4
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/08/16/gif3.gif" style="width: 275px; height: 275px;">

The knight takes 4 moves to reach the pawn at `(0, 0)`.

**Example 2:**

```bash
Input: kx = 0, ky = 2, positions = [[1,1],[2,2],[3,3]]

Output: 8
```

Explanation:

**<img alt="" src="https://assets.leetcode.com/uploads/2024/08/16/gif4.gif" style="width: 320px; height: 320px;">**

- Alice picks the pawn at `(2, 2)` and captures it in two moves: `(0, 2) -> (1, 4) -> (2, 2)`.
- Bob picks the pawn at `(3, 3)` and captures it in two moves: `(2, 2) -> (4, 1) -> (3, 3)`.
- Alice picks the pawn at `(1, 1)` and captures it in four moves: `(3, 3) -> (4, 1) -> (2, 2) -> (0, 3) -> (1, 1)`.

**Example 3:**

```bash
Input: kx = 0, ky = 0, positions = [[1,2],[2,4]]

Output: 3
```

Explanation:

- Alice picks the pawn at `(2, 4)` and captures it in two moves: `(0, 0) -> (1, 2) -> (2, 4)`. Note that the pawn at `(1, 2)` is not captured.
- Bob picks the pawn at `(1, 2)` and captures it in one move: `(2, 4) -> (1, 2)`.

**Constraints:**

- `0 <= kx, ky <= 49`
- `1 <= positions.length <= 15`
- `positions[i].length == 2`
- `0 <= positions[i][0], positions[i][1] <= 49`
- All `positions[i]` are unique.
- The input is generated such that `positions[i] != [kx, ky]` for all `0 <= i < positions.length`.

## Hints/Notes

- 2024/09/06
- array has better performance than vector, when accessing the same data block many times
- state compression dp
- [0x3F's solution](https://leetcode.cn/problems/maximum-number-of-moves-to-kill-all-pawns/solutions/2909069/pai-lie-xing-zhuang-ya-dpxiang-lin-xiang-q49q/)(checked)
- Weekly Contest 414

## Solution

Language: **C++**

```C++
class Solution {
public:
    int BOUNDARY = 50;
    array<array<int, 2>, 8> DIRS = {{{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}}};
    vector<unordered_map<int, int>> steps;
    vector<vector<bool>> visited;
    // the meaning of dp[i][j]: with previous point at i, and visited points as j, what' the
    // maximum result we can get
    vector<vector<int>> dp;
    int n_;

    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        positions.push_back({kx, ky});
        int n = positions.size();
        n_ = n;
        steps.resize(n);
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            auto p = positions[i];
            pos[encode(p[0], p[1])] = i;;
        }
        for (int i = 0; i < positions.size(); i++) {
            auto p = positions[i]; int x = p[0], y = p[1];
            visited = vector<vector<bool>>(50, vector<bool>(50, false));
            queue<pair<int, int>> q;
            q.push({x, y});
            int cur = 0;
            while (steps[i].size() < n) {
                int sz = q.size();
                for (int j = 0; j < sz; j++) {
                    auto p = q.front();
                    q.pop();
                    int x1 = p.first, y1 = p.second;
                    int cipher = encode(x1, y1);
                    if (pos.contains(cipher)) {
                        steps[i][pos[cipher]] = cur;
                        steps[pos[cipher]][i] = cur;
                    }
                    cut(x1, y1, q);
                }
                cur++;
            }
        }
        // by this time, we have pre-calculated the steps needed to reach each pawn
        dp.resize(n, vector<int>(1 << (n - 1), -1));
        int res = dfs(n - 1, 0, positions);
        return res;
    }

    int dfs(int prev, int mask, vector<vector<int>>& positions) {
        int count = __builtin_popcount(mask);
        if (count == n_ - 1) {
            return 0;
        }
        if (dp[prev][mask] != -1) {
            return dp[prev][mask];
        }
        auto p = positions[prev];
        int x = p[0], y = p[1];
        int res = count % 2 ? INT_MAX : INT_MIN;

        for (int i = 0; i < n_ - 1; i++) {
            if ((mask >> i) & 1) {
                continue;
            }
            if (count % 2) {
                res = min(res, steps[prev][i] + dfs(i, mask | (1 << i), positions));
            } else {
                res = max(res, steps[prev][i] + dfs(i, mask | (1 << i), positions));
            }
        }
        dp[prev][mask] = res;
        return res;
    }

    void cut(int x, int y, queue<pair<int, int>>& q) {
        for (auto d : DIRS) {
            int x1 = x + d[0], y1 = y + d[1];
            if (x1 < 0 || x1 >= BOUNDARY || y1 < 0 || y1 >= BOUNDARY || visited[x1][y1]) {
                continue;
            }
            visited[x1][y1] = true;
            q.push({x1, y1});
        }
    }

    int encode(int x, int y) {
        return x * 50 + y;
    }
};
```
