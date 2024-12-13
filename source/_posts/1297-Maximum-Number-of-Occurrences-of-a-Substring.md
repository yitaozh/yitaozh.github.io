---
title: 1297. Maximum Number of Occurrences of a Substring
categories: Leetcode
date: 2024-10-24 23:56:14
tags:
    - Hash Table
    - String
    - Sliding Window
---

[1297. Maximum Number of Occurrences of a Substring](https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/description/)

## Description

Given a string `s`, return the maximum number of occurrences of **any**  substring under the following rules:

- The number of unique characters in the substring must be less than or equal to `maxLetters`.
- The substring size must be between `minSize` and `maxSize` inclusive.

**Example 1:**

```bash
Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
Output: 2
Explanation: Substring "aab" has 2 occurrences in the original string.
It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).
```

**Example 2:**

```bash
Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
Output: 2
Explanation: Substring "aaa" occur 2 times in the string. It can overlap.
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `1 <= maxLetters <= 26`
- `1 <= minSize <= maxSize <= min(26, s.length)`
- `s` consists of only lowercase English letters.

## Hints/Notes

- 2024/10/16
- sliding window
- because every larger subString must contains smaller subString, we should only care about the subStrings with minSize
- can use string_view but there's no need
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size(), left = 0, right = 0, res = 0;
        unordered_map<int, int> m;
        unordered_map<string, int> freq;
        while (right < s.size()) {
            char c = s[right];
            m[c]++;
            if (right >= minSize - 1) {
                if (m.size() <= maxLetters) {
                    string tmp = s.substr(left, minSize);
                    freq[tmp]++;
                    res = max(res, freq[tmp]);
                }
                char l = s[left++];
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
