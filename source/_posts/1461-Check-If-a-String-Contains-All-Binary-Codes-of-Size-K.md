---
title: 1461. Check If a String Contains All Binary Codes of Size K
categories: Leetcode
date: 2024-10-24 23:51:13
tags:
    - Hash Table
    - String
    - Bit Manipulation
    - Rolling Hash
    - Hash Function
---

[1461. Check If a String Contains All Binary Codes of Size K](https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/)

## Description

Given a binary string `s` and an integer `k`, return `true` if every binary code of length `k` is a substring of `s`. Otherwise, return `false`.

**Example 1:**

```bash
Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
```

**Example 2:**

```bash
Input: s = "0110", k = 1
Output: true
Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring.
```

**Example 3:**

```bash
Input: s = "0110", k = 2
Output: false
Explanation: The binary code "00" is of length 2 and does not exist in the array.
```

**Constraints:**

- `1 <= s.length <= 5 * 10^5`
- `s[i]` is either `'0'` or `'1'`.
- `1 <= k <= 20`

## Hints/Notes

- sliding window

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> nums;
        int n = s.size(), numbits = sizeof(int);
        int right = 0, cur = 0, digits = 0;
        while (right < n) {
            cur += s[right] - '0';
            if (right >= k - 1) {
                nums.insert(cur);
                cur &= (1 << k - 1) - 1;
            }
            cur <<= 1;
            right++;
        }
        return nums.size() == (2 << k - 1);
    }
};
```
