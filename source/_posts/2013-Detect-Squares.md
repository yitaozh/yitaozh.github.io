---
title: 2013. Detect Squares
categories: Leetcode
date: 2024-12-27 02:35:49
tags:
    - Array
    - Hash Table
    - Design
    - Counting
---

[2013. Detect Squares](https://leetcode.com/problems/detect-squares/description/?envType=problem-list-v2&envId=plakya4j)

## Description

You are given a stream of points on the X-Y plane. Design an algorithm that:

- **Adds**  new points from the stream into a data structure. **Duplicate**  points are allowed and should be treated as different points.
- Given a query point, **counts**  the number of ways to choose three points from the data structure such that the three points and the query point form an **axis-aligned square**  with **positive area** .

An **axis-aligned square**  is a square whose edges are all the same length and are either parallel or perpendicular to the x-axis and y-axis.

Implement the `DetectSquares` class:

- `DetectSquares()` Initializes the object with an empty data structure.
- `void add(int[] point)` Adds a new point `point = [x, y]` to the data structure.
- `int count(int[] point)` Counts the number of ways to form **axis-aligned squares**  with point `point = [x, y]` as described above.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/09/01/image.png" style="width: 869px; height: 504px;">

```bash
Input

["DetectSquares", "add", "add", "add", "count", "count", "add", "count"]
[[], [[3, 10]], [[11, 2]], [[3, 2]], [[11, 10]], [[14, 8]], [[11, 2]], [[11, 10]]]
Output

[null, null, null, null, 1, 0, null, 2]

Explanation

DetectSquares detectSquares = new DetectSquares();
detectSquares.add([3, 10]);
detectSquares.add([11, 2]);
detectSquares.add([3, 2]);
detectSquares.count([11, 10]); // return 1. You can choose:
                               //   - The first, second, and third points
detectSquares.count([14, 8]);  // return 0. The query point cannot form a square with any points in the data structure.
detectSquares.add([11, 2]);    // Adding duplicate points is allowed.
detectSquares.count([11, 10]); // return 2. You can choose:
                               //   - The first, second, and third points
                               //   - The first, third, and fourth points
```

**Constraints:**

- `point.length == 2`
- `0 <= x, y <= 1000`
- At most `3000` calls **in total**  will be made to `add` and `count`.

## Hints/Notes

- 2024/12/26
- hashmap
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> cols, rows;
    unordered_map<int, int> m;

    DetectSquares() {
    }

    void add(vector<int> point) {
        int i = point[0], j = point[1];
        cols[i][j]++;
        rows[j][i]++;
        m[encode(i, j)]++;
    }

    int count(vector<int> point) {
        int i = point[0], j = point[1], res = 0;
        for (auto& [row, v1] : cols[i]) {
            if (row == j) {
                continue;
            }
            for (auto& [col, v2] : rows[j]) {
                if (col == i) {
                    continue;
                }
                if (abs(row - j) == abs(i - col)) {
                    res += m[encode(col, row)] * v1 * v2;
                }
            }
        }
        return res;
    }


    int encode(int x, int y) {
        return x * 1000 + y;
    }


};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
```
