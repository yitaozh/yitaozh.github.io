---
title: 941. Valid Mountain Array
categories: Leetcode
date: 2025-04-27 17:39:26
tags:
    - Array
---

[941. Valid Mountain Array](https://leetcode.com/problems/valid-mountain-array/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-six-months)

## Description

Given an array of integers `arr`, return `true` if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

- `arr.length >= 3`
- There exists some `i` with `0 < i < arr.length - 1` such that:

- `arr[0] < arr[1] < ... < arr[i - 1] < arr[i]`
- `arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`

<img width="500" src="https://assets.leetcode.com/uploads/2019/10/20/hint_valid_mountain_array.png">

**Example 1:**

```bash
Input: arr = [2,1]
Output: false
```

**Example 2:**

```bash
Input: arr = [3,5,5]
Output: false
```

**Example 3:**

```bash
Input: arr = [0,3,2,1]
Output: true
```

**Constraints:**

- `1 <= arr.length <= 10^4`
- `0 <= arr[i] <= 10^4`

## Hints/Notes

- 2025/04/25 Q1
- array
- [Leetcode solution](https://leetcode.com/problems/valid-mountain-array/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) {
            return false;
        }
        int i = 0;
        while (i < n - 1 && arr[i] < arr[i + 1]) {
            i++;
        }
        if (i == 0 || i == n - 1) {
            return false;
        }
        while (i < n - 1 && arr[i] > arr[i + 1]) {
            i++;
        }
        return i == n - 1;
    }
};
```
