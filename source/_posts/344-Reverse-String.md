---
title: 344. Reverse String
categories: Leetcode
date: 2023-01-19 15:25:27
tags:
    - Two Pointers
    - String
---

# [344\. Reverse String](https://leetcode.com/problems/reverse-string/)

## Description

Difficulty: **Easy**

Related Topics: [Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/)

Write a function that reverses a string. The input string is given as an array of characters `s`.

You must do this by modifying the input array [in-place](https://en.wikipedia.org/wiki/In-place_algorithm) with `O(1)` extra memory.

**Example 1:**

```
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
```

**Example 2:**

```
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
```

**Constraints:**

*   1 <= s.length <= 10<sup>5</sup>
*   `s[i]` is a [printable ascii character](https://en.wikipedia.org/wiki/ASCII#Printable_characters).

## Solution

Language: ****

```
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            char c = s[right];
            s[right] = s[left];
            s[left] = c;
            left++;
            right--;
        }
    }
};
```