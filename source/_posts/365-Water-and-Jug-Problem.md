---
title: 365. Water and Jug Problem
categories: Leetcode
date: 2025-03-23 02:31:26
tags:
    - Math
    - Depth-First Search
    - Breadth-First Search
---

[365. Water and Jug Problem](https://leetcode.com/problems/water-and-jug-problem/description/)

## Description

You are given two jugs with capacities `x` liters and `y` liters. You have an infinite water supply. Return whether the total amount of water in both jugs may reach `target` using the following operations:

- Fill either jug completely with water.
- Completely empty either jug.
- Pour water from one jug into another until the receiving jug is full, or the transferring jug is empty.

**Example 1:**

```bash
Input: x = 3, y = 5, target = 4

Output: true
```

Explanation:

Follow these steps to reach a total of 4 liters:

- Fill the 5-liter jug (0, 5).
- Pour from the 5-liter jug into the 3-liter jug, leaving 2 liters (3, 2).
- Empty the 3-liter jug (0, 2).
- Transfer the 2 liters from the 5-liter jug to the 3-liter jug (2, 0).
- Fill the 5-liter jug again (2, 5).
- Pour from the 5-liter jug into the 3-liter jug until the 3-liter jug is full. This leaves 4 liters in the 5-liter jug (3, 4).
- Empty the 3-liter jug. Now, you have exactly 4 liters in the 5-liter jug (0, 4).

Reference: The <a href="https://www.youtube.com/watch?v=BVtQNK_ZUJg&amp;ab_channel=notnek01" target="_blank">Die Hard</a> example.

**Example 2:**

```bash
Input: x = 2, y = 6, target = 5

Output: false
```

**Example 3:**

```bash
Input: x = 1, y = 2, target = 3

Output: true
```

Explanation: Fill both jugs. The total amount of water in both jugs is equal to 3 now.

**Constraints:**

- `1 <= x, y, target<= 10^3`

## Hints/Notes

- 2025/03/17 Q1
- dfs
- [Leetcode solution](https://leetcode.cn/problems/water-and-jug-problem/solutions/161010/shui-hu-wen-ti-by-leetcode-solution/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        unordered_set<int> visited;
        if (x + y < target) {
            return false;
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited.insert(0);
        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();
            if (a == target || b == target || a + b == target) {
                return true;
            }
            vector<pair<int, int>> next_pairs = {
                {0, b},
                {a, 0},
                {x, b},
                {a, y},
                {a - min(y - b, a), b + min(y - b, a)},
                {a + min(x - a, b), b - min(x - a, b)}
            };
            for (auto p : next_pairs) {
                int key = p.first * 1000 + p.second;
                if (!visited.contains(key)) {
                    q.push(p);
                    visited.insert(key);
                }
            }
        }
        return false;
    }
};
```
