---
title: 815. Bus Routes
categories: Leetcode
date: 2025-04-06 12:36:37
tags:
    - Array
    - Hash Table
    - Breadth-First Search
---

[815. Bus Routes](https://leetcode.com/problems/bus-routes/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-six-months)

## Description

You are given an array `routes` representing bus routes where `routes[i]` is a bus route that the `i^th` bus repeats forever.

- For example, if `routes[0] = [1, 5, 7]`, this means that the `0^th` bus travels in the sequence `1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ...` forever.

You will start at the bus stop `source` (You are not on any bus initially), and you want to go to the bus stop `target`. You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from `source` to `target`. Return `-1` if it is not possible.

**Example 1:**

```bash
Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
```

**Example 2:**

```bash
Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
Output: -1
```

**Constraints:**

- `1 <= routes.length <= 500`.
- `1 <= routes[i].length <= 10^5`
- All the values of `routes[i]` are **unique** .
- `sum(routes[i].length) <= 10^5`
- `0 <= routes[i][j] < 10^6`
- `0 <= source, target < 10^6`

## Hints/Notes

- 2025/04/05 Q2
- bfs
- [Leetcode solution](https://leetcode.com/problems/bus-routes/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> stopToRoutes;
        for (int i = 0; i < routes.size(); i++) {
            auto& r = routes[i];
            for (int stop : r) {
                stopToRoutes[stop].push_back(i);
            }
        }
        queue<int> q;
        q.push(source);
        int num = 0, n = routes.size();
        vector<bool> routesVisited(n, false);
        unordered_set<int> stopsVisited;
        stopsVisited.insert(source);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curStop = q.front();
                q.pop();
                if (curStop == target) {
                    return num;
                }
                for (int routeId : stopToRoutes[curStop]) {
                    if (routesVisited[routeId]) {
                        continue;
                    }
                    for (int stop : routes[routeId]) {
                        if (stopsVisited.contains(stop)) {
                            continue;
                        }
                        stopsVisited.insert(stop);
                        q.push(stop);
                    }
                    routesVisited[routeId] = true;
                }
            }
            num++;
        }
        return -1;
    }
};
```
