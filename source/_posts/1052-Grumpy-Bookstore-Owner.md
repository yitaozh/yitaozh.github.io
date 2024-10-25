---
title: 1052. Grumpy Bookstore Owner
categories: Leetcode
date: 2024-10-24 23:49:00
tags:
    - Array
    - Sliding Window
---

[1052. Grumpy Bookstore Owner](https://leetcode.com/problems/grumpy-bookstore-owner/description/)

## Description

There is a bookstore owner that has a store open for `n` minutes. You are given an integer array `customers` of length `n` where `customers[i]` is the number of the customers that enter the store at the start of the `i^th` minute and all those customers leave after the end of that minute.

During certain minutes, the bookstore owner is grumpy. You are given a binary array grumpy where `grumpy[i]` is `1` if the bookstore owner is grumpy during the `i^th` minute, and is `0` otherwise.

When the bookstore owner is grumpy, the customers entering during that minute are not **satisfied** . Otherwise, they are satisfied.

The bookstore owner knows a secret technique to remain **not grumpy**  for `minutes` consecutive minutes, but this technique can only be used **once** .

Return the **maximum**  number of customers that can be satisfied throughout the day.

**Example 1:**

```bash
Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3

Output: 16
```

Explanation:

The bookstore owner keeps themselves not grumpy for the last 3 minutes.

The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.

**Example 2:**

```bash
Input: customers = [1], grumpy = [0], minutes = 1

Output: 1
```

**Constraints:**

- `n == customers.length == grumpy.length`
- `1 <= minutes <= n <= 2 * 10^4`
- `0 <= customers[i] <= 1000`
- `grumpy[i]` is either `0` or `1`.

## Hints/Notes

- sliding window

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size(), sum = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i]) {
                customers[i] *= -1;
            }
        }
        int positiveSum = 0, negativeSum = 0, right = 0, negativeMax = 0;
        while (right < n) {
            if (customers[right] >= 0) {
                positiveSum += customers[right];
            } else {
                negativeSum -= customers[right];
            }
            if (right >= minutes - 1) {
                negativeMax = max(negativeMax, negativeSum);
                if (customers[right - minutes + 1] < 0) {
                    negativeSum += customers[right - minutes + 1];
                }
            }
            right++;
        }
        return positiveSum + negativeMax;
    }
};
```
