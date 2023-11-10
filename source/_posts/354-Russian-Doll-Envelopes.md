---
title: 354. Russian Doll Envelopes
categories: Leetcode
date: 2023-11-09 23:40:54
tags:
    - Array
    - Binary Search
    - Dynamic Programming
    - Sorting
---

# [354\. Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes/)

## Description

Difficulty: **Hard**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Binary Search](https://leetcode.com/tag/https://leetcode.com/tag/binary-search//), [Dynamic Programming](https://leetcode.com/tag/https://leetcode.com/tag/dynamic-programming//), [Sorting](https://leetcode.com/tag/https://leetcode.com/tag/sorting//)

You are given a 2D array of integers `envelopes` where envelopes[i] = [w<sub>i</sub>, h<sub>i</sub>] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return _the maximum number of envelopes you can Russian doll (i.e., put one inside the other)_.

**Note:** You cannot rotate an envelope.

**Example 1:**

```bash
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
```

**Example 2:**

```bash
Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
```

**Constraints:**

* 1 <= envelopes.length <= 10<sup>5</sup>
* `envelopes[i].length == 2`
* 1 <= w<sub>i</sub>, h<sub>i</sub> <= 10<sup>5</sup>

## Hints/Notes

* dp

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        auto cmp = [](vector<int> lhs, vector<int> rhs) {
            if (lhs[0] != rhs[0]) {
                return lhs[0] < rhs[0];
            }
            return lhs[1] > rhs[1];
        };
        sort(envelopes.begin(), envelopes.end(), cmp);
        int res = 0;
        vector<int> dp(envelopes.size(), 1);
        for (int i = 0; i < envelopes.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
```
