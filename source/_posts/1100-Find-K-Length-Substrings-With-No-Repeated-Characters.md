---
title: 1100. Find K-Length Substrings With No Repeated Characters
categories: Leetcode
date: 2024-10-25 21:22:25
tags:
    - Hash Table
    - String
    - Sliding Window
---

[1100. Find K-Length Substrings With No Repeated Characters](https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/description/)

## Description

Given a string `s` and an integer `k`, return the number of substrings in `s` of length `k` with no repeated characters.

**Example 1:**

```bash
Input: s = "havefunonleetcode", k = 5
Output: 6
Explanation: There are 6 substrings they are: 'havef','avefu','vefun','efuno','etcod','tcode'.
```

**Example 2:**

```bash
Input: s = "home", k = 5
Output: 0
Explanation: Notice k can be larger than the length of s. In this case, it is not possible to find any substring.
```

**Constraints:**

- `1 <= s.length <= 10^4`
- `s` consists of lowercase English letters.
- `1 <= k <= 10^4`

## Hints/Notes

- sliding window

## Solution

Language: **C++**

```C++
class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int n = s.size(), right = 0, res = 0;
        unordered_map<int, int> m;
        while (right < n) {
            char c = s[right];
            m[c]++;
            if (right >= k - 1) {
                if (m.size() == k) {
                    res++;
                }
                char l = s[right - k + 1];
                m[l]--;
                if (m[l] == 0) {
                    m.erase(l);
                }
            }
            right++;
        }
        return res;
    }
};
```
