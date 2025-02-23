---
title: 3443. Maximum Manhattan Distance After K Changes
categories: Leetcode
date: 2025-02-23 14:13:20
tags:
    - Hash Table
    - Math
    - String
    - Counting
---

[3443. Maximum Manhattan Distance After K Changes](https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/description/)

## Description

You are given a string `s` consisting of the characters `'N'`, `'S'`, `'E'`, and `'W'`, where `s[i]` indicates movements in an infinite grid:

- `'N'` : Move north by 1 unit.
- `'S'` : Move south by 1 unit.
- `'E'` : Move east by 1 unit.
- `'W'` : Move west by 1 unit.

Initially, you are at the origin `(0, 0)`. You can change **at most**  `k` characters to any of the four directions.

Find the **maximum**  **Manhattan distance**  from the origin that can be achieved **at any time**  while performing the movements **in order** .
The **Manhattan Distance**  between two cells (x<sub>i</sub>, y<sub>i</sub>) and (x<sub>j</sub>, y<sub>j</sub>) is |x<sub>i</sub> - x<sub>j</sub>| + |y<sub>i</sub> - y<sub>j</sub>|.

**Example 1:**

```bash
Input: s = "NWSE", k = 1

Output: 3
```

Explanation:

Change `s[2]` from `'S'` to `'N'`. The string `s` becomes `"NWNE"`.

<table style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left=""><thead><tr><th style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">Movement</th><th style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">Position (x, y)</th><th style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">Manhattan Distance</th><th style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">Maximum</th></tr></thead><tbody><tr><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">s[0] == 'N'</td><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">(0, 1)</td><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">0 + 1 = 1</td><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">1</td></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">s[1] == 'W'</td><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">(-1, 1)</td><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">1 + 1 = 2</td><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">2</td></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">s[2] == 'N'</td><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">(-1, 2)</td><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">1 + 2 = 3</td><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">3</td></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">s[3] == 'E'</td><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">(0, 2)</td><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">0 + 2 = 2</td><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">3</td></tr></tbody></table>

The maximum Manhattan distance from the origin that can be achieved is 3. Hence, 3 is the output.

**Example 2:**

```bash
Input: s = "NSWWEW", k = 3

Output: 6
```

Explanation:

Change `s[1]` from `'S'` to `'N'`, and `s[4]` from `'E'` to `'W'`. The string `s` becomes `"NNWWWW"`.

The maximum Manhattan distance from the origin that can be achieved is 6. Hence, 6 is the output.

**Constraints:**

- `1 <= s.length <= 10^5`
- `0 <= k <= s.length`
- `s` consists of only `'N'`, `'S'`, `'E'`, and `'W'`.

## Hints/Notes

- 2025/02/20
- greedy
- [0x3F's solution](https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/)
- weekly contest 435

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxDistance(string s, int original_k) {
        int north = 0, south = 0, east = 0, west = 0, res = 0;
        // make 'N' and 'W' +1, and 'S' and 'E' -1, check max abs cur
        for (char& c : s) {
            int k = original_k;
            if (c == 'N') {
                north++;
            } else if (c == 'S') {
                south++;
            } else if (c == 'W') {
                west++;
            } else if (c == 'E') {
                east++;
            }
            int mx1 = max(north, south), mi1 = min(north, south);
            int mx2 = max(west, east), mi2 = min(west, east);
            if (k <= mi1) {
                mx1 += k;
                mi1 -= k;
                res = max(res, mx1 - mi1 + mx2 - mi2);
            } else {
                k -= mi1;
                mx1 += mi1;
                k = min(k, mi2);
                mx2 += k;
                mi2 -= k;
                res = max(res, mx1 + mx2 - mi2);
            }
            // cout << mx1 << " " << mi1 << " " << mx2 << " " << mi2 << " " << res << endl;
        }
        return res;
    }
};
```
