---
title: 3178. Find the Child Who Has the Ball After K Seconds
categories: Leetcode
date: 2024-06-14 14:04:17
tags:
    - Math
    - Simulation
---

[3178. Find the Child Who Has the Ball After K Seconds](https://leetcode.com/problems/find-the-child-who-has-the-ball-after-k-seconds/description/)

## Description

You are given two **positive**  integers `n` and `k`. There are `n` children numbered from `0` to `n - 1` standing in a queue in order from left to right.

Initially, child 0 holds a ball and the direction of passing the ball is towards the right direction. After each second, the child holding the ball passes it to the child next to them. Once the ball reaches **either**  end of the line, i.e. child 0 or child `n - 1`, the direction of passing is **reversed** .

Return the number of the child who receives the ball after `k` seconds.

**Example 1:**

```bash
Input: n = 3, k = 5

Output: 1
```

Explanation:

<table><tbody><tr><th>Time elapsed</th><th>Children</th></tr><tr><td>`0`</td><td>`[0, 1, 2]`</td></tr><tr><td>`1`</td><td>`[0, 1, 2]`</td></tr><tr><td>`2`</td><td>`[0, 1, 2]`</td></tr><tr><td>`3`</td><td>`[0, 1, 2]`</td></tr><tr><td>`4`</td><td>`[0, 1, 2]`</td></tr><tr><td>`5`</td><td>`[0, 1, 2]`</td></tr></tbody></table>

**Example 2:**

```bash
Input: n = 5, k = 6

Output: 2
```

Explanation:

<table><tbody><tr><th>Time elapsed</th><th>Children</th></tr><tr><td>`0`</td><td>`[0, 1, 2, 3, 4]`</td></tr><tr><td>`1`</td><td>`[0, 1, 2, 3, 4]`</td></tr><tr><td>`2`</td><td>`[0, 1, 2, 3, 4]`</td></tr><tr><td>`3`</td><td>`[0, 1, 2, 3, 4]`</td></tr><tr><td>`4`</td><td>`[0, 1, 2, 3, 4]`</td></tr><tr><td>`5`</td><td>`[0, 1, 2, 3, 4]`</td></tr><tr><td>`6`</td><td>`[0, 1, 2, 3, 4]`</td></tr></tbody></table>

**Example 3:**

```bash
Input: n = 4, k = 2

Output: 2
```

Explanation:

<table><tbody><tr><th>Time elapsed</th><th>Children</th></tr><tr><td>`0`</td><td>`[0, 1, 2, 3]`</td></tr><tr><td>`1`</td><td>`[0, 1, 2, 3]`</td></tr><tr><td>`2`</td><td>`[0, 1, 2, 3]`</td></tr></tbody></table>

**Constraints:**

- `2 <= n <= 50`
- `1 <= k <= 50`

## Hints/Notes

- Weekly Contest 401

## Solution

Language: **C++**

```C++
class Solution {
public:
    int numberOfChild(int n, int k) {
        k = k % (2 * n - 2);
        if (k < n) {
            return k;
        } else {
            return 2 * n - 2 - k;
        }
    }
};
```
