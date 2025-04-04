---
title: 1824. Minimum Sideway Jumps
categories: Leetcode
date: 2025-03-28 01:43:37
tags:
    - Array
    - Dynamic Programming
    - Greedy
---

[1824. Minimum Sideway Jumps](https://leetcode.com/problems/minimum-sideway-jumps/description/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days)

## Description

There is a **3 lane road**  of length `n` that consists of `n + 1` **points**  labeled from `0` to `n`. A frog **starts**  at point `0` in the **second ** lane** ** and wants to jump to point `n`. However, there could be obstacles along the way.

You are given an array `obstacles` of length `n + 1` where each `obstacles[i]` (**ranging from 0 to 3** ) describes an obstacle on the lane `obstacles[i]` at point `i`. If `obstacles[i] == 0`, there are no obstacles at point `i`. There will be **at most one**  obstacle in the 3 lanes at each point.

- For example, if `obstacles[2] == 1`, then there is an obstacle on lane 1 at point 2.

The frog can only travel from point `i` to point `i + 1` on the same lane if there is not an obstacle on the lane at point `i + 1`. To avoid obstacles, the frog can also perform a **side jump**  to jump to **another**  lane (even if they are not adjacent) at the **same**  point if there is no obstacle on the new lane.

- For example, the frog can jump from lane 3 at point 3 to lane 1 at point 3.

Return the **minimum number of side jumps**  the frog needs to reach **any lane**  at point n starting from lane `2` at point 0.

**Note:**  There will be no obstacles on points `0` and `n`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/03/25/ic234-q3-ex1.png" style="width: 500px; height: 244px;">

```bash
Input: obstacles = [0,1,2,3,0]
Output: 2
Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps (red arrows).
Note that the frog can jump over obstacles only when making side jumps (as shown at point 2).
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/03/25/ic234-q3-ex2.png" style="width: 500px; height: 196px;">

```bash
Input: obstacles = [0,1,1,3,3,0]
Output: 0
Explanation: There are no obstacles on lane 2. No side jumps are required.
```

**Example 3:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/03/25/ic234-q3-ex3.png" style="width: 500px; height: 196px;">

```bash
Input: obstacles = [0,2,1,0,3,0]
Output: 2
Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps.
```

**Constraints:**

- `obstacles.length == n + 1`
- `1 <= n <= 5 * 10^5`
- `0 <= obstacles[i] <= 3`
- `obstacles[0] == obstacles[n] == 0`

## Hints/Notes

- 2025/03/28 Q1
- dp
- [0x3F's solution](https://leetcode.cn/problems/minimum-sideway-jumps/solutions/2071617/cong-0-dao-1-de-0-1-bfspythonjavacgo-by-1m8z4/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<array<int, 3>> dp;

    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        dp.resize(n, {-1, -1, -1});
        return dfs(0, 1, obstacles);
    }

    int dfs(int index, int lane, vector<int>& obstacles) {
        if (index == obstacles.size() - 1) {
            return 0;
        }
        if (dp[index][lane] != -1) {
            return dp[index][lane];
        }
        int& res = dp[index][lane];
        res = INT_MAX;
        int next_obstacle = obstacles[index + 1] - 1;
        if (next_obstacle != lane) {
            res = dfs(index + 1, lane, obstacles);
        } else {
            for (int i = 0; i < 3; i++) {
                if (i == lane || obstacles[index] - 1 == i) {
                    continue;
                }
                res = min(res, 1 + dfs(index + 1, i, obstacles));
            }
        }
        return res;
    }
};
```
