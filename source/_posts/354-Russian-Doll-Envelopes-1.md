---
title: 354. Russian Doll Envelopes
categories: Leetcode
date: 2025-05-03 01:18:51
tags:
    - Array
    - Binary Search
    - Dynamic Programming
    - Sorting
---

[354. Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes/description/?envType=company&envId=google&favoriteSlug=google-three-months)

## Description

You are given a 2D array of integers <code>envelopes</code> where <code>envelopes[i] = [w<sub>i</sub>, h<sub>i</sub>]</code> represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

**Note:**  You cannot rotate an envelope.

**Example 1:**

```bash
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is <code>3</code> ([2,3] => [5,4] => [6,7]).
```

**Example 2:**

```bash
Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
```

**Constraints:**

- <code>1 <= envelopes.length <= 10^5</code>
- <code>envelopes[i].length == 2</code>
- <code>1 <= w<sub>i</sub>, h<sub>i</sub> <= 10^5</code>

## Hints/Notes

- 2025/04/27 Q2
- LIS
- [Leetcode solution](https://leetcode.com/problems/russian-doll-envelopes/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        auto cmp = [](vector<int> lhs, vector<int> rhs) {
            if (lhs[0] == rhs[0]) {
                return lhs[1] > rhs[1];
            }
            return lhs[0] < rhs[0];
        };
        sort(envelopes.begin(), envelopes.end(), cmp);
        int size = envelopes.size();
        vector<int> dolls;
        for (int i = 0; i < size; i++) {
            auto it = lower_bound(dolls.begin(), dolls.end(), envelopes[i][1]);
            if (it == dolls.end()) {
                dolls.push_back(envelopes[i][1]);
            } else {
                *it = envelopes[i][1];
            }
        }
        return dolls.size();
    }
};
```
