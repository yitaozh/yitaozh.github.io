---
title: 1762. Buildings With an Ocean View
categories: Leetcode
date: 2025-01-27 13:14:40
tags:
    - Array
    - Stack
    - Monotonic Stack
---

[1762. Buildings With an Ocean View](https://leetcode.com/problems/buildings-with-an-ocean-view/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

There are `n` buildings in a line. You are given an integer array `heights` of size `n` that represents the heights of the buildings in the line.

The ocean is to the right of the buildings. A building has an ocean view if the building can see the ocean without obstructions. Formally, a building has an ocean view if all the buildings to its right have a **smaller**  height.

Return a list of indices **(0-indexed)**  of buildings that have an ocean view, sorted in increasing order.

**Example 1:**

```bash
Input: heights = [4,2,3,1]
Output: [0,2,3]
Explanation: Building 1 (0-indexed) does not have an ocean view because building 2 is taller.
```

**Example 2:**

```bash
Input: heights = [4,3,2,1]
Output: [0,1,2,3]
Explanation: All the buildings have an ocean view.
```

**Example 3:**

```bash
Input: heights = [1,3,2,4]
Output: [3]
Explanation: Only building 3 has an ocean view.
```

**Constraints:**

- `1 <= heights.length <= 10^5`
- `1 <= heights[i] <= 10^9`

## Hints/Notes

- 2025/01/27
- iteration
- [Leetcode solution](https://leetcode.com/problems/buildings-with-an-ocean-view/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int max_height = 0;
        vector<int> res;
        for (int i = heights.size() - 1; i >= 0; i--) {
            if (heights[i] > max_height) {
                res.push_back(i);
            }
            max_height = max(max_height, heights[i]);
        }
        ranges::reverse(res);
        return res;
    }
};
```
