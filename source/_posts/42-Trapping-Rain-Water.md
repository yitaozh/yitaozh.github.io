---
title: 42. Trapping Rain Water
categories: Leetcode
date: 2024-12-21 00:45:36
tags:
    - Array
    - Two Pointers
    - Dynamic Programming
    - Stack
    - Monotonic Stack
---

[42. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

**Example 1:**

<img src="https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png" style="width: 412px; height: 161px;">

```bash
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
```

**Example 2:**

```bash
Input: height = [4,2,0,3,2,5]
Output: 9
```

**Constraints:**

- `n == height.length`
- `1 <= n <= 2 * 10^4`
- `0 <= height[i] <= 10^5`

## Hints/Notes

- 2024/12/20
- two pointers
- work on monotonic stack next time
- [0x3F's solution](https://leetcode.cn/problems/trapping-rain-water/solutions/1974340/zuo-liao-nbian-huan-bu-hui-yi-ge-shi-pin-ukwm/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1, max_left = 0, max_right = 0, res = 0;
        while (left <= right) {
             max_left = max(height[left], max_left);
             max_right = max(height[right], max_right);
             if (max_left < max_right) {
                res += max_left - height[left];
                left++;
             } else {
                res += max_right - height[right];
                right--;
             }
        }
        return res;
    }
};
```

monotonic stack

```C++
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int n = height.size(), res = 0;
        for (int i = 0; i < n; i++) {
            int h = height[i];
            while (!stk.empty() && height[stk.top()] < h) {
                int bottom = height[stk.top()];
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                int left = stk.top();
                res += (min(h, height[left]) - bottom) * (i - left - 1);
            }
            stk.push(i);
        }
        return res;
    }
};
```
