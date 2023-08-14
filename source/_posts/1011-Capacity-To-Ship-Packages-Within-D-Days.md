---
title: 1011. Capacity To Ship Packages Within D Days
categories: Leetcode
date: 2023-01-30 12:18:19
tags:
    - Array
    - Binary Search
---

# [1011\. Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

A conveyor belt has packages that must be shipped from one port to another within `days` days.

The i<sup>th</sup> package on the conveyor belt has a weight of `weights[i]`. Each day, we load the ship with packages on the conveyor belt (in the order given by `weights`). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within `days` days.

**Example 1:**

```text
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
```

**Example 2:**

```text
Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
```

**Example 3:**

```text
Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
```

**Constraints:**

* 1 <= days <= weights.length <= 5 * 10<sup>4</sup>
* `1 <= weights[i] <= 500`

## Hints/Notes

* Binary search
* Helper function to get how many days with specific capacity

## Solution

Language: **C++**

```C++
class Solution {
public:
    int shipTime(vector<int>& weights, int c) {
        int days = 0;
        for (int i = 0; i < weights.size();) {
            int sum = 0;
            while (sum <= c && i < weights.size()) {
                sum += weights[i++];
            }
            if (sum > c) {
                i--;
            }
            days++;
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0;
        for (int weight : weights) {
            if (weight > left) {
                left = weight;
            }
            right += weight;
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            int time = shipTime(weights, mid);
            if (time == days) {
                right = mid;
            } else if (time > days) {
                left = mid + 1;
            } else if (time < days) {
                right = mid;
            }
        }
        return left;
    }
};
```
