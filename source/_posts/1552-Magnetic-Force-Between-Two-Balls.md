---
title: 1552. Magnetic Force Between Two Balls
categories: Leetcode
date: 2025-04-23 01:39:31
tags:
    - Array
    - Binary Search
    - Sorting
---

[1552. Magnetic Force Between Two Balls](https://leetcode.com/problems/magnetic-force-between-two-balls/description/)

## Description

In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has `n` empty baskets, the `i^th` basket is at `position[i]`, Morty has `m` balls and needs to distribute the balls into the baskets such that the **minimum magnetic force**  between any two balls is **maximum** .

Rick stated that magnetic force between two different balls at positions `x` and `y` is `|x - y|`.

Given the integer array `position` and the integer `m`. Return the required force.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/08/11/q3v1.jpg" style="width: 562px; height: 195px;">

```bash
Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
```

**Example 2:**

```bash
Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
Explanation: We can use baskets 1 and 1000000000.
```

**Constraints:**

- `n == position.length`
- `2 <= n <= 10^5`
- `1 <= position[i] <= 10^9`
- All integers in `position` are **distinct** .
- `2 <= m <= position.length`

## Hints/Notes

- 2025/04/21 Q3
- binary search
- [Leetcode solution](https://leetcode.com/problems/magnetic-force-between-two-balls/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        ranges::sort(position);
        int n = position.size();
        int low = 0, high = ceil(position[n - 1] / (m - 1.0)) + 1;
        while (low + 1 < high) {
            int mid = (low + high) / 2;
            if (check(mid, position, m)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return low;
    }

    bool check(int interval, vector<int>& position, int m) {
        int placed = 1, prev = position[0];
        for (int i = 1; i < position.size(); i++) {
            if (position[i] >= prev + interval) {
                placed++;
                prev = position[i];
            }
            if (placed >= m) {
                return true;
            }
        }
        return false;
    }
};
```
