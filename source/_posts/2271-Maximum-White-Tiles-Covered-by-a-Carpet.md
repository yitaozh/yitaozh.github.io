---
title: 2271. Maximum White Tiles Covered by a Carpet
categories: Leetcode
date: 2025-01-15 00:03:29
tags:
    - Array
    - Binary Search
    - Greedy
    - Sliding Window
    - Sorting
    - Prefix Sum
---

[2271. Maximum White Tiles Covered by a Carpet](https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/description/)

## Description

You are given a 2D integer array `tiles` where tiles[i] = [l<sub>i</sub>, r<sub>i</sub>] represents that every tile `j` in the range l<sub>i</sub> <= j <= r<sub>i</sub> is colored white.

You are also given an integer `carpetLen`, the length of a single carpet that can be placed **anywhere** .

Return the **maximum**  number of white tiles that can be covered by the carpet.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2022/03/25/example1drawio3.png" style="width: 644px; height: 158px;">

```bash
Input: tiles = [[1,5],[10,11],[12,18],[20,25],[30,32]], carpetLen = 10
Output: 9
Explanation: Place the carpet starting on tile 10.
It covers 9 white tiles, so we return 9.
Note that there may be other places where the carpet covers 9 white tiles.
It can be shown that the carpet cannot cover more than 9 white tiles.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2022/03/24/example2drawio.png" style="width: 231px; height: 168px;">

```bash
Input: tiles = [[10,11],[1,1]], carpetLen = 2
Output: 2
Explanation: Place the carpet starting on tile 10.
It covers 2 white tiles, so we return 2.
```

**Constraints:**

- `1 <= tiles.length <= 5 * 10^4`
- `tiles[i].length == 2`s
- 1 <= l<sub>i</sub> <= r<sub>i</sub> <= 10^9
- `1 <= carpetLen <= 10^9`
- The `tiles` are **non-overlapping** .

## Hints/Notes

- 2025/01/13
- sort
- [0x3F's solution](https://leetcode.cn/problems/maximum-white-tiles-covered-by-a-carpet/solutions/1496434/by-endlesscheng-kdy9/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        ranges::sort(tiles);
        int left = 0, cur = 0, n = tiles.size(), res = 0;
        for (int i = 0; i < n; i++) {
            int right = tiles[i][1] + 1;
            cur += tiles[i][1] - tiles[i][0] + 1;
            // at this step, we moved tiles out of the carpet, whose
            // right side is less than (right - carpetLen)
            while (tiles[left][1] < right - carpetLen) {
                cur -= tiles[left][1] - tiles[left][0] + 1;
                left++;
            }
            // now it's possible that the left is out of the carpet
            if (tiles[left][0] < right - carpetLen) {
                res = max(res, cur - (right - carpetLen - tiles[left][0]));
            } else {
                res = max(res, cur);
            }
        }
        return res;
    }
};
```
