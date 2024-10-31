---
title: 3275. K-th Nearest Obstacle Queries
categories: Leetcode
date: 2024-10-06 21:44:23
tags:
    - Array
    - Heap (Priority Queue)
---

[3275. K-th Nearest Obstacle Queries](https://leetcode.com/problems/k-th-nearest-obstacle-queries/description/)

## Description

There is an infinite 2D plane.

You are given a positive integer `k`. You are also given a 2D array `queries`, which contains the following queries:

- `queries[i] = [x, y]`: Build an obstacle at coordinate `(x, y)` in the plane. It is guaranteed that there is **no**  obstacle at this coordinate when this query is made.

After each query, you need to find the **distance**  of the `k^th` **nearest**  obstacle from the origin.

Return an integer array `results` where `results[i]` denotes the `k^th` nearest obstacle after query `i`, or `results[i] == -1` if there are less than `k` obstacles.

**Note**  that initially there are **no**  obstacles anywhere.

The **distance**  of an obstacle at coordinate `(x, y)` from the origin is given by `|x| + |y|`.

**Example 1:**

```bash
Input: queries = [[1,2],[3,4],[2,3],[-3,0]], k = 2

Output: [-1,7,5,3]
```

Explanation:

- Initially, there are 0 obstacles.
- After `queries[0]`, there are less than 2 obstacles.
- After `queries[1]`, there are obstacles at distances 3 and 7.
- After `queries[2]`, there are obstacles at distances 3, 5, and 7.
- After `queries[3]`, there are obstacles at distances 3, 3, 5, and 7.

**Example 2:**

```bash
Input: queries = [[5,5],[4,4],[3,3]], k = 1

Output: [10,8,6]
```

Explanation:

- After `queries[0]`, there is an obstacle at distance 10.
- After `queries[1]`, there are obstacles at distances 8 and 10.
- After `queries[2]`, there are obstacles at distances 6, 8, and 10.

**Constraints:**

- `1 <= queries.length <= 2 * 10^5`
- All `queries[i]` are unique.
- `-10^9 <= queries[i][0], queries[i][1] <= 10^9`
- `1 <= k <= 10^5`

## Hints/Notes

- priority queue
- Weekly Contest 413
- [0x3F's solution](https://leetcode.cn/problems/k-th-nearest-obstacle-queries/solutions/2900061/zui-da-dui-wei-hu-qian-k-xiao-pythonjava-h15x/)

## Solution

Language: **C++**

faster approach

```C++
class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;
        int n = queries.size();
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++) {
            auto& q = queries[i];
            int x = abs(q[0]), y = abs(q[1]);
            pq.push(x + y);
            if (pq.size() > k) {
                pq.pop();
            }
            if (pq.size() == k) {
                res[i] = pq.top();
            }
        }
        return res;
    }
};
```

```C++
class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;
        vector<int> res;
        for (auto q : queries) {
            int x = abs(q[0]), y = abs(q[1]);
            pq.push(x + y);
            if (pq.size() > k) {
                pq.pop();
            }
            if (pq.size() < k) {
                res.push_back(-1);
            } else {
                res.push_back(pq.top());
            }
        }
        return res;
    }
};
```
