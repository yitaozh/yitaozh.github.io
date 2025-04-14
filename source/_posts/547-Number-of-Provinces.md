---
title: 547. Number of Provinces
categories: Leetcode
date: 2025-04-14 03:48:51
tags:
    - Depth-First Search
    - Breadth-First Search
    - Union Find
    - Graph
---

[547. Number of Provinces](https://leetcode.com/problems/number-of-provinces/description/?envType=company&envId=doordash&favoriteSlug=doordash-more-than-six-months)

## Description

There are `n` cities. Some of them are connected, while some are not. If city `a` is connected directly with city `b`, and city `b` is connected directly with city `c`, then city `a` is connected indirectly with city `c`.

A **province**  is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an `n x n` matrix `isConnected` where `isConnected[i][j] = 1` if the `i^th` city and the `j^th` city are directly connected, and `isConnected[i][j] = 0` otherwise.

Return the total number of **provinces** .

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/12/24/graph1.jpg" style="width: 222px; height: 142px;">

```bash
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/12/24/graph2.jpg" style="width: 222px; height: 142px;">

```bash
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
```

**Constraints:**

- `1 <= n <= 200`
- `n == isConnected.length`
- `n == isConnected[i].length`
- `isConnected[i][j]` is `1` or `0`.
- `isConnected[i][i] == 1`
- `isConnected[i][j] == isConnected[j][i]`

## Hints/Notes

- 2025/04/12 Q2
- union find
- [0x3F's solution](https://leetcode.com/problems/number-of-provinces/editorial/?envType=company&envId=doordash&favoriteSlug=doordash-more-than-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> roots(n);
        int res = n;
        iota(roots.begin(), roots.end(), 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j]) {
                    int rootI = findRoot(i, roots), rootJ = findRoot(j, roots);
                    if (rootI != rootJ) {
                        roots[rootI] = rootJ;
                        res--;
                    }
                }
            }
        }
        return res;
    }

    int findRoot(int node, vector<int>& roots) {
        if (node != roots[node]) {
            roots[node] = findRoot(roots[node], roots);
        }
        return roots[node];
    }
};
```
