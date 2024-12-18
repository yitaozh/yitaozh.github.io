---
title: 5. Longest Palindromic Substring
categories: Leetcode
date: 2023-01-19 15:43:12
tags:
    - String
    - Dynamic Programming
---

[5\. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)

## Description

Difficulty: **Medium**

Related Topics: [String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

Given a string `s`, return _the longest_ <span data-keyword="palindromic-string">_palindromic_</span> <span data-keyword="substring-nonempty">_substring_</span> in `s`.

**Example 1:**

```bash
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
```

**Example 2:**

```bash
Input: s = "cbbd"
Output: "bb"
```

**Constraints:**

* `1 <= s.length <= 1000`
* `s` consist of only digits and English letters.

## Hints/Notes

* Use a helper function to get the longest palindromic string from one index

## Solution

Language: **C++**

Manacher's algorithm

```C++
class Solution {
public:
    string longestPalindrome(string s) {
        string manacher = "^#";
        for (auto& c : s) {
            manacher.push_back(c);
            manacher.push_back('#');
        }
        manacher.push_back('$');
        vector<int> halfLen(manacher.size(), 0);
        int center = 0, right = 0;
        for (int i = 1; i < manacher.size() - 1; i++) {
            int len = 0;
            if (i < right) {
                len = min(right - i, halfLen[2 * center - i]);
            }
            while (manacher[i + len] == manacher[i - len]) {
                if (i + len > right) {
                    right = i + len;
                    center = i;
                }
                len++;
            }
            halfLen[i] = len;
        }
        int maxLen = 0;
        string res;
        for (int i = 1; i < halfLen.size() - 1; i++) {
            if (halfLen[i] > maxLen) {
                maxLen = halfLen[i];
                string tmp = manacher.substr(i - maxLen + 1, maxLen * 2 - 1);
                tmp.erase(remove(tmp.begin(), tmp.end(), '#'), tmp.end());
                res = tmp;
            }
        }
        return res;
    }
};
```

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
