---
title: 2594. Minimum Time to Repair Cars
categories: Leetcode
date: 2025-03-28 02:46:04
tags:
    - Array
    - Binary Search
---

[2594. Minimum Time to Repair Cars](https://leetcode.com/problems/minimum-time-to-repair-cars/description/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days)

## Description

You are given an integer array `ranks` representing the **ranks**  of some mechanics. ranks<sub>i</sub> is the rank of the i^th mechanic. A mechanic with a rank `r` can repair n cars in `r * n^2` minutes.

You are also given an integer `cars` representing the total number of cars waiting in the garage to be repaired.

Return the **minimum**  time taken to repair all the cars.

**Note:**  All the mechanics can repair the cars simultaneously.

**Example 1:**

```bash
Input: ranks = [4,2,3,1], cars = 10
Output: 16
Explanation:
- The first mechanic will repair two cars. The time required is 4 * 2 * 2 = 16 minutes.
- The second mechanic will repair two cars. The time required is 2 * 2 * 2 = 8 minutes.
- The third mechanic will repair two cars. The time required is 3 * 2 * 2 = 12 minutes.
- The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​
```

**Example 2:**

```bash
Input: ranks = [5,1,8], cars = 6
Output: 16
Explanation:
- The first mechanic will repair one car. The time required is 5 * 1 * 1 = 5 minutes.
- The second mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
- The third mechanic will repair one car. The time required is 8 * 1 * 1 = 8 minutes.
It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​
```

**Constraints:**

- `1 <= ranks.length <= 10^5`
- `1 <= ranks[i] <= 100`
- `1 <= cars <= 10^6`

## Hints/Notes

- 2025/03/17 Q2
- binary search
- [Leetcode solution](https://leetcode.com/problems/minimum-time-to-repair-cars/editorial/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days)

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 0, right = LLONG_MAX;
        while (left + 1 < right) {
            long long mid = (left + right) / 2;
            if (canFix(mid, cars, ranks)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }

    bool canFix(long long time, int cars, vector<int>& ranks) {
        long long fix_cars = 0;
        for (int& rank : ranks) {
            // a mechanic with rank r can repair n cars in r * n ^ 2 time
            // so with r * (n ^ 2) = time => n ^ 2 = time / r
            fix_cars += (long long)sqrt(time * 1.0 / rank);
        }
        return fix_cars >= cars;
    }
};
```
