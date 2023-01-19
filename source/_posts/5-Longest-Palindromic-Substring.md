---
title: 5. Longest Palindromic Substring
categories: Leetcode
date: 2023-01-19 15:43:12
tags:
    - String
    - Dynamic Programming
---

# [5\. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)

## Description

Difficulty: **Medium**

Related Topics: [String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

Given a string `s`, return _the longest_ <span data-keyword="palindromic-string">_palindromic_</span> <span data-keyword="substring-nonempty">_substring_</span> in `s`.

**Example 1:**

```
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
```

**Example 2:**

```
Input: s = "cbbd"
Output: "bb"
```

**Constraints:**

*   `1 <= s.length <= 1000`
*   `s` consist of only digits and English letters.

## Solution

Language: **C++**

```C++
class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for (int i = 0; i < s.size(); i++) {
            string s1 = palindrom(s, i, i);
            string s2 = palindrom(s, i, i + 1);
            res = res.size() > s1.size() ? res : s1;
            res = res.size() > s2.size() ? res : s2;
        }
        return res;
    }

    string palindrom(string s, int left, int right) {
        while (left >= 0 && right < s.size()) {
            if (s[left] != s[right]) {
                break;
            }
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
};
```