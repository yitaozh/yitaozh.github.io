---
title: 875. Koko Eating Bananas
categories: Leetcode
date: 2023-01-30 11:34:28
tags:
    - Array
    - Binary Search
---

# [875\. Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

Koko loves to eat bananas. There are `n` piles of bananas, the i<sup>th</sup> pile has `piles[i]` bananas. The guards have gone and will come back in `h` hours.

Koko can decide her bananas-per-hour eating speed of `k`. Each hour, she chooses some pile of bananas and eats `k` bananas from that pile. If the pile has less than `k` bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return _the minimum integer_ `k` _such that she can eat all the bananas within_ `h` _hours_.

**Example 1:**

```text
Input: piles = [3,6,7,11], h = 8
Output: 4
```

**Example 2:**

```text
Input: piles = [30,11,23,4,20], h = 5
Output: 30
```

**Example 3:**

```text
Input: piles = [30,11,23,4,20], h = 6
Output: 23
```

**Constraints:**

* 1 <= piles.length <= 10<sup>4</sup>
* piles.length <= h <= 10<sup>9</sup>
* 1 <= piles[i] <= 10<sup>9</sup>

## Solution

Language: **C++**

```C++
class Solution {
public:
    int eatingHour(vector<int>& piles, int s) {
        int hour = 0;
        for (int pile : piles) {
            hour += pile / s;
            if (pile % s != 0) {
                hour++;
            }
        }
        return hour;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 0;
        for (int pile : piles) {
            if (right < pile) {
                right = pile;
            }
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            int hour = eatingHour(piles, mid);
            if (hour == h) {
                right = mid;
            } else if (hour > h) {
                left = mid + 1;
            } else if (hour < h) {
                right = mid;
            }
        }
        return left;
    }
};
```
