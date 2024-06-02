---
title: 3161. Block Placement Queries
categories: Leetcode
date: 2024-05-28 23:41:00
tags:
    - Array
    - Binary Search
    - Binary Indexed Tree
    - Segment Tree
---

[3161. Block Placement Queries](https://leetcode.com/problems/block-placement-queries/description/)

## Description

There exists an infinite number line, with its origin at 0 and extending towards the **positive**  x-axis.

You are given a 2D array `queries`, which contains two types of queries:

- For a query of type 1, `queries[i] = [1, x]`. Build an obstacle at distance `x` from the origin. It is guaranteed that there is **no**  obstacle at distance `x` when the query is asked.
- For a query of type 2, `queries[i] = [2, x, sz]`. Check if it is possible to place a block of size `sz` anywhere in the range `[0, x]` on the line, such that the block **entirely**  lies in the range `[0, x]`. A block **cannot ** be placed if it intersects with any obstacle, but it may touch it. Note that you do** not**  actually place the block. Queries are separate.

Return a boolean array `results`, where `results[i]` is `true` if you can place the block specified in the `i^th` query of type 2, and `false` otherwise.

**Example 1:**

```bash
Input: queries = [[1,2],[2,3,3],[2,3,1],[2,2,2]]

Output: [false,true,true]
```

Explanation:

**<img alt="" src="https://assets.leetcode.com/uploads/2024/04/22/example0block.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 309px; height: 129px; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="">**

For query 0, place an obstacle at `x = 2`. A block of size at most 2 can be placed before `x = 3`.

**Example 2:**

```bash
Input: queries = [[1,7],[2,7,6],[1,2],[2,7,5],[2,7,6]]

Output: [true,true,false]
```

Explanation:

**<img alt="" src="https://assets.leetcode.com/uploads/2024/04/22/example1block.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 310px; height: 130px; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="">**

- Place an obstacle at `x = 7` for query 0. A block of size at most 7 can be placed before `x = 7`.
- Place an obstacle at `x = 2` for query 2. Now, a block of size at most 5 can be placed before `x = 7`, and a block of size at most 2 before `x = 2`.

**Constraints:**

- `1 <= queries.length <= 15 * 10^4`
- `2 <= queries[i].length <= 3`
- `1 <= queries[i][0] <= 2`
- `1 <= x, sz <= min(5 * 10^4, 3 * queries.length)`
- The input is generated such that for queries of type 1, no obstacle exists at distance `x` when the query is asked.
- The input is generated such that there is at least one query of type 2.

## Hints/Notes

- Biweekly Contest 131
- segment tree

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> mx;

    vector<bool> getResults(vector<vector<int>>& queries) {
        int boundary = 0;
        for (auto query : queries) {
            boundary = max(boundary, query[1]);
        }
        boundary++;
        mx = vector<int>(boundary * 4, 0);
        set<int> obstacles{0, boundary};
        vector<bool> res;
        for (auto q : queries) {
            int x = q[1];
            auto it = obstacles.lower_bound(x);
            int pre = *prev(it); // x 左侧最近障碍物的位置
            if (q[0] == 1) {
                int nxt = *it;
                obstacles.insert(x);
                update(1, 0, boundary, x, x - pre);
                update(1, 0, boundary, nxt, nxt - x);
            } else {
                int max_gap = max(query(1, 0, boundary, pre), x - pre);
                res.push_back(max_gap >= q[2]);
            }
        }
        return res;
    }

    void update(int o, int l, int r, int i, int val) {
        if (l == r) {
            mx[o] = val;
            return;
        }
        int m = (r - l) / 2 + l;
        if (i <= m) {
            update(o * 2, l, m, i, val);
        } else {
            update(o * 2 + 1, m + 1, r, i, val);
        }
        mx[o] = max(mx[o * 2], mx[o * 2 + 1]);
    }

    int query(int o, int l, int r, int R) {
        if (r <= R) {
            return mx[o];
        }
        int m = (r - l) / 2 + l;
        if (R <= m) {
            return query(o * 2, l, m, R);
        }
        return max(mx[o * 2], query(o * 2 + 1, m + 1, r, R));
    }
};
```
