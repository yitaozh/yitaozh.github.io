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

- 2024/08/02
- enumerate on the left index of the subarray
- [0x3F's solution](https://leetcode.cn/problems/count-the-number-of-substrings-with-dominant-ones/solutions/2860198/mei-ju-zi-chuan-zhong-de-0-de-ge-shu-pyt-c654/)
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
        int totalOne = s.size() - zeros.size();
        int zeroIdx = 0, res = 0;
        zeros.push_back(s.size());
        // start from 0, we want to calculate the number of dominant substring
        // with l as subString left index
        for (int left = 0; left < s.size(); left++) {
            // the meaning of the inner for loop:
            //  we calculate the number of zero and one up to jth zero(included)
            //  then we check the if the numZero and numOne fits the need
            //  if it fits, then all indexes starting from the jth zero,
            //  but before the (j+1)th zero works
            //  if it doesn't fit, then we need 1 from the next segment
            for (int j = zeroIdx; j < zeros.size() - 1; j++) {
                int numZero = j - zeroIdx + 1;
                if (numZero * numZero > totalOne) {
                    break;
                }
                int numOne = zeros[j] + 1 - left - numZero;
                int p = zeros[j], q = zeros[j + 1];
                if (numZero * numZero <= numOne) {
                    res += q - p;
                } else {
                    res += max(0, q - p + numOne - numZero * numZero);
                }
            }
            if (s[left] == '0') {
                zeroIdx++;
            } else {
                // from l to the left of first 0, all strings are valid
                res += zeros[zeroIdx] - left;
                totalOne--;
            }
        }
        return res;
    }
};
```
