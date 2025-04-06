---
title: 1010. Pairs of Songs With Total Durations Divisible by 60
categories: Leetcode
date: 2025-04-05 22:22:40
tags:
    - Array
    - Hash Table
    - Counting
---

[1010. Pairs of Songs With Total Durations Divisible by 60](https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-six-months)

## Description

You are given a list of songs where the `i^th` song has a duration of `time[i]` seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by `60`. Formally, we want the number of indices `i`, `j` such that `i < j` with `(time[i] + time[j]) % 60 == 0`.

**Example 1:**

```bash
Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60
```

**Example 2:**

```bash
Input: time = [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.
```

**Constraints:**

- `1 <= time.length <= 6 * 10^4`
- `1 <= time[i] <= 500`

## Hints/Notes

- 2025/04/04 Q1
- preSum
- [Leetcode solution](https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/editorial)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> m;
        int res = 0;
        for (int& t : time) {
            int target = (60 - t % 60) % 60;
            res += m[target];
            m[t % 60]++;
        }
        return res;
    }
};
```
