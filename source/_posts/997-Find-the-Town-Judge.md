---
title: 997. Find the Town Judge
categories: Leetcode
date: 2023-01-23 13:10:16
tags:
    - Array
    - Hash Table
    - Graph
---

# [1039\. Find the Town Judge](https://leetcode.com/problems/find-the-town-judge/)

## Description

Difficulty: **Easy**

Related Topics: [Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Graph](https://leetcode.com/tag/graph/)

In a town, there are `n` people labeled from `1` to `n`. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

1. The town judge trusts nobody.
2. Everybody (except for the town judge) trusts the town judge.
3. There is exactly one person that satisfies properties **1** and **2**.

You are given an array `trust` where trust[i] = [a<sub>i</sub>, b<sub>i</sub>] representing that the person labeled a<sub>i</sub> trusts the person labeled b<sub>i</sub>.

Return _the label of the town judge if the town judge exists and can be identified, or return_ `-1` _otherwise_.

**Example 1:**

```text
Input: n = 2, trust = [[1,2]]
Output: 2
```

**Example 2:**

```text
Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
```

**Example 3:**

```text
Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
```

**Constraints:**

* `1 <= n <= 1000`
* 0 <= trust.length <= 10<sup>4</sup>
* `trust[i].length == 2`
* All the pairs of `trust` are **unique**.
* a<sub>i</sub> != b<sub>i</sub>
* 1 <= a<sub>i</sub>, b<sub>i</sub> <= n

## Solution

Language: **C++**

```C++
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trusts) {
        int res = -1;
        if (trusts.size() < n - 1) {
            return res;
        }
        vector<int> in_trust(n + 1, 0);
        vector<int> out_trust(n + 1, -1);
        for (vector<int> t : trusts) {
            in_trust[t[1]]++;
            out_trust[t[0]] = t[1];
        }
        for (int i = 1; i <= n; i++) {
            if (in_trust[i] == n - 1 && out_trust[i] == -1) {
                return i;
            }
        }
        return -1;
    }
};
```
