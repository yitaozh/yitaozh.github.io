---
title: 3280. Convert Date to Binary
categories: Leetcode
date: 2024-10-08 15:51:21
tags:
    - Math
    - String
---

[3280. Convert Date to Binary](https://leetcode.com/problems/convert-date-to-binary/description/)

## Description

You are given a string `date` representing a Gregorian calendar date in the `yyyy-mm-dd` format.

`date` can be written in its binary representation obtained by converting year, month, and day to their binary representations without any leading zeroes and writing them down in `year-month-day` format.

Return the **binary**  representation of `date`.

**Example 1:**

```bash
Input: date = "2080-02-29"

Output: "100000100000-10-11101"
```

Explanation:

100000100000, 10, and 11101 are the binary representations of 2080, 02, and 29 respectively.

**Example 2:**

```bash
Input: date = "1900-01-01"

Output: "11101101100-1-1"
```

Explanation:

11101101100, 1, and 1 are the binary representations of 1900, 1, and 1 respectively.

**Constraints:**

- `date.length == 10`
- `date[4] == date[7] == '-'`, and all other `date[i]`'s are digits.
- The input is generated such that `date` represents a valid Gregorian calendar date between Jan 1^st, 1900 and Dec 31^st, 2100 (both inclusive).

## Hints/Notes

- 2024/09/03
- decimal to binary
- [0x3F's solution](https://leetcode.cn/problems/convert-date-to-binary/solutions/2909000/ku-han-shu-jian-ji-xie-fa-pythonjavacgo-ohojk/)(checked)
- Weekly Contest 414

## Solution

Language: **C++**

A more elegant way to make decimal number binary

```C++
class Solution {
public:
    string convertDateToBinary(string date) {
        string res = convertDate(date.substr(0, 4)) + "-" + convertDate(date.substr(5, 2)) + "-" + convertDate(date.substr(8, 2));
        return res;
    }

    string convertDate(string s) {
        string res = bitset<32>(stoi(s)).to_string();
        return res.substr(res.find('1'));
    }
};
```

```C++
class Solution {
public:
    string convertDateToBinary(string date) {
        string res = convertDate(date.substr(0, 4)) + "-" + convertDate(date.substr(5, 2)) + "-" + convertDate(date.substr(8, 2));
        return res;
    }

    string convertDate(string s) {
        int value = stoi(s);
        string res;
        while (value != 0) {
            int tmp = value % 2;
            res.push_back(tmp + '0');
            value /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```
