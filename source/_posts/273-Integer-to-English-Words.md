---
title: 273. Integer to English Words
categories: Leetcode
date: 2025-02-03 00:05:32
tags:
    - Math
    - String
    - Recursion
---

[273. Integer to English Words](https://leetcode.com/problems/integer-to-english-words/description/)

## Description

Convert a non-negative integer `num` to its English words representation.

**Example 1:**

```bash
Input: num = 123
Output: "One Hundred Twenty Three"
```

**Example 2:**

```bash
Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
```

**Example 3:**

```bash
Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
```

**Constraints:**

- `0 <= num <= 2^31 - 1`

## Hints/Notes

- 2025/02/02 Q2
- string
- TODO: modify to recursive solution
- [Leetcode solution](https://leetcode.com/problems/integer-to-english-words/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<string> underTwenty = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                                  "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                                  "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string numberToWords(int num) {
        if (!num) {
            return "Zero";
        }
        string numStr = to_string(num);
        string res;
        // 1,234,567,890
        // 9,876,543,210
        if ((numStr.size() - 1) / 3 >= 3) {
            int len = numStr.size() % 3;
            if (!len) len = 3;
            int billion = stoi(numStr.substr(0, len));
            res += within_thousand(billion) + " Billion";
            numStr.erase(0, len);
        }
        if ((numStr.size() - 1) / 3 >= 2) {
            int len = numStr.size() % 3;
            if (!len) len = 3;
            int million = stoi(numStr.substr(0, len));
            if (million) {
                if (!res.empty()) res += " ";
                res += within_thousand(million) + " Million";
            }
            numStr.erase(0, len);
        }
        if ((numStr.size() - 1) / 3 >= 1) {
            int len = numStr.size() % 3;
            if (!len) len = 3;
            int thousand = stoi(numStr.substr(0, len));
            if (thousand) {
                if (!res.empty()) res += " ";
                res += within_thousand(thousand) + " Thousand";
            }
            numStr.erase(0, len);
        }
        int len = numStr.size() % 3;
        if (!len) len = 3;
        num = stoi(numStr.substr(0, len));
        if (num) {
            if (!res.empty()) res += " ";
            res += within_thousand(num);
        }
        return res;
    }

    string within_thousand(int num) {
        string res;
        if (num >= 100) {
            int hundred = num / 100;
            num %= 100;
            res += underTwenty[hundred] + " Hundred";
        }
        if (!num) {
            return res;
        }
        if (!res.empty()) {
            res += " ";
        }
        if (num >= 20) {
            int ten = num / 10;
            int digit = num % 10;
            res += tens[ten - 2];
            if (digit != 0) {
                res += " " + underTwenty[digit];
            }
        } else {
            res += underTwenty[num];
        }
        return res;
    }
};
```
