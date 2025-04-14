---
title: 2276. Count Integers in Intervals
categories: Leetcode
date: 2025-04-14 03:40:50
tags:
    - Design
    - Segment Tree
    - Ordered Set
---

[2276. Count Integers in Intervals](https://leetcode.com/problems/count-integers-in-intervals/description/?envType=company&envId=linkedin&favoriteSlug=linkedin-six-months)

## Description

Given an **empty**  set of intervals, implement a data structure that can:

- **Add**  an interval to the set of intervals.
- **Count**  the number of integers that are present in **at least one**  interval.

Implement the `CountIntervals` class:

- `CountIntervals()` Initializes the object with an empty set of intervals.
- `void add(int left, int right)` Adds the interval `[left, right]` to the set of intervals.
- `int count()` Returns the number of integers that are present in **at least one**  interval.

**Note**  that an interval `[left, right]` denotes all the integers `x` where `left <= x <= right`.

**Example 1:**

```bash
Input

["CountIntervals", "add", "add", "count", "add", "count"]
[[], [2, 3], [7, 10], [], [5, 8], []]
Output

[null, null, null, 6, null, 8]

Explanation

CountIntervals countIntervals = new CountIntervals(); // initialize the object with an empty set of intervals.
countIntervals.add(2, 3);  // add [2, 3] to the set of intervals.
countIntervals.add(7, 10); // add [7, 10] to the set of intervals.
countIntervals.count();    // return 6
                           // the integers 2 and 3 are present in the interval [2, 3].
                           // the integers 7, 8, 9, and 10 are present in the interval [7, 10].
countIntervals.add(5, 8);  // add [5, 8] to the set of intervals.
countIntervals.count();    // return 8
                           // the integers 2 and 3 are present in the interval [2, 3].
                           // the integers 5 and 6 are present in the interval [5, 8].
                           // the integers 7 and 8 are present in the intervals [5, 8] and [7, 10].
                           // the integers 9 and 10 are present in the interval [7, 10].
```

**Constraints:**

- `1 <= left <= right <= 10^9`
- At most `10^5` calls **in total**  will be made to `add` and `count`.
- At least **one**  call will be made to `count`.

## Hints/Notes

- 2025/04/12 Q1
- merge intervals
- [0x3F's solution](https://leetcode.cn/problems/count-integers-in-intervals/solutions/1495396/by-endlesscheng-clk2/?envType=company&envId=linkedin&favoriteSlug=linkedin-six-months)

## Solution

Language: **C++**

```C++
class CountIntervals {
public:
    map<int, int> intervals;
    int res = 0;

    CountIntervals() {

    }

    void add(int left, int right) {
        auto it = intervals.lower_bound(left);
        if (it != intervals.begin()) {
            auto p = prev(it);
            if (p->second >= left) {
                it--;
            }
        }
        for (; it != intervals.end() && it->first <= right; intervals.erase(it++)) {
            int l = it->first, r = it->second;
            res -= r - l + 1;
            left = min(l, left);
            right = max(r, right);
        }
        intervals[left] = right;
        res += right - left + 1;
    }

    int count() {
        return res;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
```
