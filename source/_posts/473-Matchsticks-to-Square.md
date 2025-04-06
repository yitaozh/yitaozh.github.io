---
title: 473. Matchsticks to Square
categories: Leetcode
date: 2025-04-06 12:59:54
tags:
    - Array
    - Dynamic Programming
    - Backtracking
    - Bit Manipulation
    - Bitmask
---

[473. Matchsticks to Square](https://leetcode.com/problems/matchsticks-to-square/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-six-months)

## Description

You are given an integer array `matchsticks` where `matchsticks[i]` is the length of the `i^th` matchstick. You want to use **all the matchsticks**  to make one square. You **should not break**  any stick, but you can link them up, and each matchstick must be used **exactly one time** .

Return `true` if you can make this square and `false` otherwise.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/04/09/matchsticks1-grid.jpg" style="width: 253px; height: 253px;">

```bash
Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
```

**Example 2:**

```bash
Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.
```

**Constraints:**

- `1 <= matchsticks.length <= 15`
- `1 <= matchsticks[i] <= 10^8`

## Hints/Notes

- 2025/04/05 Q3
- backtracking
- [Leetcode solution](https://leetcode.com/problems/matchsticks-to-square/editorial)

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = reduce(matchsticks.begin(), matchsticks.end());
        if (sum % 4) {
            return false;
        }
        int side = sum / 4;
        if (ranges::max(matchsticks) > side) {
            return false;
        }
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> sticks(4, 0);
        return dfs(0, matchsticks, sticks, side);
    }

    bool dfs(int idx, vector<int>& matchsticks, vector<int>& sticks, const int side) {
        if (idx == matchsticks.size()) {
            return true;
        }
        bool res = false;
        for (int i = 0; i < sticks.size(); i++) {
            if (sticks[i] + matchsticks[idx] > side) {
                continue;
            }
            sticks[i] += matchsticks[idx];
            res |= dfs(idx + 1, matchsticks, sticks, side);
            sticks[i] -= matchsticks[idx];
            if (res) {
                return true;
            }
        }
        return false;
    }
};
```
