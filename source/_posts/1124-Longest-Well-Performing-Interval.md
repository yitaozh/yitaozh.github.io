---
title: 1124. Longest Well-Performing Interval
categories: Leetcode
date: 2023-11-13 17:55:19
tags:
    - Array
    - Hash Table
    - Stack
    - Monotonic Stack
    - Prefix Sum
---

# [1124\. Longest Well-Performing Interval](https://leetcode.com/problems/longest-well-performing-interval/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [Stack](https://leetcode.com/tag/https://leetcode.com/tag/stack//), [Monotonic Stack](https://leetcode.com/tag/https://leetcode.com/tag/monotonic-stack//), [Prefix Sum](https://leetcode.com/tag/https://leetcode.com/tag/prefix-sum//)

We are given `hours`, a list of the number of hours worked per day for a given employee.

A day is considered to be a _tiring day_ if and only if the number of hours worked is (strictly) greater than `8`.

A _well-performing interval_ is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.

Return the length of the longest well-performing interval.

**Example 1:**

```bash
Input: hours = [9,9,6,0,6,6,9]
Output: 3
Explanation: The longest well-performing interval is [9,9,6].
```

**Example 2:**

```bash
Input: hours = [6,6,6]
Output: 0
```

**Constraints:**

* 1 <= hours.length <= 10<sup>4</sup>
* `0 <= hours[i] <= 16`

## Hints/Notes

* preSum + map

## Solution

Language: **C++**

```C++
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int size = hours.size();
        vector<int> preSum(size + 1, 0);
        for (int i = 0; i < size; i++) {
            preSum[i + 1] = preSum[i] + (hours[i] > 8 ? 1 : -1);
        }
        map<int, int> m;
        int res = 0;
        for (int i = 0; i <= size; i++) {
            if (!m.contains(preSum[i])) {
                m[preSum[i]] = i;
            }
            if (preSum[i] > 0) {
                res = max(res, i);
            } else {
                if (m.contains(preSum[i] - 1)) {
                    res = max(res, i - m[preSum[i] - 1]);
                }
            }
        }
        return res;
    }
};
```
