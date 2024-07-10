---
title: 3208. Alternating Groups II
categories: Leetcode
date: 2024-07-10 00:20:00
tags:
    - Array
    - Sliding Window
---

[3208. Alternating Groups II](https://leetcode.com/problems/alternating-groups-ii/description/)

## Description

There is a circle of red and blue tiles. You are given an array of integers `colors` and an integer `k`. The color of tile `i` is represented by `colors[i]`:

- `colors[i] == 0` means that tile `i` is **red** .
- `colors[i] == 1` means that tile `i` is **blue** .

An **alternating**  group is every `k` contiguous tiles in the circle with **alternating**  colors (each tile in the group except the first and last one has a different color from its **left**  and **right**  tiles).

Return the number of **alternating**  groups.

**Note**  that since `colors` represents a **circle** , the **first**  and the **last**  tiles are considered to be next to each other.

**Example 1:**

```bash
Input: colors = [0,1,0,1,0], k = 3

Output: 3
```

Explanation:

<img alt="" data-darkreader-inline-bgcolor="" data-darkreader-inline-bgimage="" src="https://assets.leetcode.com/uploads/2024/06/19/screenshot-2024-05-28-183519.png" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;">

Alternating groups:

<img alt="" data-darkreader-inline-bgcolor="" data-darkreader-inline-bgimage="" src="https://assets.leetcode.com/uploads/2024/05/28/screenshot-2024-05-28-182448.png" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;">

<img alt="" data-darkreader-inline-bgcolor="" data-darkreader-inline-bgimage="" src="https://assets.leetcode.com/uploads/2024/05/28/screenshot-2024-05-28-182844.png" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;">

<img alt="" data-darkreader-inline-bgcolor="" data-darkreader-inline-bgimage="" src="https://assets.leetcode.com/uploads/2024/05/28/screenshot-2024-05-28-183057.png" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;">

**Example 2:**

```bash
Input: colors = [0,1,0,0,1,0,1], k = 6

Output: 2
```

Explanation:

**<img alt="" data-darkreader-inline-bgcolor="" data-darkreader-inline-bgimage="" src="https://assets.leetcode.com/uploads/2024/06/19/screenshot-2024-05-28-183907.png" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;">**

Alternating groups:

<img alt="" data-darkreader-inline-bgcolor="" data-darkreader-inline-bgimage="" src="https://assets.leetcode.com/uploads/2024/06/19/screenshot-2024-05-28-184128.png" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;">

<img alt="" data-darkreader-inline-bgcolor="" data-darkreader-inline-bgimage="" src="https://assets.leetcode.com/uploads/2024/06/19/screenshot-2024-05-28-184240.png" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;">

**Example 3:**

```bash
Input: colors = [1,1,0,1], k = 4

Output: 0
```

Explanation:

<img alt="" data-darkreader-inline-bgcolor="" data-darkreader-inline-bgimage="" src="https://assets.leetcode.com/uploads/2024/06/19/screenshot-2024-05-28-184516.png" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;">

**Constraints:**

- `3 <= colors.length <= 10^5`
- `0 <= colors[i] <= 1`
- `3 <= k <= colors.length`

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int cur = colors[0], curLength = 1, res = 0;
        for (int i = 1; i < n + k; i++) {
            if (colors[i % n] != cur) {
                curLength++;
                cur = 1 - cur;
            } else {
                res += max(0, curLength - k + 1);
                cur = colors[i % n];
                curLength = 1;
            }
        }
        res += max(0, curLength - k);
        return res;
    }
};
```
