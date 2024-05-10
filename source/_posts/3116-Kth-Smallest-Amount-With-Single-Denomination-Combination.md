---
title: 3116. Kth Smallest Amount With Single Denomination Combination
categories: Leetcode
date: 2024-05-10 14:05:32
tags:
    - Array
    - Math
    - Binary Search
    - Bit Manipulation
    - Combinatorics
    - Number Theory
---

[3116. Kth Smallest Amount With Single Denomination Combination](https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/description/)

## Description

You are given an integer array `coins` representing coins of different denominations and an integer `k`.

You have an infinite number of coins of each denomination. However, you are **not allowed**  to combine coins of different denominations.

Return the `k^th` **smallest**  amount that can be made using these coins.

**Example 1:**

```bash
Input: coins = [3,6,9], k = 3

Output:  9

Explanation: The given coins can make the following amounts:<br>
Coin 3 produces multiples of 3: 3, 6, 9, 12, 15, etc.<br>
Coin 6 produces multiples of 6: 6, 12, 18, 24, etc.<br>
Coin 9 produces multiples of 9: 9, 18, 27, 36, etc.<br>
All of the coins combined produce: 3, 6, **9** , 12, 15, etc.
```

**Example 2:**

```bash
Input: coins = [5,2], k = 7

Output: 12

Explanation: The given coins can make the following amounts:<br>
Coin 5 produces multiples of 5: 5, 10, 15, 20, etc.<br>
Coin 2 produces multiples of 2: 2, 4, 6, 8, 10, 12, etc.<br>
All of the coins combined produce: 2, 4, 5, 6, 8, 10, **12** , 14, 15, etc.
```

**Constraints:**

- `1 <= coins.length <= 15`
- `1 <= coins[i] <= 25`
- `1 <= k <= 2 * 10^9`
- `coins` contains pairwise distinct integers.

## Hints/Notes

- binary search
- Principle of inclusion-exclusion

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long left = 1, right = LLONG_MAX;
        while (left < right) {
            long long mid = (right - left) / 2 + left;
            long index = findIndex(mid, coins);
            if (index == k) {
                right = mid;
            } else if (index > k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    long findIndex(long long mid, vector<int>& coins) {
        long res = 0;
        select(mid, coins, res, 0, 0, 1);
        return res;
    }

    void select(long long mid, vector<int>& coins, long& res, int index, int numSelected, long long factor) {
        if (index == coins.size()) {
            if (numSelected > 0) {
                if (numSelected % 2 == 1) {
                    res += mid / factor;
                } else {
                    res -= mid / factor;
                }
            }
            return;
        }
        select(mid, coins, res, index + 1, numSelected + 1, lcm(factor, coins[index]));
        select(mid, coins, res, index + 1, numSelected, factor);
    }
};
```
