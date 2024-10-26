---
title: 1151. Minimum Swaps to Group All 1's Together
categories: Leetcode
date: 2024-10-25 21:28:47
tags:
    - Array
    - Sliding Window
---

[1151. Minimum Swaps to Group All 1's Together](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/description/)

## Description

Given a binary array `data`, return the minimum number of swaps required to group all `1`’s present in the array together in **any place**  in the array.

**Example 1:**

```bash
Input: data = [1,0,1,0,1]
Output: 1
Explanation: There are 3 ways to group all 1's together:
[1,1,1,0,0] using 1 swap.
[0,1,1,1,0] using 2 swaps.
[0,0,1,1,1] using 1 swap.
The minimum is 1.
```

**Example 2:**

```bash
Input: data = [0,0,0,1,0]
Output: 0
Explanation: Since there is only one 1 in the array, no swaps are needed.
```

**Example 3:**

```bash
Input: data = [1,0,1,0,1,0,0,1,1,0,1]
Output: 3
Explanation: One possible solution that uses 3 swaps is [0,0,0,0,0,1,1,1,1,1,1].
```

**Constraints:**

- `1 <= data.length <= 10^5`
- `data[i]` is either `0` or `1`.

## Hints/Notes

- sliding window

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n = data.size(), right = 0, k = 0, mx = 0, cur = 0;
        for (int d : data) {
            k += d;
        }
        while (right < n) {
            int r = data[right];
            cur += r;
            if (right >= k - 1) {
                mx = max(mx, cur);
                cur -= data[right - k + 1];
            }
            right++;
        }
        return k - mx;
    }
};
```
