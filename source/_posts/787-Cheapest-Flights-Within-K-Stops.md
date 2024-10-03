---
title: 787. Cheapest Flights Within K Stops
categories: Leetcode
date: 2024-10-03 10:56:33
tags:
    - Dynamic Programming
    - Depth-First Search
    - Breadth-First Search
    - Graph
    - Heap (Priority Queue)
    - Shortest Path
---

[787. Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/description/)

## Description

There are `n` cities connected by some number of flights. You are given an array `flights` where flights[i] = [from<sub>i</sub>, to<sub>i</sub>, price<sub>i</sub>] indicates that there is a flight from city from<sub>i</sub> to city to<sub>i</sub> with cost price<sub>i</sub>.

You are also given three integers `src`, `dst`, and `k`, return **the cheapest price**  from `src` to `dst` with at most `k` stops. If there is no such route, return `-1`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-3drawio.png" style="width: 332px; height: 392px;">

```bash
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-1drawio.png" style="width: 332px; height: 242px;">

```bash
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
```

**Example 3:**

<img alt="" src="https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-2drawio.png" style="width: 332px; height: 242px;">

```bash
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
```

**Constraints:**

- `1 <= n <= 100`
- `0 <= flights.length <= (n * (n - 1) / 2)`
- `flights[i].length == 3`
- 0 <= from<sub>i</sub>, to<sub>i</sub> < n
- from<sub>i</sub> != to<sub>i</sub>
- 1 <= price<sub>i</sub> <= 10^4
- There will not be any multiple flights between two cities.
- `0 <= src, dst, k < n`
- `src != dst`

## Hints/Notes

- dp

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<pair<int, int>>> graph;
    int dst_;
    vector<vector<int>> dp;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        graph.resize(n, vector<pair<int, int>>());
        dp.resize(n, vector<int>(k + 2, -1));
        buildGraph(flights);
        dst_ = dst;
        int res = traverse(src, k + 1);
        return res == INT_MAX ? -1 : res;
    }

    int traverse(int src, int k) {
        if (k < 0) {
            return INT_MAX;
        }
        if (src == dst_) {
            return 0;
        }
        if (dp[src][k] != -1) {
            return dp[src][k];
        }
        long res = INT_MAX;
        for (auto p : graph[src]) {
            int v = p.first;
            int price = p.second;
            res = min(res, (long)price + traverse(v, k - 1));
        }
        dp[src][k] = res;
        return dp[src][k];
    }

    void buildGraph(vector<vector<int>>& flights) {
        for (auto flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            graph[from].push_back({to, price});
        }
    }
};
```
