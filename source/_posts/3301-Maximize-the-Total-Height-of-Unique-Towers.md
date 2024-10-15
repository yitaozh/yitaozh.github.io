---
title: 3301. Maximize the Total Height of Unique Towers
categories: Leetcode
date: 2024-10-15 16:42:05
tags:
    - Array
    - Greedy
    - Sorting
---

[3301. Maximize the Total Height of Unique Towers](https://leetcode.com/problems/maximize-the-total-height-of-unique-towers/description/)

## Description

You are given an array `maximumHeight`, where `maximumHeight[i]` denotes the **maximum**  height the `i^th` tower can be assigned.

Your task is to assign a height to each tower so that:

- The height of the `i^th` tower is a positive integer and does not exceed `maximumHeight[i]`.
- No two towers have the same height.

Return the **maximum**  possible total sum of the tower heights. If it's not possible to assign heights, return `-1`.

**Example 1:**

```bash
Input: maximumHeight = [2,3,4,3]

Output: 10
```

Explanation:

We can assign heights in the following way: `[1, 2, 4, 3]`.

**Example 2:**

```bash
Input: maximumHeight = [15,10]

Output: 25
```

Explanation:

We can assign heights in the following way: `[15, 10]`.

**Example 3:**

```bash
Input: maximumHeight = [2,2,1]

Output: -1
```

Explanation:

It's impossible to assign positive heights to each index so that no two towers have the same height.

**Constraints:**

- `1 <= maximumHeight.length<= 10^5`
- `1 <= maximumHeight[i] <= 10^9`

## Hints/Notes

- sorting or priority_queue
- Biweekly Contest 140

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        priority_queue<int> pq;
        for (int h : maximumHeight) {
            pq.push(h);
        }
        long long res = 0, curH = INT_MAX;
        while (!pq.empty()) {
            int tmp = pq.top();
            pq.pop();
            if (tmp <= curH) {
                curH = tmp;
            }
            res += curH;
            curH--;
            if (curH < pq.size()) {
                return -1;
            }
        }
        return res;
    }
};
```
