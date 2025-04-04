---
title: 729. My Calendar I
categories: Leetcode
date: 2025-04-04 13:37:11
tags:
    - Array
    - Binary Search
    - Design
    - Segment Tree
    - Ordered Set
---

[729. My Calendar I](https://leetcode.com/problems/my-calendar-i/description/)

## Description

You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a **double booking** .

A **double booking**  happens when two events have some non-empty intersection (i.e., some moment is common to both events.).

The event can be represented as a pair of integers `startTime` and `endTime` that represents a booking on the half-open interval `[startTime, endTime)`, the range of real numbers `x` such that `startTime <= x < endTime`.

Implement the `MyCalendar` class:

- `MyCalendar()` Initializes the calendar object.
- `boolean book(int startTime, int endTime)` Returns `true` if the event can be added to the calendar successfully without causing a **double booking** . Otherwise, return `false` and do not add the event to the calendar.

**Example 1:**

```bash
Input

["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]
Output

[null, true, false, true]

Explanation

MyCalendar myCalendar = new MyCalendar();
myCalendar.book(10, 20); // return True
myCalendar.book(15, 25); // return False, It can not be booked because time 15 is already booked by another event.
myCalendar.book(20, 30); // return True, The event can be booked, as the first event takes every time less than 20, but not including 20.
```

**Constraints:**

- `0 <= start < end <= 10^9`
- At most `1000` calls will be made to `book`.

## Hints/Notes

- 2025/03/28 Q3
- ordered set
- [Leetcode solution](https://leetcode.com/problems/my-calendar-i/editorial/)

## Solution

Language: **C++**

```C++
class MyCalendar {
public:
    set<pair<int, int>> s;

    MyCalendar() {

    }
    // start, it->first, it->second, endTime
    // start,
    bool book(int startTime, int endTime) {
        auto it = s.lower_bound({startTime, endTime});
        if (it != s.end()) {
            auto [next_start, next_end] = *it;
            if (endTime > next_start) {
                return false;
            }
        }
        if (it != s.begin()) {
            auto [prev_start, prev_end] = *prev(it);
            if (prev_end > startTime) {
                return false;
            }
        }
        s.insert({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
```
