---
title: 3206. Alternating Groups I
categories: Leetcode
date: 2024-07-10 00:15:57
tags:
    - Array
    - Sliding Window
---

[3206. Alternating Groups I](https://leetcode.com/problems/alternating-groups-i/description/)

## Description

There is a circle of red and blue tiles. You are given an array of integers `colors`. The color of tile `i` is represented by `colors[i]`:

- `colors[i] == 0` means that tile `i` is **red**.
- `colors[i] == 1` means that tile `i` is **blue**.

Every 3 contiguous tiles in the circle with **alternating** colors (the middle tile has a different color from its **left** and **right** tiles) is called an **alternating** group.

Return the number of **alternating** groups.

**Note** that since `colors` represents a **circle**, the **first** and the **last** tiles are considered to be next to each other.

**Example 1:**

```bash
Input: colors = [1,1,1]

Output: 0
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/05/16/image_2024-05-16_23-53-171.png" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="">

**Example 2:**

```bash
Input: colors = [0,1,0,0,1]

Output: 3
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/05/16/image_2024-05-16_23-47-491.png" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="">

Alternating groups:

<img alt="" src="https://assets.leetcode.com/uploads/2024/05/16/image_2024-05-16_23-50-441.png" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="">

<img alt="" src="https://assets.leetcode.com/uploads/2024/05/16/image_2024-05-16_23-48-211.png" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="">

<img alt="" src="https://assets.leetcode.com/uploads/2024/05/16/image_2024-05-16_23-49-351.png" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="">

**Constraints:**

- `3 <= colors.length <= 100`
- `0 <= colors[i] <= 1`

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size(), res = 0;
        for (int i = 0; i < n; i++) {
            if (colors[(i - 1 + n) % n] != colors[i] &&
                colors[i] != colors[(i + 1) % n]) {
                res++;
            }
        }
        return res;
    }
};
```
