---
title: 54. Spiral Matrix
categories: Leetcode
date: 2023-01-23 12:19:49
tags:
    - Array
    - Matrix
    - Simulation
---

[54\. Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/array/), [Matrix](https://leetcode.com/tag/matrix/), [Simulation](https://leetcode.com/tag/simulation/)

Given an `m x n` `matrix`, return _all elements of the_ `matrix` _in spiral order_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg)

```bash
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg)

```bash
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
```

**Constraints:**

* `m == matrix.length`
* `n == matrix[i].length`
* `1 <= m, n <= 10`
* `-100 <= matrix[i][j] <= 100`

## Hints/Notes

* 2023/08/09
* Traverse all four sides in one iteration
* [0x3F's solution](https://leetcode.cn/problems/spiral-matrix/solutions/2966229/liang-chong-fang-fa-jian-ji-gao-xiao-pyt-4wzk/)(checked)

## Solution

cleaner solution

```C++
class Solution {
public:
    static constexpr int DIRs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res(m * n);
        int i = 0, j = 0, d = 0;
        for (int k = 0; k < m * n; k++) {
            res[k] = matrix[i][j];
            matrix[i][j] = INT_MAX;
            int x = i + DIRs[d][0], y = j + DIRs[d][1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] == INT_MAX) {
                d = (d + 1) % 4;
                x = i + DIRs[d][0];
                y = j + DIRs[d][1];
            }
            i = x; j = y;
        }
        return res;
    }
};
```

Language: **C++**

```C++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return res;
        }
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n - 1, up = 0, down = m - 1, x = 0, y = 0;
        while (res.size() < m * n) {
            if (up <= down) {
                for (int i = left; i <= right; i++) {
                    res.push_back(matrix[up][i]);
                }
                up++;
            }

            if (left <= right) {
                for (int i = up; i <= down; i++) {
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
            
            if (up <= down) {
                for (int i = right; i >= left; i--) {
                    res.push_back(matrix[down][i]);
                }
                down--;
            }
            
            if (left <= right) {
                for (int i = down; i >= up; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};
```
