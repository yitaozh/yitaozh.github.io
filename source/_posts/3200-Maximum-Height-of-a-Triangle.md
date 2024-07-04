---
title: 3200. Maximum Height of a Triangle
categories: Leetcode
date: 2024-07-03 23:38:33
tags:
    - Array
    - Enumeration
---

[3200. Maximum Height of a Triangle](https://leetcode.com/problems/maximum-height-of-a-triangle/description/)

## Description

You are given two integers `red` and `blue` representing the count of red and blue colored balls. You have to arrange these balls to form a triangle such that the 1^st row will have 1 ball, the 2^nd row will have 2 balls, the 3^rd row will have 3 balls, and so on.

All the balls in a particular row should be the **same** color, and adjacent rows should have **different** colors.

Return the **maximum** height of the triangle that can be achieved.

**Example 1:**

```bash
Input: red = 2, blue = 4

Output: 3
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/06/16/brb.png" style="width: 300px; height: 240px; padding: 10px;">

The only possible arrangement is shown above.

**Example 2:**

```bash
Input: red = 2, blue = 1

Output: 2
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/06/16/br.png" style="width: 150px; height: 135px; padding: 10px;"><br>
The only possible arrangement is shown above.

**Example 3:**

```bash
Input: red = 1, blue = 1

Output: 1
```

**Example 4:**

```bash
Input: red = 10, blue = 1

Output: 2
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/06/16/br.png" style="width: 150px; height: 135px; padding: 10px;"><br>
The only possible arrangement is shown above.

**Constraints:**

- `1 <= red, blue <= 100`

## Hints/Notes

- Weekly Contest 404

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int odd = 0, even = 0;
        for (int i = 1; i <= 100; i++) {
            if (i % 2) {
                odd += i;
            } else {
                even += i;
            }
            if ((max(odd, even) > max(red, blue)) ||
                (min(odd, even) > min(red, blue))) {
                return i - 1;
            }
        }
        return 1;
    }
};
```
