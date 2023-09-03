---
title: 990. Satisfiability of Equality Equations
categories: Leetcode
date: 2023-09-03 00:06:09
tags:
    - Array
    - String
    - Union Find
    - Graph
---

# [990\. Satisfiability of Equality Equations](https://leetcode.com/problems/satisfiability-of-equality-equations/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [String](https://leetcode.com/tag/https://leetcode.com/tag/string//), [Union Find](https://leetcode.com/tag/https://leetcode.com/tag/union-find//), [Graph](https://leetcode.com/tag/https://leetcode.com/tag/graph//)

You are given an array of strings `equations` that represent relationships between variables where each string `equations[i]` is of length `4` and takes one of two different forms: "x<sub>i</sub>==y<sub>i</sub>" or "x<sub>i</sub>!=y<sub>i</sub>".Here, x<sub>i</sub> and y<sub>i</sub> are lowercase letters (not necessarily different) that represent one-letter variable names.

Return `true` _if it is possible to assign integers to variable names so as to satisfy all the given equations, or_ `false` _otherwise_.

**Example 1:**

```bash
Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.
```

**Example 2:**

```bash
Input: equations = ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
```

**Constraints:**

* `1 <= equations.length <= 500`
* `equations[i].length == 4`
* `equations[i][0]` is a lowercase letter.
* `equations[i][1]` is either `'='` or `'!'`.
* `equations[i][2]` is `'='`.
* `equations[i][3]` is a lowercase letter.

## Hints/Notes

* Union find

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> parent;

    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; i++) {
            parent.push_back(i);
        }

        for (string equation : equations) {
            if (equation[1] == '=') {
                int left = equation[0] - 'a';
                int right = equation[3] - 'a';
                int rootLeft = find(left);
                int rootRight = find(right);
                if (rootLeft != rootRight) {
                    parent[rootLeft] = rootRight;
                }
            }
        }

        for (string equation : equations) {
            if (equation[1] == '!') {
                int left = equation[0] - 'a';
                int right = equation[3] - 'a';
                int rootLeft = find(left);
                int rootRight = find(right);
                if (rootLeft == rootRight) {
                    return false;
                }
            }
        }

        return true;
    }

    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
};
```
