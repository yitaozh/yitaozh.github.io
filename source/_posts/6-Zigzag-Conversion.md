---
title: 6. Zigzag Conversion
categories: Leetcode
date: 2025-05-03 01:22:10
tags:
    - String
---

[6. Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion/description/?envType=company&envId=google&favoriteSlug=google-three-months)

## Description

The string <code>"PAYPALISHIRING"</code> is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

```bash
P   A   H   N
A P L S I I G
Y   I   R
```

And then read line by line: <code>"PAHNAPLSIIGYIR"</code>

Write the code that will take a string and make this conversion given a number of rows:

```bash
string convert(string s, int numRows);
```

**Example 1:**

```bash
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
```

**Example 2:**

```bash
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
```

**Example 3:**

```bash
Input: s = "A", numRows = 1
Output: "A"
```

**Constraints:**

- <code>1 <= s.length <= 1000</code>
- <code>s</code> consists of English letters (lower-case and upper-case), <code>','</code> and <code>'.'</code>.
- <code>1 <= numRows <= 1000</code>

## Hints/Notes

- 2025/04/28 Q1
- string
- [Leetcode solution](https://leetcode.com/problems/zigzag-conversion/editorial)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<string> rows(numRows);
        int n = s.size(), curRow = 0, curDir = 1;
        for (int i = 0; i < n; i++) {
            rows[curRow].push_back(s[i]);
            curRow += curDir;
            if (curRow == numRows) {
                curRow = numRows - 2;
                curDir = -1;
            } else if (curRow == -1) {
                curRow = 1;
                curDir = 1;
            }
        }
        string res;
        for (auto& row : rows) {
            res += row;
        }
        return res;
    }
};
```
