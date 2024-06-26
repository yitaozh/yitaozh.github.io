---
title: 389. Find the Difference
categories: Leetcode
date: 2023-12-26 21:54:07
tags:
    - Hash Table
    - String
    - Bit Manipulation
    - Sorting
---

[389\. Find the Difference](https://leetcode.com/problems/find-the-difference/)

## Description

Difficulty: **Easy**

Related Topics: [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [String](https://leetcode.com/tag/https://leetcode.com/tag/string//), [Bit Manipulation](https://leetcode.com/tag/https://leetcode.com/tag/bit-manipulation//), [Sorting](https://leetcode.com/tag/https://leetcode.com/tag/sorting//)

You are given two strings `s` and `t`.

String `t` is generated by random shuffling string `s` and then add one more letter at a random position.

Return the letter that was added to `t`.

**Example 1:**

```bash
Input: s = "abcd", t = "abcde"
Output: "e"
Explanation: 'e' is the letter that was added.
```

**Example 2:**

```bash
Input: s = "", t = "y"
Output: "y"
```

**Constraints:**

* `0 <= s.length <= 1000`
* `t.length == s.length + 1`
* `s` and `t` consist of lowercase English letters.

## Hints/Notes

* use xor operation

## Solution

Language: **C++**

```C++
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for (char c : s) {
            res ^= c;
        }
        for (char c : t) {
            res ^= c;
        }
        return res;
    }
};
```
