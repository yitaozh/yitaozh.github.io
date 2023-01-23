---
title: 1109. Corporate Flight Bookings
categories: Leetcode
date: 2023-01-23 11:24:04
tags:
    - Array
    - Prefix Sum
---

# [1109\. Corporate Flight Bookings](https://leetcode.com/problems/corporate-flight-bookings/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/array/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

There are `n` flights that are labeled from `1` to `n`.

You are given an array of flight bookings `bookings`, where bookings[i] = [first<sub>i</sub>, last<sub>i</sub>, seats<sub>i</sub>] represents a booking for flights first<sub>i</sub> through last<sub>i</sub> (**inclusive**) with seats<sub>i</sub> seats reserved for **each flight** in the range.

Return _an array_ `answer` _of length_ `n`_, where_ `answer[i]` _is the total number of seats reserved for flight_ `i`.

**Example 1:**

```text
Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
Output: [10,55,45,25,25]
Explanation:
Flight labels:        1   2   3   4   5
Booking 1 reserved:  10  10
Booking 2 reserved:      20  20
Booking 3 reserved:      25  25  25  25
Total seats:         10  55  45  25  25
Hence, answer = [10,55,45,25,25]
```

**Example 2:**

```text
Input: bookings = [[1,2,10],[2,2,15]], n = 2
Output: [10,25]
Explanation:
Flight labels:        1   2
Booking 1 reserved:  10  10
Booking 2 reserved:      15
Total seats:         10  25
Hence, answer = [10,25]

```

**Constraints:**

* 1 <= n <= 2 * 10<sup>4</sup>
* 1 <= bookings.length <= 2 * 10<sup>4</sup>
* `bookings[i].length == 3`
* 1 <= first<sub>i</sub> <= last<sub>i</sub> <= n
* 1 <= seats<sub>i</sub> <= 10<sup>4</sup>

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diffs(n, 0);
        for (vector<int> booking : bookings) {
            int start = booking[0] - 1, end = booking[1] - 1, diff = booking[2];
            diffs[start] += diff;
            if (end + 1 < n) {
                diffs[end + 1] -= diff;
            }
        }
        vector<int> res;
        res.push_back(diffs[0]);
        for (int i = 1; i < n; i++) {
            res.push_back(res[i - 1] + diffs[i]);
        }
        return res;
    }
};
```
