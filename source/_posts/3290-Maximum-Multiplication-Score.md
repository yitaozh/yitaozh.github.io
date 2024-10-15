---
title: 3290. Maximum Multiplication Score
categories: Leetcode
date: 2024-10-15 16:25:40
tags:
    - Array
    - Dynamic Programming
---

[3290. Maximum Multiplication Score](https://leetcode.com/problems/maximum-multiplication-score/description/)

## Description

You are given an integer array `a` of size 4 and another integer array `b` of size **at least**  4.

You need to choose 4 indices i<sub>0</sub>, i<sub>1</sub>, i<sub>2</sub>, and i<sub>3</sub> from the array `b` such that i<sub>0</sub> < i<sub>1</sub> < i<sub>2</sub> < i<sub>3</sub>. Your score will be equal to the value a[0] \* b[i<sub>0</sub>] + a[1] \* b[i<sub>1</sub>] + a[2] \* b[i<sub>2</sub>] + a[3] \* b[i<sub>3</sub>].

Return the **maximum**  score you can achieve.

**Example 1:**

```bash
Input: a = [3,2,5,6], b = [2,-6,4,-5,-3,2,-7]

Output: 26
```

Explanation:

We can choose the indices 0, 1, 2, and 5. The score will be `3 * 2 + 2 * (-6) + 5 * 4 + 6 * 2 = 26`.

**Example 2:**

```bash
Input: a = [-1,4,5,-2], b = [-5,-1,-3,-2,-4]

Output: -1
```

Explanation:

We can choose the indices 0, 1, 3, and 4. The score will be `(-1) * (-5) + 4 * (-1) + 5 * (-2) + (-2) * (-4) = -1`.

**Constraints:**

- `a.length == 4`
- `4 <= b.length <= 10^5`
- `-10^5 <= a[i], b[i] <= 10^5`

## Hints/Notes

- dp
- Weekly Contest 415

## Solution

Language: **C++**

```C++
class Solution {
public:
    int m_, n_;

    // the meaning of dp[i][j]: when we are at ith item in a, and jth item in b
    // the maximum number we can achieve
    // the state transition:
    //  at jth item of a, we can either match or not
    vector<vector<long long>> dp;
    long long maxScore(vector<int>& a, vector<int>& b) {
        m_ = a.size(), n_ = b.size();
        dp.resize(m_, vector<long long>(n_, LONG_MIN));
        dp[0][0] = (long long)a[0] * b[0];
        for (int i = 0; i < m_; i++) {
            for (int j = i; j < n_ + i + 1 - m_; j++) {
                if (i) {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1] + (long long)a[i] * b[j]);
                } else if (j) {
                    dp[i][j] = max(dp[i][j - 1], (long long)a[i] * b[j]);
                }
            }
        }
        return dp[m_ - 1][n_ - 1];
    }
};
```
