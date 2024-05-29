---
title: 3160. Find the Number of Distinct Colors Among the Balls
categories: Leetcode
date: 2024-05-28 23:39:46
tags:
    - Array
    - Hash Table
    - Simulation
---

[3160. Find the Number of Distinct Colors Among the Balls](https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/)

You are given an integer `limit` and a 2D array `queries` of size `n x 2`.

There are `limit + 1` balls with **distinct**  labels in the range `[0, limit]`. Initially, all balls are uncolored. For every query in `queries` that is of the form `[x, y]`, you mark ball `x` with the color `y`. After each query, you need to find the number of **distinct**  colors among the balls.

Return an array `result` of length `n`, where `result[i]` denotes the number of distinct colors after `i^th` query.

**Note**  that when answering a query, lack of a color will not be considered as a color.

**Example 1:**

```bash
Input: limit = 4, queries = [[1,4],[2,5],[1,3],[3,4]]

Output: [1,2,2,3]
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/04/17/ezgifcom-crop.gif" style="width: 455px; height: 145px;">

- After query 0, ball 1 has color 4.
- After query 1, ball 1 has color 4, and ball 2 has color 5.
- After query 2, ball 1 has color 3, and ball 2 has color 5.
- After query 3, ball 1 has color 3, ball 2 has color 5, and ball 3 has color 4.

**Example 2:**

```bash
Input: limit = 4, queries = [[0,1],[1,2],[2,2],[3,4],[4,5]]

Output: [1,2,2,3,4]
```

Explanation:

**<img alt="" src="https://assets.leetcode.com/uploads/2024/04/17/ezgifcom-crop2.gif" style="width: 457px; height: 144px;">**

- After query 0, ball 0 has color 1.
- After query 1, ball 0 has color 1, and ball 1 has color 2.
- After query 2, ball 0 has color 1, and balls 1 and 2 have color 2.
- After query 3, ball 0 has color 1, balls 1 and 2 have color 2, and ball 3 has color 4.
- After query 4, ball 0 has color 1, balls 1 and 2 have color 2, ball 3 has color 4, and ball 4 has color 5.

**Constraints:**

- `1 <= limit <= 10^9`
- `1 <= n == queries.length <= 10^5`
- `queries[i].length == 2`
- `0 <= queries[i][0] <= limit`
- `1 <= queries[i][1] <= 10^9`

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int, int> m;
        map<int, int> colorToOccurances;
        vector<int> res;
        for (auto query : queries) {
            int x = query[0];
            int y = query[1];
            if (!m.contains(x)) {
                m[x] = y;
                colorToOccurances[y]++;
            } else {
                int previousColor = m[x];
                colorToOccurances[previousColor]--;
                if (colorToOccurances[previousColor] == 0) {
                    colorToOccurances.erase(previousColor);
                }
                m[x] = y;
                colorToOccurances[y]++;
            }
            res.push_back(colorToOccurances.size());
        }
        return res;
    }
};
```
