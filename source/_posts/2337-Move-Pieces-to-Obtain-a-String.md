---
title: 2337. Move Pieces to Obtain a String
categories: Leetcode
date: 2025-05-03 17:13:06
tags:
    - Two Pointers
    - String
---

[2337. Move Pieces to Obtain a String](https://leetcode.com/problems/move-pieces-to-obtain-a-string/description/?envType=company&envId=google&favoriteSlug=google-three-months)

## Description

You are given two strings <code>start</code> and <code>target</code>, both of length <code>n</code>. Each string consists **only**  of the characters <code>'L'</code>, <code>'R'</code>, and <code>'_'</code> where:

- The characters <code>'L'</code> and <code>'R'</code> represent pieces, where a piece <code>'L'</code> can move to the **left**  only if there is a **blank**  space directly to its left, and a piece <code>'R'</code> can move to the **right**  only if there is a **blank**  space directly to its right.
- The character <code>'_'</code> represents a blank space that can be occupied by **any**  of the <code>'L'</code> or <code>'R'</code> pieces.

Return <code>true</code> if it is possible to obtain the string <code>target</code> by moving the pieces of the string <code>start</code> **any**  number of times. Otherwise, return <code>false</code>.

**Example 1:**

```bash
Input: start = "_L__R__R_", target = "L______RR"
Output: true
Explanation: We can obtain the string target from start by doing the following moves:
- Move the first piece one step to the left, start becomes equal to "**L** ___R__R_".
- Move the last piece one step to the right, start becomes equal to "L___R___**R** ".
- Move the second piece three steps to the right, start becomes equal to "L______**R** R".
Since it is possible to get the string target from start, we return true.
```

**Example 2:**

```bash
Input: start = "R_L_", target = "__LR"
Output: false
Explanation: The 'R' piece in the string start can move one step to the right to obtain "_**R** L_".
After that, no pieces can move anymore, so it is impossible to obtain the string target from start.
```

**Example 3:**

```bash
Input: start = "_R", target = "R_"
Output: false
Explanation: The piece in the string start can move only to the right, so it is impossible to obtain the string target from start.
```

**Constraints:**

- <code>n == start.length == target.length</code>
- <code>1 <= n <= 10^5</code>
- <code>start</code> and <code>target</code> consist of the characters <code>'L'</code>, <code>'R'</code>, and <code>'_'</code>.

## Hints/Notes

- 2025/04/30 Q2
- string
- [0x3F's solution](https://leetcode.cn/problems/move-pieces-to-obtain-a-string/solutions/1658923/nao-jin-ji-zhuan-wan-pythonjavacgo-by-en-9sqt)

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool canChange(string start, string target) {
        string s = start, t = target;
        s.erase(remove(s.begin(), s.end(), '_'), s.end());
        t.erase(remove(t.begin(), t.end(), '_'), t.end());
        if (s != t) {
            return false;
        }
        for (int i = 0, j = 0; i < start.length(); i++) {
            if (start[i] == '_') {
                continue;
            }
            while (target[j] == '_') {
                j++;
            }
            if (i != j && (start[i] == 'L') == (i < j)) {
                return false;
            }
            j++;
        }
        return true;
    }
};
```
