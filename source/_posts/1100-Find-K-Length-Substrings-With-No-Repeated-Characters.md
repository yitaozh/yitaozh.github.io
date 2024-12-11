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

- 2024/10/20
- sliding window
- premium

## Solution

Language: **C++**

```C++
class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int n = s.size(), right = 0, res = 0, valid = 0;
        vector<int> m(26, 0);
        while (right < n) {
            char c = s[right];
            m[c - 'a']++;
            if (m[c - 'a'] == 1) {
                valid++;
            }
            if (right >= k - 1) {
                if (valid == k) {
                    res++;
                }
                char l = s[right - k + 1];
                m[l - 'a']--;
                if (m[l - 'a'] == 0) {
                    valid--;
                }
            }
            right++;
        }
        return res;
    }
};
```
