---
title: 2269. Find the K-Beauty of a Number
categories: Leetcode
date: 2024-10-26 21:03:45
tags:
    - Math
    - String
    - Sliding Window
---

[2269. Find the K-Beauty of a Number](https://leetcode.com/problems/find-the-k-beauty-of-a-number/description/)

## Description

The **k-beauty**  of an integer `num` is defined as the number of **substrings**  of `num` when it is read as a string that meet the following conditions:

- It has a length of `k`.
- It is a divisor of `num`.

Given integers `num` and `k`, return the k-beauty of `num`.

Note:

- **Leading zeros**  are allowed.
- `0` is not a divisor of any value.

A **substring**  is a contiguous sequence of characters in a string.

**Example 1:**

```bash
Input: num = 240, k = 2
Output: 2
```

Explanation: The following are the substrings of num of length k:

- "24" from "**24** 0": 24 is a divisor of 240.
- "40" from "2 **40** ": 40 is a divisor of 240.
Therefore, the k-beauty is 2.

**Example 2:**

```bash
Input: num = 430043, k = 2
Output: 2
```

Explanation: The following are the substrings of num of length k:

- "43" from " **43** 0043": 43 is a divisor of 430043.
- "30" from "4 **30** 043": 30 is not a divisor of 430043.
- "00" from "43 **00** 43": 0 is not a divisor of 430043.
- "04" from "430 **04** 3": 4 is not a divisor of 430043.
- "43" from "4300 **43** ": 43 is a divisor of 430043.
Therefore, the k-beauty is 2.

**Constraints:**

- `1 <= num <= 10^9`
- `1 <= k <= num.length` (taking `num` as a string)

## Hints/Notes

- sliding window

## Solution

Language: **C++**

```C++
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string numStr = to_string(num), cur;
        int right = 0, n = numStr.size(), res = 0;
        while (right < n) {
            cur.push_back(numStr[right]);
            if (right >= k - 1) {
                int curNum = stoi(cur);
                if (curNum && num % stoi(cur) == 0) {
                    res++;
                }
                cur.erase(cur.begin());
            }
            right++;
        }
        return res;
    }
};
```
