---
title: 3154. Find Number of Ways to Reach the K-th Stair
categories: Leetcode
date: 2024-05-23 11:45:35
tags:
    - Math
    - Dynamic Programming
    - Bit Manipulation
    - Memoization
    - Combinatorics
---

[3154. Find Number of Ways to Reach the K-th Stair](https://leetcode.com/problems/find-number-of-ways-to-reach-the-k-th-stair/description/)

## Description

You are given a **non-negative**  integer `k`. There exists a staircase with an infinite number of stairs, with the **lowest**  stair numbered 0.

Alice has an integer `jump`, with an initial value of 0. She starts on stair 1 and wants to reach stair `k` using **any**  number of **operations** . If she is on stair `i`, in one **operation**  she can:

- Go down to stair `i - 1`. This operation **cannot**  be used consecutively or on stair 0.
- Go up to stair `i + 2^jump`. And then, `jump` becomes `jump + 1`.

Return the total number of ways Alice can reach stair `k`.

**Note**  that it is possible that Alice reaches the stair `k`, and performs some operations to reach the stair `k` again.

**Example 1:**

```bash
Input: k = 0

Output: 2

Explanation:

The 2 possible ways of reaching stair 0 are:

- Alice starts at stair 1.

- Using an operation of the first type, she goes down 1 stair to reach stair 0.

- Alice starts at stair 1.

- Using an operation of the first type, she goes down 1 stair to reach stair 0.
- Using an operation of the second type, she goes up 2^0 stairs to reach stair 1.
- Using an operation of the first type, she goes down 1 stair to reach stair 0.
```

**Example 2:**

```bash
Input: k = 1

Output: 4

Explanation:

The 4 possible ways of reaching stair 1 are:

- Alice starts at stair 1. Alice is at stair 1.
- Alice starts at stair 1.

- Using an operation of the first type, she goes down 1 stair to reach stair 0.
- Using an operation of the second type, she goes up 2^0 stairs to reach stair 1.

- Alice starts at stair 1.

- Using an operation of the second type, she goes up 2^0 stairs to reach stair 2.
- Using an operation of the first type, she goes down 1 stair to reach stair 1.

- Alice starts at stair 1.

- Using an operation of the first type, she goes down 1 stair to reach stair 0.
- Using an operation of the second type, she goes up 2^0 stairs to reach stair 1.
- Using an operation of the first type, she goes down 1 stair to reach stair 0.
- Using an operation of the second type, she goes up 2^1 stairs to reach stair 2.
- Using an operation of the first type, she goes down 1 stair to reach stair 1.
```

**Constraints:**

- `0 <= k <= 10^9`

## Hints/Notes

- Weekly contest 398
- dynamic programming

## Solution

Language: **C++**

```C++
class Solution {
public:
    int k_;
    vector<vector<map<int, int>>> dp;

    int waysToReachStair(int k) {
        k_ = k;
        dp = vector<vector<map<int, int>>>(2, vector<map<int, int>>(32, map<int, int>()));
        return traverse(1, 0, 0);
    }

    int traverse(int cur, int jump, int preDown) {
        if (jump < 0) {
            return 0;
        }
        if (cur > k_ + 1) {
            return 0;
        }
        if (dp[preDown][jump].contains(cur)) {
            return dp[preDown][jump][cur];
        }
        int res = cur == k_ ? 1 : 0;
        long next_jump = cur + pow(2, jump);
        res += traverse(cur + pow(2, jump), jump + 1, 0);
        if (!preDown) {
            res += traverse(cur - 1, jump, 1);
        }
        dp[preDown][jump][cur] = res;
        return res;
    }
};
```
