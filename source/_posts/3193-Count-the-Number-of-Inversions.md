---
title: 3193. Count the Number of Inversions
categories: Leetcode
date: 2024-06-27 23:31:38
tags:
    - Array
    - Dynamic Programming
---

[3193. Count the Number of Inversions](https://leetcode.com/problems/count-the-number-of-inversions/description/)

## Description

You are given an integer `n` and a 2D array `requirements`, where requirements[i] = [end<sub>i</sub>, cnt<sub>i</sub>] represents the end index and the **inversion** count of each requirement.

A pair of indices `(i, j)` from an integer array `nums` is called an **inversion** if:

- `i < j` and `nums[i] > nums[j]`

Return the number of permutations `perm` of `[0, 1, 2, ..., n - 1]` such that for **all** requirements[i], perm[0..end<sub>i</sub>] has exactly cnt<sub>i</sub> inversions.

Since the answer may be very large, return it **modulo** `10^9 + 7`.

**Example 1:**

```bash
Input: n = 3, requirements = [[2,2],[0,0]]

Output: 2
```

Explanation:

The two permutations are:

- `[2, 0, 1]`

  - Prefix `[2, 0, 1]` has inversions `(0, 1)` and `(0, 2)`.
  - Prefix `[2]` has 0 inversions.

- `[1, 2, 0]`

  - Prefix `[1, 2, 0]` has inversions `(0, 2)` and `(1, 2)`.
  - Prefix `[1]` has 0 inversions.

**Example 2:**

```bash
Input: n = 3, requirements = [[2,2],[1,1],[0,0]]

Output: 1
```

Explanation:

The only satisfying permutation is `[2, 0, 1]`:

- Prefix `[2, 0, 1]` has inversions `(0, 1)` and `(0, 2)`.
- Prefix `[2, 0]` has an inversion `(0, 1)`.
- Prefix `[2]` has 0 inversions.

**Example 3:**

```bash
Input: n = 2, requirements = [[0,0],[1,0]]

Output: 1
```

Explanation:

The only satisfying permutation is `[0, 1]`:

- Prefix `[0]` has 0 inversions.
- Prefix `[0, 1]` has an inversion `(0, 1)`.

**Constraints:**

- `2 <= n <= 300`
- `1 <= requirements.length <= n`
- `requirements[i] = [end<sub>i</sub>, cnt<sub>i</sub>]`
- `0 <= end<sub>i</sub> <= n - 1`
- `0 <= cnt<sub>i</sub> <= 400`
- The input is generated such that there is at least one `i` such that `end<sub>i</sub> == n - 1`.
- The input is generated such that all `end<sub>i</sub>` are unique.

## Hints/Notes

- dynamic programming
- Biweekly Contest 133

## Solution

Language: **C++**

```C++
class Solution {
public:
    unordered_map<int, int> m;
    vector<unordered_map<int, int>> dp;
    int mod = 1e9 + 7;

    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        for (auto r : requirements) {
            m[r[0]] = r[1];
        }
        dp.resize(n);
        int res = traverse(n - 1, m[n - 1]);
        return res;
    }

    int traverse(int curIndex, int numInv) {
        if (curIndex == 0) {
            return numInv == 0;
        }

        if (dp[curIndex].contains(numInv)) {
            return dp[curIndex][numInv];
        }

        int ans = 0;
        if (m.contains(curIndex - 1)) {
            int r = m[curIndex - 1];
            ans = (numInv >= r && curIndex + r >= numInv)
                      ? traverse(curIndex - 1, m[curIndex - 1])
                      : 0;
        } else {
            for (int i = 0; i <= min(numInv, curIndex); i++) {
                ans = (ans + traverse(curIndex - 1, numInv - i) % mod) % mod;
            }
        }
        dp[curIndex][numInv] = ans;
        return ans;
    }
};
```
