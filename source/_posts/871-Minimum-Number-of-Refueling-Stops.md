---
title: 871. Minimum Number of Refueling Stops
categories: Leetcode
date: 2025-03-16 17:24:25
tags:
    - Array
    - Dynamic Programming
    - Greedy
    - Heap (Priority Queue)
---

[871. Minimum Number of Refueling Stops](https://leetcode.com/problems/minimum-number-of-refueling-stops/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

A car travels from a starting position to a destination which is `target` miles east of the starting position.

There are gas stations along the way. The gas stations are represented as an array `stations` where `stations[i] = [position<sub>i</sub>, fuel<sub>i</sub>]` indicates that the `i^th` gas station is `position<sub>i</sub>` miles east of the starting position and has `fuel<sub>i</sub>` liters of gas.

The car starts with an infinite tank of gas, which initially has `startFuel` liters of fuel in it. It uses one liter of gas per one mile that it drives. When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.

Return the minimum number of refueling stops the car must make in order to reach its destination. If it cannot reach the destination, return `-1`.

Note that if the car reaches a gas station with `0` fuel left, the car can still refuel there. If the car reaches the destination with `0` fuel left, it is still considered to have arrived.

**Example 1:**

```bash
Input: target = 1, startFuel = 1, stations = []
Output: 0
Explanation: We can reach the target without refueling.
```

**Example 2:**

```bash
Input: target = 100, startFuel = 1, stations = [[10,100]]
Output: -1
Explanation: We can not reach the target (or even the first gas station).
```

**Example 3:**

```bash
Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
Output: 2
Explanation: We start with 10 liters of fuel.
We drive to position 10, expending 10 liters of fuel.  We refuel from 0 liters to 60 liters of gas.
Then, we drive from position 10 to position 60 (expending 50 liters of fuel),
and refuel from 10 liters to 50 liters of gas.  We then drive to and reach the target.
We made 2 refueling stops along the way, so we return 2.
```

**Constraints:**

- `1 <= target, startFuel <= 10^9`
- `0 <= stations.length <= 500`
- 1 <= position<sub>i</sub> < position<sub>i+1</sub> < target
- 1 <= fuel<sub>i</sub> < 10^9

## Hints/Notes

- 2025/02/08 Q3
- priority queue
- [0x3F's solution](https://leetcode.cn/problems/minimum-number-of-refueling-stops/solutions/2921064/zui-da-dui-tan-xin-pythonjavacgojsrust-b-yldp/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int res = 0, curEnd = startFuel;
        ranges::sort(stations);
        priority_queue<int> pq;
        for (auto station : stations) {
            int position = station[0], fuel = station[1];
            if (position <= curEnd) {
                pq.push(fuel);
            } else {
                while (!pq.empty()) {
                    curEnd += pq.top();
                    res++;
                    pq.pop();
                    if (curEnd >= position) {
                        pq.push(fuel);
                        break;
                    }
                }
                if (curEnd < position) {
                    return -1;
                }
            }
        }
        while (curEnd < target && !pq.empty()) {
            res++;
            curEnd += pq.top();
            pq.pop();
        }
        return (curEnd >= target) ? res : -1;
    }
};
```
