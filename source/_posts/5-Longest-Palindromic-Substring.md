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

* 2023/08/05
* Use a helper function to get the longest palindromic string from one index
* [0x3F's solution](https://leetcode.cn/problems/longest-palindromic-substring/solutions/2958179/mo-ban-on-manacher-suan-fa-pythonjavacgo-t6cx/)(checked)

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
        // the mapping between manacher and the original string:
        // a, b
        // 0, 1
        // =>
        // ^, #, a, #, b, #, $
        // 0, 1, 2, 3, 4, 5, 6
        // s[i] = t[(i + 1) * 2]
        // t[i] = s[i / 2 - 1]
        vector<int> halfLen(manacher.size() - 2, 0);
        int center = 0, right = 0, max_idx = 0;
        for (int i = 2; i < halfLen.size(); i++) {
            int len = 1;
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
            if (len > halfLen[max_idx]) {
                max_idx = i;
            }
        }
        int hl = halfLen[max_idx];
        // in fact we should use hl - 2, because manacher[i + len] != manacher[i - len] and the boundary is '#'
        // so the range in manacher is [max_idx - hl + 2, max_idx + hl - 2]
        // the range in origin is [(max_idx - hl) / 2, (max_idx + hl) / 2 - 2];
        return s.substr((max_idx - hl) / 2, hl - 1);
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
