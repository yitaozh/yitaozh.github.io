---
title: 84. Largest Rectangle in Histogram
categories: Leetcode
date: 2024-12-26 01:25:03
tags:
    - Array
    - Stack
    - Monotonic Stack
---

[84. Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given an array of integers `heights` representing the histogram's bar height where the width of each bar is `1`, return the area of the largest rectangle in the histogram.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/histogram.jpg" style="width: 522px; height: 242px;">

```bash
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/histogram-1.jpg" style="width: 202px; height: 362px;">

```bash
Input: heights = [2,4]
Output: 4
```

**Constraints:**

- `1 <= heights.length <= 10^5`
- `0 <= heights[i] <= 10^4`

## Hints/Notes

- 2024/12/25
- monotonic stack
- [0x3F's solution](https://leetcode.cn/problems/largest-rectangle-in-histogram/solutions/2695467/dan-diao-zhan-fu-ti-dan-pythonjavacgojsr-89s7/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> stk;
        heights.push_back(0);
        int n = heights.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int h = heights[i], w = 0;
            while (!stk.empty() && heights[stk.top().first] >= h) {
                auto& [idx, prev_w] = stk.top();
                stk.pop();
                w += prev_w;
                res = max(res, w * heights[idx]);
            }
            stk.push({i, 1 + w});
        }
        return res;
    }
};
```
