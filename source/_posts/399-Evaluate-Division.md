---
title: 399. Evaluate Division
categories: Leetcode
date: 2025-04-27 14:36:34
tags:
    - Array
    - String
    - Depth-First Search
    - Breadth-First Search
    - Union Find
    - Graph
    - Shortest Path
---

[399. Evaluate Division](https://leetcode.com/problems/evaluate-division/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-six-months)

## Description

You are given an array of variable pairs `equations` and an array of real numbers `values`, where `equations[i] = [A<sub>i</sub>, B<sub>i</sub>]` and `values[i]` represent the equation `A<sub>i</sub> / B<sub>i</sub> = values[i]`. Each `A<sub>i</sub>` or `B<sub>i</sub>` is a string that represents a single variable.

You are also given some `queries`, where `queries[j] = [C<sub>j</sub>, D<sub>j</sub>]` represents the `j^th` query where you must find the answer for `C<sub>j</sub> / D<sub>j</sub> = ?`.

Return the answers to all queries. If a single answer cannot be determined, return `-1.0`.

**Note:**  The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

**Note:** The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.

**Example 1:**

```bash
Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation:
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
note: x is undefined => -1.0
```

**Example 2:**

```bash
Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
```

**Example 3:**

```bash
Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
```

**Constraints:**

- `1 <= equations.length <= 20`
- `equations[i].length == 2`
- 1 <= A<sub>i</sub>.length, B<sub>i</sub>.length <= 5
- `values.length == equations.length`
- `0.0 < values[i] <= 20.0`
- `1 <= queries.length <= 20`
- `queries[i].length == 2`
- 1 <= C<sub>j</sub>.length, D<sub>j</sub>.length <= 5
- A<sub>i</sub>, B<sub>i</sub>, C<sub>j</sub>, D<sub>j</sub> consist of lower case English letters and digits.

## Hints/Notes

- 2025/04/23 Q1
- dfs
- [Leetcode solution](https://leetcode.com/problems/evaluate-division/editorial)

## Solution

Language: **C++**

```C++
class Solution {
public:
    unordered_map<string, unordered_map<string, double>> graph;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // build the graph and union find roots
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            auto& equation = equations[i];
            string dividend = equation[0], divisor = equation[1];
            double val = values[i];
            graph[dividend][divisor] = val;
            graph[divisor][dividend] = 1.0 / val;
        }

        vector<double> res;
        unordered_set<string> visited;
        for (auto& q : queries) {
            string dividend = q[0], divisor = q[1];
            if (!graph.contains(dividend) || !graph.contains(divisor)) {
                res.push_back(-1.0);
            } else {
                res.push_back(dfs(dividend, divisor, visited));
            }
        }
        return res;
    }

    double dfs(string root, string target, unordered_set<string>& visited) {
        if (root == target) {
            return 1.0;
        }
        visited.insert(root);
        double mx = -1.0;
        for (auto [u, v]: graph[root]) {
            if (!visited.contains(u)) {
                mx = max(mx, dfs(u, target, visited) * v);
            }
        }
        visited.erase(root);
        return mx < 0 ? -1 : mx;
    }
};
```
