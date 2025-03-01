---
title: 278. First Bad Version
categories: Leetcode
date: 2025-01-21 02:20:29
tags:
    - Binary Search
    - Interactive
---

[278. First Bad Version](https://leetcode.com/problems/first-bad-version/description/)

## Description

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have `n` versions `[1, 2, ..., n]` and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API `bool isBadVersion(version)` which returns whether `version` is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

**Example 1:**

```bash
Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5)-> true
call isBadVersion(4)-> true
Then 4 is the first bad version.
```

**Example 2:**

```bash
Input: n = 1, bad = 1
Output: 1
```

**Constraints:**

- `1 <= bad <= n <= 2^31 - 1`

## Hints/Notes

- 2025/01/20
- binary search
- No solution from 0x3F

## Solution

Language: **C++**

```C++
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        // every version >= right is bad version
        // every version < left is good version
        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```
