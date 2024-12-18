---
title: 11. Container With Most Water
categories: Leetcode
date: 2024-12-18 01:19:28
tags:
    - Array
    - Two Pointers
    - Greedy
---

[11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/description/?envType=problem-list-v2&envId=plakya4j)

## Description

You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `i^th` line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

**Notice**  that you may not slant the container.

**Example 1:**

<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg" style="width: 600px; height: 287px;">

```bash
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
```

**Example 2:**

```bash
Input: height = [1,1]
Output: 1
```

**Constraints:**

- `n == height.length`
- `2 <= n <= 10^5`
- `0 <= height[i] <= 10^4`

## Hints/Notes

- 2024/12/17
- two pointers
- [0x3F's solution](https://leetcode.cn/problems/container-with-most-water/solutions/1974355/by-endlesscheng-f0xz/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, res = 0;
        while (left < right) {
            res = max(res, (right - left) * min(height[left], height[right]));
            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }
        return res;
    }
};
```
