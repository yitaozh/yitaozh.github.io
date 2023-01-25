---
title: 28. Find the Index of the First Occurrence in a String
categories: Leetcode
date: 2023-01-25 13:02:15
tags:
    - Two Pointers
    - String
    - String Matching
---

# [28\. Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)

## Description

Difficulty: **Medium**

Related Topics: [Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/), [String Matching](https://leetcode.com/tag/string-matching/)

Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

**Example 1:**

```text
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
```

**Example 2:**

```text
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
```

**Constraints:**

* 1 <= haystack.length, needle.length <= 10<sup>4</sup>
* `haystack` and `needle` consist of only lowercase English characters.

## Solution

Language: **C++**

```C++
class Solution {
public:
    int strStr(string haystack, string needle) {
        int patHash = 0, left = 0, right = 0, powHash = 1, prime = 9999991, R = 26;
        for (char c : needle) {
            patHash = (patHash * R + (c - 'a')) % prime;
        }
        for (int i = 0; i < needle.size() - 1; i++) {
            powHash = powHash * R % prime;
        }
        int sumHash = 0;
        while (right < haystack.size()) {
            int num = haystack[right++] - 'a';
            sumHash = (sumHash * R + num) % prime;
            if (right - left == needle.size()) {
                if (sumHash == patHash && haystack.substr(left, right - left) == needle) {
                    return left;
                } else {
                    sumHash = ((sumHash - (haystack[left++] - 'a') * powHash) % prime + prime) % prime;
                }
            }
        }
        return -1;
    }
};
```
