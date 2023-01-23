---
title: 1094. Car Pooling
categories: Leetcode
date: 2023-01-23 11:27:24
tags:
    - Array
    - Sorting
    - Heap (Priority Queue)
    - Simulation
    - Prefix Sum
---

# [1094\. Car Pooling](https://leetcode.com/problems/car-pooling/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/array/), [Sorting](https://leetcode.com/tag/sorting/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Simulation](https://leetcode.com/tag/simulation/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

There is a car with `capacity` empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer `capacity` and an array `trips` where trips[i] = [numPassengers<sub>i</sub>, from<sub>i</sub>, to<sub>i</sub>] indicates that the i<sup>th</sup> trip has numPassengers<sub>i</sub> passengers and the locations to pick them up and drop them off are from<sub>i</sub> and to<sub>i</sub> respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return `true` _if it is possible to pick up and drop off all passengers for all the given trips, or_ `false` _otherwise_.

**Example 1:**

```
Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
```

**Example 2:**

```
Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true
```

**Constraints:**

*   `1 <= trips.length <= 1000`
*   `trips[i].length == 3`
*   1 <= numPassengers<sub>i</sub> <= 100
*   0 <= from<sub>i</sub> < to<sub>i</sub> <= 1000
*   1 <= capacity <= 10<sup>5</sup>

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diffs(1001, 0);
        for (vector<int> trip : trips) {
            int val = trip[0], from = trip[1], to = trip[2] - 1;
            diffs[from] += val;
            if (to + 1 < diffs.size()) {
                diffs[to + 1] -= val;
            }
        }
        vector<int> numPassengers;
        if (diffs[0] > capacity) {
            return false;
        } else {
            numPassengers.push_back(diffs[0]);
        }
        for (int i = 1; i < diffs.size(); i++) {
            numPassengers.push_back(numPassengers[i - 1] + diffs[i]);
            if (numPassengers[i] > capacity) {
                return false;
            }
        }
        return true;
    }
};
```