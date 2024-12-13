---
title: 3310. Remove Methods From Project
categories: Leetcode
date: 2024-10-19 16:25:52
tags:
    - Depth-First Search
    - Breadth-First Search
    - Graph
---

[3310. Remove Methods From Project](https://leetcode.com/problems/remove-methods-from-project/description/)

## Description

You are maintaining a project that has `n` methods numbered from `0` to `n - 1`.

You are given two integers `n` and `k`, and a 2D integer array `invocations`, where invocations[i] = [a<sub>i</sub>, b<sub>i</sub>] indicates that method a<sub>i</sub> invokes method b<sub>i</sub>.

There is a known bug in method `k`. Method `k`, along with any method invoked by it, either **directly**  or **indirectly** , are considered **suspicious**  and we aim to remove them.

A group of methods can only be removed if no method **outside**  the group invokes any methods **within**  it.

Return an array containing all the remaining methods after removing all the **suspicious**  methods. You may return the answer in any order. If it is not possible to remove **all**  the suspicious methods, **none**  should be removed.

**Example 1:**

```bash
Input: n = 4, k = 1, invocations = [[1,2],[0,1],[3,2]]

Output: [0,1,2,3]
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/07/18/graph-2.png" style="width: 200px; height: 200px;">

Method 2 and method 1 are suspicious, but they are directly invoked by methods 3 and 0, which are not suspicious. We return all elements without removing anything.

**Example 2:**

```bash
Input: n = 5, k = 0, invocations = [[1,2],[0,2],[0,1],[3,4]]

Output: [3,4]
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/07/18/graph-3.png" style="width: 200px; height: 200px;">

Methods 0, 1, and 2 are suspicious and they are not directly invoked by any other method. We can remove them.

**Example 3:**

```bash
Input: n = 3, k = 2, invocations = [[1,2],[0,1],[2,0]]

Output: []
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/07/20/graph.png" style="width: 200px; height: 200px;">

All methods are suspicious. We can remove them.

**Constraints:**

- `1 <= n <= 10^5`
- `0 <= k <= n - 1`
- `0 <= invocations.length <= 2 * 10^5`
- invocations[i] == [a<sub>i</sub>, b<sub>i</sub>]
- 0 <= a<sub>i</sub>, b<sub>i</sub> <= n - 1
- a<sub>i</sub> != b<sub>i</sub>
- `invocations[i] != invocations[j]`

## Hints/Notes

- 2024/09/21
- dfs
- [0x3F's solution](https://leetcode.cn/problems/remove-methods-from-project/solutions/2940460/liang-ci-dfspythonjavacgo-by-endlesschen-cjat/)(checked)
- Weekly Contest 418

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> graph;
    set<int> suspicious;
    int k_;

    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        k_ = k;
        graph.resize(n, vector<int>());
        buildGraph(invocations);
        dfs(k);
        for (auto invocation : invocations) {
            int from = invocation[0], to = invocation[1];
            if (!suspicious.contains(from) && suspicious.contains(to)) {
                vector<int> res(n);
                iota(res.begin(), res.end(), 0);
                return res;
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (!suspicious.contains(i)) {
                res.push_back(i);
            }
        }
        return res;
    }

    void dfs(int u) {
        suspicious.insert(u);
        for (int v : graph[u]) {
            if (!suspicious.contains(v)) {
                dfs(v);
            }
        }
    }

    void buildGraph(vector<vector<int>>& invocations) {
        for (auto invocation : invocations) {
            int from = invocation[0], to = invocation[1];
            graph[from].push_back(to);
        }
    }
};
```
