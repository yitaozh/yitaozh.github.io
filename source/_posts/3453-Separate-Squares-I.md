---
title: 3453. Separate Squares I
categories: Leetcode
date: 2025-03-10 02:09:04
tags:
    - Array
    - Binary Search
---

[3453. Separate Squares I](https://leetcode.com/problems/separate-squares-i/description/)

## Description

You are given a 2D integer array `squares`. Each squares[i] = [x<sub>i</sub>, y<sub>i</sub>, l<sub>i</sub>] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.

Find the **minimum** y-coordinate value of a horizontal line such that the total area of the squares above the line equals the total area of the squares below the line.

Answers within `10^-5` of the actual answer will be accepted.

**Note** : Squares **may**  overlap. Overlapping areas should be counted **multiple times** .

**Example 1:**

```bash
Input: squares = [[0,0,1],[2,2,1]]

Output: 1.00000
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2025/01/06/4062example1drawio.png" style="width: 378px; height: 352px;">

Any horizontal line between `y = 1` and `y = 2` will have 1 square unit above it and 1 square unit below it. The lowest option is 1.

**Example 2:**

```bash
Input: squares = [[0,0,2],[1,1,1]]

Output: 1.16667
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2025/01/15/4062example2drawio.png" style="width: 378px; height: 352px;">

The areas are:

- Below the line: `7/6 * 2 (Red) + 1/6 (Blue) = 15/6 = 2.5`.
- Above the line: `5/6 * 2 (Red) + 5/6 (Blue) = 15/6 = 2.5`.

Since the areas above and below the line are equal, the output is `7/6 = 1.16667`.

**Constraints:**

- `1 <= squares.length <= 5 * 10^4`
- squares[i] = [x<sub>i</sub>, y<sub>i</sub>, l<sub>i</sub>]
- `squares[i].length == 3`
- 0 <= x<sub>i</sub>, y<sub>i</sub> <= 10^9
- 1 <= l<sub>i</sub> <= 10^9
- The total area of all the squares will not exceed `10^12`.

## Hints/Notes

- 2025/02/25
- diff array
- [0x3F's solution](https://leetcode.cn/problems/separate-squares-i/solutions/3076424/zheng-shu-er-fen-pythonjavacgo-by-endles-8yn5/)
- Biweekly Contest 150

## Solution

Language: **C++**

```C++
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        map<int, int> m;
        double total_area = 0;
        for (auto& square : squares) {
            int x = square[0], y = square[1], l = square[2];
            m[y] += l;
            m[y + l] -= l;
            total_area += 1.0 * l * l;
        }
        // so now we have an sorted array
        // 0: 1, 1: -1,
        double cur_area = 0;
        int prev_pos = m.begin()->first, cur_pos = 0, cur_len = 0;
        for (auto& [k, v] : m) {
            int pos_diff = k - prev_pos;
            double new_area = cur_area + 1.0 * pos_diff * cur_len;
            if (new_area * 2 == total_area) {
                return k;
            } else if (new_area * 2 > total_area) {
                double area_diff = total_area / 2 - cur_area;
                return area_diff / cur_len + prev_pos;
            } else {
                prev_pos = k;
                cur_len += v;
                cur_area = new_area;
            }
        }
        return 0
    }
};
```
