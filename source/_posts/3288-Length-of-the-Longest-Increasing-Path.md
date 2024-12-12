---
title: 3288. Length of the Longest Increasing Path
categories: Leetcode
date: 2024-10-10 00:14:17
tags:
    - Array
    - Binary Search
    - Sorting
---

[3288. Length of the Longest Increasing Path](https://leetcode.com/problems/length-of-the-longest-increasing-path/description/)

## Description

You are given a 2D array of integers `coordinates` of length `n` and an integer `k`, where `0 <= k < n`.

coordinates[i] = [x<sub>i</sub>, y<sub>i</sub>] indicates the point (x<sub>i</sub>, y<sub>i</sub>) in a 2D plane.

An **increasing path**  of length `m` is defined as a list of points (x<sub>1</sub>, y<sub>1</sub>), (x<sub>2</sub>, y<sub>2</sub>), (x<sub>3</sub>, y<sub>3</sub>), ..., (x<sub>m</sub>, y<sub>m</sub>) such that:

- x<sub>i</sub> < x<sub>i + 1</sub> and y<sub>i</sub> < y<sub>i + 1</sub> for all `i` where `1 <= i < m`.
- (x<sub>i</sub>, y<sub>i</sub>) is in the given coordinates for all `i` where `1 <= i <= m`.

Return the **maximum**  length of an **increasing path**  that contains `coordinates[k]`.

**Example 1:**

```bash
Input: coordinates = [[3,1],[2,2],[4,1],[0,0],[5,3]], k = 1

Output: 3
```

Explanation:

`(0, 0)`, `(2, 2)`, `(5, 3)` is the longest increasing path that contains `(2, 2)`.

**Example 2:**

```bash
Input: coordinates = [[2,1],[7,0],[5,6]], k = 2

Output: 2
```

Explanation:

`(2, 1)`, `(5, 6)` is the longest increasing path that contains `(5, 6)`.

**Constraints:**

- `1 <= n == coordinates.length <= 10^5`
- `coordinates[i].length == 2`
- `0 <= coordinates[i][0], coordinates[i][1] <= 10^9`
- All elements in `coordinates` are **distinct** .
- `0 <= k <= n - 1`

## Hints/Notes

- 2024/09/08
- LIS
- [0x3F's solution](https://leetcode.cn/problems/length-of-the-longest-increasing-path/solutions/2917590/pai-xu-lispythonjavacgo-by-endlesscheng-803g/)(checked)
- Biweekly Contest 139

## Solution

Language: **C++**

Cleaner solution:

```C++
class Solution {
public:
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        int n = coordinates.size();
        auto cmp = [](vector<int>& lhs, vector<int>& rhs) {
            if (lhs[0] != rhs[0]) {
                return lhs[0] < rhs[0];
            }
            return lhs[1] > rhs[1];
        };
        vector<int> y_coordinates;
        int kx = coordinates[k][0], ky = coordinates[k][1];
        sort(coordinates.begin(), coordinates.end(), cmp);
        for (int i = 0; i < n; i++) {
            int x = coordinates[i][0], y = coordinates[i][1];
            if ((x < kx && y < ky) || (x > kx && y > ky)) {
                auto it = ranges::lower_bound(y_coordinates, y);
                if (it == y_coordinates.end()) {
                    y_coordinates.push_back(y);
                } else {
                    *it = y;
                }
            }
        }
        return y_coordinates.size() + 1;
    }
};
```

```C++
class Solution {
public:
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        int n = coordinates.size();
        vector<int> nums;
        int xIndex = -1, yIndex = -1;
        for (int i = 0; i < n; i++) {
            coordinates[i] = {coordinates[i][0], coordinates[i][1], i};
        }
        auto cmp = [](vector<int>& lhs, vector<int>& rhs) {
            if (lhs[0] != rhs[0]) {
                return lhs[0] < rhs[0];
            }
            return lhs[1] > rhs[1];
        };
        sort(coordinates.begin(), coordinates.end(), cmp);
        for (int i = 0; i < n; i++) {
            int x = coordinates[i][1], idx = coordinates[i][2];
            int index = binarySearch(nums, x);
            if (index == nums.size()) {
                nums.push_back(x);
            } else {
                nums[index] = x;
            }
            if (idx == k) {
                xIndex = index;
                break;
            }
        }
        nums.clear();
        for (int i = n - 1; i >= 0; i--) {
            int x = -coordinates[i][1], idx = coordinates[i][2];
            int index = binarySearch(nums, x);
            if (index == nums.size()) {
                nums.push_back(x);
            } else {
                nums[index] = x;
            }
            if (idx == k) {
                yIndex = index;
                break;
            }
        }
        return xIndex + yIndex + 1;
    }

    int binarySearch(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = (r - l) / 2 + l;
            if (nums[mid] > target) {
                r = mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] == target) {
                return mid;
            }
        }
        return l;
    }
};
```
