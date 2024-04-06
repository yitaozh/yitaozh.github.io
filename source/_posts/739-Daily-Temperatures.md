---
title: 739. Daily Temperatures
categories: Leetcode
date: 2023-09-10 23:29:31
tags:
    - Array
    - Stack
    - Monotonic Stack
---

[739\. Daily Temperatures](https://leetcode.com/problems/daily-temperatures/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Stack](https://leetcode.com/tag/https://leetcode.com/tag/stack//), [Monotonic Stack](https://leetcode.com/tag/https://leetcode.com/tag/monotonic-stack//)

Given an array of integers `temperatures` represents the daily temperatures, return _an array_ `answer` _such that_ `answer[i]` _is the number of days you have to wait after the_ i<sup>th</sup> _day to get a warmer temperature_. If there is no future day for which this is possible, keep `answer[i] == 0` instead.

**Example 1:**

```bash
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
```

**Example 2:**

```bash
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
```

**Example 3:**

```bash
Input: temperatures = [30,60,90]
Output: [1,1,0]
```

**Constraints:**

* 1 <= temperatures.length <= 10<sup>5</sup>
* `30 <= temperatures[i] <= 100`

## Hints/Notes

* Monotonic Stack

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> warmer;
        int size = temperatures.size();
        vector<int> res(size, 0);
        for (int i = size - 1; i >= 0; i--) {
            while (!warmer.empty() && warmer.top().first <= temperatures[i]) {
                warmer.pop();
            }
            res[i] = warmer.empty() ? 0 : warmer.top().second - i;
            warmer.push({temperatures[i], i});
        }
        return res;
    }
};
```
