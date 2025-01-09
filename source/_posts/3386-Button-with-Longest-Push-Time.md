---
title: 3386. Button with Longest Push Time
categories: Leetcode
date: 2025-01-09 17:28:11
tags:
    - Array
---

[3386. Button with Longest Push Time](https://leetcode.com/problems/button-with-longest-push-time/description/)

## Description

You are given a 2D array `events` which represents a sequence of events where a child pushes a series of buttons on a keyboard.

Each events[i] = [index<sub>i</sub>, time<sub>i</sub>] indicates that the button at index index<sub>i</sub> was pressed at time time<sub>i</sub>.

- The array is **sorted**  in increasing order of `time`.
- The time taken to press a button is the difference in time between consecutive button presses. The time for the first button is simply the time at which it was pressed.

Return the `index` of the button that took the **longest**  time to push. If multiple buttons have the same longest time, return the button with the **smallest**  `index`.

**Example 1:**

```bash
Input: events = [[1,2],[2,5],[3,9],[1,15]]

Output: 1
```

Explanation:

- Button with index 1 is pressed at time 2.
- Button with index 2 is pressed at time 5, so it took `5 - 2 = 3` units of time.
- Button with index 3 is pressed at time 9, so it took `9 - 5 = 4` units of time.
- Button with index 1 is pressed again at time 15, so it took `15 - 9 = 6` units of time.

**Example 2:**

```bash
Input: events = [[10,5],[1,7]]

Output: 10
```

Explanation:

- Button with index 10 is pressed at time 5.
- Button with index 1 is pressed at time 7, so it took `7 - 5 = 2` units of time.

**Constraints:**

- `1 <= events.length <= 1000`
- events[i] == [index<sub>i</sub>, time<sub>i</sub>]
- 1 <= index<sub>i</sub>, time<sub>i</sub> <= 10^5
- The input is generated such that `events` is sorted in increasing order of time<sub>i</sub>.

## Hints/Notes

- 2025/01/09
- [0x3F's solution](https://leetcode.cn/problems/button-with-longest-push-time/solutions/3020639/yi-ci-bian-li-jian-ji-xie-fa-pythonjavac-rsdh/)(checked)
- Weekly Contest 428

## Solution

Language: **C++**

```C++
class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int n = events.size(), min_index = events[0][0], max_time = events[0][1];
        for (int i = 1; i < n; i++) {
            int time = events[i][1] - events[i - 1][1], idx = events[i][0];
            if (time > max_time || (time == max_time && idx < min_index)) {
                max_time = time;
                min_index = idx;
            }
        }
        return min_index;
    }
};
```
