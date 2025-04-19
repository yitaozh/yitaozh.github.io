---
title: 849. Maximize Distance to Closest Person
categories: Leetcode
date: 2025-04-19 16:29:03
tags:
    - Array
---

[849. Maximize Distance to Closest Person](https://leetcode.com/problems/maximize-distance-to-closest-person/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

You are given an array representing a row of `seats` where `seats[i] = 1` represents a person sitting in the `i^th` seat, and `seats[i] = 0` represents that the `i^th` seat is empty **(0-indexed)** .

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.

Return that maximum distance to the closest person.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/09/10/distance.jpg" style="width: 650px; height: 257px;">

```bash
Input: seats = [1,0,0,0,1,0,1]
Output: 2
Explanation:
If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
```

**Example 2:**

```bash
Input: seats = [1,0,0,0]
Output: 3
Explanation:
If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
```

**Example 3:**

```bash
Input: seats = [0,1]
Output: 1
```

**Constraints:**

- `2 <= seats.length <= 2 * 10^4`
- `seats[i]`is `0` or`1`.
- At least one seat is **empty** .
- At least one seat is **occupied** .

## Hints/Notes

- 2025/04/17 Q3
- array
- [Leetcode solution](https://leetcode.com/problems/maximize-distance-to-closest-person/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int prev = -1, max_interval = INT_MIN, n = seats.size();
        for (int i = 0; i < n; i++) {
            if (seats[i]) {
                int mid, cur_interval;
                if (prev == -1) {
                    mid = 0;
                    cur_interval = i;
                } else {
                    mid = (prev + i) / 2;
                    cur_interval = min(mid - prev, i - mid);
                }
                max_interval = max(cur_interval, max_interval);
                prev = i;
            } else if (i == n - 1) {
                max_interval = max(max_interval, i - prev);
            }
        }
        return max_interval;
    }
};
```
