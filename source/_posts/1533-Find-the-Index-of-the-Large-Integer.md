---
title: 1533. Find the Index of the Large Integer
categories: Leetcode
date: 2023-01-19 17:52:55
tags:
    - Array
    - Binary Search
    - Interactive
---

# [1672\. Find the Index of the Large Integer](https://leetcode.com/problems/find-the-index-of-the-large-integer/)

## Description

Difficulty: **Medium**

undefined

## Solution

Language: **C++**

```C++
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y]
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int left = 0, right = reader.length() - 1;
        while (left < right) {
            int window = right - left + 1; // number of items
            int m1 = window % 2 == 0 ? left + (right - left) / 2 : left + (right - left) / 2 - 1;
            int m2 = window % 2 == 0 ? left + (right - left) / 2 + 1 : left + (right - left) / 2 + 1;
            int res = reader.compareSub(left, m1, m2, right);
            if (res == 0) {
                return m1 + 1;
            } else if (res == -1) {
                left = m1 + 1;
            } else if (res == 1) {
                right = m2 - 1;
            }
        }
        return left;
    }
};
```