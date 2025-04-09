---
title: 925. Long Pressed Name
categories: Leetcode
date: 2025-04-09 17:04:25
tags:
    - Two Pointers
    - String
---

[925. Long Pressed Name](https://leetcode.com/problems/long-pressed-name/description/?envType=company&envId=linkedin&favoriteSlug=linkedin-six-months)

## Description

Your friend is typing his `name` into a keyboard. Sometimes, when typing a character `c`, the key might get long pressed, and the character will be typed 1 or more times.

You examine the `typed` characters of the keyboard. Return `True` if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

**Example 1:**

```bash
Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
```

**Example 2:**

```bash
Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it was not in the typed output.
```

**Constraints:**

- `1 <= name.length, typed.length <= 1000`
- `name` and `typed` consist of only lowercase English letters.

## Hints/Notes

- 2025/04/09 Q1
- two pointers
- [Leetcode solution](https://leetcode.com/problems/long-pressed-name/editorial)

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int l1 = 0, l2 = 0;
        while (l1 < name.size() && l2 < typed.size()) {
            int start1 = l1, start2 = l2;
            if (name[l1] != typed[l2]) {
                return false;
            }
            while (l1 < name.size() && name[l1] == name[start1]) {
                l1++;
            }
            while (l2 < typed.size() && typed[l2] == typed[start2]) {
                l2++;
            }
            if (l1- start1 > l2 - start2) {
                return false;
            }
        }
        if (l1 != name.size() || l2 != typed.size()) {
            return false;
        }
        return true;
    }
};
```
