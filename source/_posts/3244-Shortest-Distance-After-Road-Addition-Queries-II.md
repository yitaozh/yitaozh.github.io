---
title: 3244. Shortest Distance After Road Addition Queries II
categories: Leetcode
date: 2024-08-15 00:00:54
tags:
    - Array
    - Greedy
    - Graph
    - Ordered Set
---

[3244. Shortest Distance After Road Addition Queries II](https://leetcode.com/problems/shortest-distance-after-road-addition-queries-ii/description/)

## Description

You are given an integer `n` and a 2D integer array `queries`.

There are `n` cities numbered from `0` to `n - 1`. Initially, there is a **unidirectional**  road from city `i` to city `i + 1` for all `0 <= i < n - 1`.

queries[i] = [u<sub>i</sub>, v<sub>i</sub>] represents the addition of a new **unidirectional**  road from city u<sub>i</sub> to city v<sub>i</sub>. After each query, you need to find the **length**  of the **shortest path**  from city `0` to city `n - 1`.

There are no two queries such that `queries[i][0] < queries[j][0] < queries[i][1] < queries[j][1]`.

Return an array `answer` where for each `i` in the range `[0, queries.length - 1]`, `answer[i]` is the length of the shortest path from city `0` to city `n - 1` after processing the **first** `i + 1` queries.

**Example 1:**

```bash
Input: n = 5, queries = [[2,4],[0,2],[0,4]]

Output: [3,2,1]
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/06/28/image8.jpg" style="width: 350px; height: 60px;">

After the addition of the road from 2 to 4, the length of the shortest path from 0 to 4 is 3.

<img alt="" src="https://assets.leetcode.com/uploads/2024/06/28/image9.jpg" style="width: 350px; height: 60px;">

After the addition of the road from 0 to 2, the length of the shortest path from 0 to 4 is 2.

<img alt="" src="https://assets.leetcode.com/uploads/2024/06/28/image10.jpg" style="width: 350px; height: 96px;">

After the addition of the road from 0 to 4, the length of the shortest path from 0 to 4 is 1.

**Example 2:**

```bash
Input: n = 4, queries = [[0,3],[0,2]]

Output: [1,1]
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/06/28/image11.jpg" style="width: 300px; height: 70px;">

After the addition of the road from 0 to 3, the length of the shortest path from 0 to 3 is 1.

<img alt="" src="https://assets.leetcode.com/uploads/2024/06/28/image12.jpg" style="width: 300px; height: 70px;">

After the addition of the road from 0 to 2, the length of the shortest path remains 1.

**Constraints:**

- `3 <= n <= 10^5`
- `1 <= queries.length <= 10^5`
- `queries[i].length == 2`
- `0 <= queries[i][0] < queries[i][1] < n`
- `1 < queries[i][1] - queries[i][0]`
- There are no repeated roads among the queries.
- There are no two queries such that `i != j` and `queries[i][0] < queries[j][0] < queries[i][1] < queries[j][1]`.

## Hints/Notes

- 2024/08/07
- Union find
- [0x3F's solution](https://leetcode.cn/problems/shortest-distance-after-road-addition-queries-ii/solutions/2868558/qu-jian-bing-cha-ji-pythonjavacgo-by-end-a9k7/)(checked)
- Weekly Contest 409

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> nodes;

    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        nodes.resize(n - 1, 0);
        iota(nodes.begin(), nodes.end(), 0);
        vector<int> res;
        int count = n - 1;
        for (auto q : queries) {
            int l = find(q[0]), r = find(q[1] - 1);
            // merge all the way from l, l + 1, ... r - 1 -> r
            while (l != r) {
                merge(l, r);
                count--;
                l = find(l + 1);
            }
            res.push_back(count);
        }
        return res;
    }

    void merge(int l, int r) { nodes[l] = r; }

    int find(int node) {
        if (node != nodes[node]) {
            nodes[node] = find(nodes[node]);
        }
        return nodes[node];
    }
};
```
