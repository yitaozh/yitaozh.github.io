---
title: 3234. Count the Number of Substrings With Dominant Ones
categories: Leetcode
date: 2024-08-14 23:48:20
tags:
    - String
    - Sliding Window
    - Enumeration
---

[3234. Count the Number of Substrings With Dominant Ones](https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/description/)

## Description

You are given a binary string `s`.

Return the number of substrings with **dominant**  ones.

A string has **dominant**  ones if the number of ones in the string is **greater than or equal to**  the **square**  of the number of zeros in the string.

**Example 1:**

```bash
Input: s = "00011"

Output: 5
```

Explanation:

The substrings with dominant ones are shown in the table below.

<table><thead><tr><th>i</th><th>j</th><th>s[i..j]</th><th>Number of Zeros</th><th>Number of Ones</th></tr></thead><tbody><tr><td>3</td><td>3</td><td>1</td><td>0</td><td>1</td></tr><tr><td>4</td><td>4</td><td>1</td><td>0</td><td>1</td></tr><tr><td>2</td><td>3</td><td>01</td><td>1</td><td>1</td></tr><tr><td>3</td><td>4</td><td>11</td><td>0</td><td>2</td></tr><tr><td>2</td><td>4</td><td>011</td><td>1</td><td>2</td></tr></tbody></table>

**Example 2:**

```bash
Input: s = "101101"

Output: 16
```

Explanation:

The substrings with **non-dominant**  ones are shown in the table below.

Since there are 21 substrings total and 5 of them have non-dominant ones, it follows that there are 16 substrings with dominant ones.

<table><thead><tr><th>i</th><th>j</th><th>s[i..j]</th><th>Number of Zeros</th><th>Number of Ones</th></tr></thead><tbody><tr><td>1</td><td>1</td><td>0</td><td>1</td><td>0</td></tr><tr><td>4</td><td>4</td><td>0</td><td>1</td><td>0</td></tr><tr><td>1</td><td>4</td><td>0110</td><td>2</td><td>2</td></tr><tr><td>0</td><td>4</td><td>10110</td><td>2</td><td>3</td></tr><tr><td>1</td><td>5</td><td>01101</td><td>2</td><td>3</td></tr></tbody></table>

**Constraints:**

- `1 <= s.length <= 4 * 10^4`
- `s` consists only of characters `'0'` and `'1'`.

## Hints/Notes

- Weekly Contest 408

## Solution

Language: **C++**

```C++
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> zeros;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                zeros.push_back(i);
            }
        }
        int total1 = s.size() - zeros.size();
        zeros.push_back(s.size());
        int res = 0, zeroIdx = 0;
        for (int left = 0; left < s.size(); left++) {
            // 1, 1, 0, 0, 1, 0, 1
            // at start zeroIdx = 0, cnt0 = 0, zeros[i] = 2, cnt1 = 2
            for (int i = zeroIdx; i < zeros.size() - 1; i++) {
                int cnt0 = i - zeroIdx + 1;
                if (cnt0 * cnt0 > total1) {
                    break;
                }
                int cnt1 = zeros[i] - left - (i - zeroIdx);
                int p = zeros[i], q = zeros[i + 1];
                // cnt0 is the number of 0 from left to ith zero
                // cnt1 is the number of 1 from left to ith zero
                if (cnt0 * cnt0 <= cnt1) {
                    // in this case, all following p, p + 1 ... q - 1 is
                    // suitable
                    res += q - p;
                } else {
                    // in this case, we need 1 from the next segment
                    res += max(q - p - (cnt0 * cnt0 - cnt1), 0);
                }
            }
            if (s[left] == '0') {
                zeroIdx++;
            } else {
                res += zeros[zeroIdx] - left;
                total1--;
            }
        }
        return res;
    }
};
```
