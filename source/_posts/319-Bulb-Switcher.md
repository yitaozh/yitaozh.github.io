---
title: 319. Bulb Switcher
categories: Leetcode
date: 2025-03-17 01:50:58
tags:
    - Math
    - Brainteaser
---

[319. Bulb Switcher](https://leetcode.com/problems/bulb-switcher/description/?envType=company&envId=linkedin&favoriteSlug=linkedin-three-months)

## Description

There are `n` bulbs that are initially off. You first turn on all the bulbs, thenyou turn off every second bulb.

On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the `i^th` round, you toggle every `i` bulb. For the `n^th` round, you only toggle the last bulb.

Return the number of bulbs that are on after `n` rounds.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/11/05/bulb.jpg" style="width: 421px; height: 321px;">

```bash
Input: n = 3
Output: 1
Explanation: At first, the three bulbs are [off, off, off].
After the first round, the three bulbs are [on, on, on].
After the second round, the three bulbs are [on, off, on].
After the third round, the three bulbs are [on, off, off].
So you should return 1 because there is only one bulb is on.
```

**Example 2:**

```bash
Input: n = 0
Output: 0
```

**Example 3:**

```bash
Input: n = 1
Output: 1
```

**Constraints:**

- `0 <= n <= 10^9`

## Hints/Notes

- 2025/02/13 Q3
- math
- [Leetcode solution](https://leetcode.com/problems/bulb-switcher/editorial/?envType=company&envId=linkedin&favoriteSlug=linkedin-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int bulbSwitch(int n) {
        int res = 0;
        for (int j = 1; j * j <= n; j++) {
            res++;
        }
        return res;
    }
};
```
