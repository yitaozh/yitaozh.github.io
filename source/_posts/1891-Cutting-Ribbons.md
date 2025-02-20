---
title: 1891. Cutting Ribbons
categories: Leetcode
date: 2025-02-20 17:50:03
tags:
    - Array
    - Binary Search
---

[1891. Cutting Ribbons](https://leetcode.com/problems/cutting-ribbons/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

You are given an integer array `ribbons`, where `ribbons[i]` represents the length of the `i^th` ribbon, and an integer `k`. You may cut any of the ribbons into any number of segments of **positive integer**  lengths, or perform no cuts at all.

- For example, if you have a ribbon of length `4`, you can:

- Keep the ribbon of length `4`,
- Cut it into one ribbon of length `3` and one ribbon of length `1`,
- Cut it into two ribbons of length `2`,
- Cut it into one ribbon of length `2` and two ribbons of length `1`, or
- Cut it into four ribbons of length `1`.

Your task is to determine the **maximum**  length of ribbon, `x`, that allows you to cut at least `k` ribbons, each of length `x`. You can discard any leftover ribbon from the cuts. If it is **impossible**  to cut `k` ribbons of the same length, return 0.

**Example 1:**

```bash
Input: ribbons = [9,7,5], k = 3
Output: 5
Explanation:
- Cut the first ribbon to two ribbons, one of length 5 and one of length 4.
- Cut the second ribbon to two ribbons, one of length 5 and one of length 2.
- Keep the third ribbon as it is.
Now you have 3 ribbons of length 5.```

**Example 2:**

```bash
Input: ribbons = [7,5,9], k = 4
Output: 4
Explanation:
- Cut the first ribbon to two ribbons, one of length 4 and one of length 3.
- Cut the second ribbon to two ribbons, one of length 4 and one of length 1.
- Cut the third ribbon to three ribbons, two of length 4 and one of length 1.
Now you have 4 ribbons of length 4.
```

**Example 3:**

```bash
Input: ribbons = [5,7,9], k = 22
Output: 0
Explanation: You cannot obtain k ribbons of the same positive integer length.
```

**Constraints:**

- `1 <= ribbons.length <= 10^5`
- `1 <= ribbons[i] <= 10^5`
- `1 <= k <= 10^9`

## Hints/Notes

- 2025/02/09
- binary search
- [Leetcode solution](https://leetcode.com/problems/cutting-ribbons/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        // if the ribbon length is max_len, then we can cut 1
        int low = 0, high = ranges::max(ribbons) + 1;
        while (low + 1 < high) {
            int mid = (low + high) / 2;
            if (check(mid, ribbons, k)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return low;
    }

    bool check(int len, vector<int>& ribbons, int k) {
        int sum = 0;
        for (int & r : ribbons) {
            sum += r / len;
        }
        return sum >= k;
    }
};
```
