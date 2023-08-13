---
title: 567. Permutation in String
categories: Leetcode
date: 2023-01-18 23:25:33
tags:
    - Hash Table
    - Two Pointers
    - String
    - Sliding Window
---

# [567\. Permutation in String](https://leetcode.com/problems/permutation-in-string/)

## Description

Difficulty: **Medium**

Related Topics: [Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

Given two strings `s1` and `s2`, return `true` _if_ `s2` _contains a permutation of_ `s1`_, or_ `false` _otherwise_.

In other words, return `true` if one of `s1`'s permutations is the substring of `s2`.

**Example 1:**

```bash
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
```

**Example 2:**

```bash
Input: s1 = "ab", s2 = "eidboaoo"
Output: false
```

**Constraints:**

* 1 <= s1.length, s2.length <= 10<sup>4</sup>
* `s1` and `s2` consist of lowercase English letters.

## Hints/Notes

* Sliding window

```C++
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        return false;
    }
}
```

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (char c : s1) {
            need[c]++;
        }
        int left = 0, right = 0, valid = 0, len = s1.size();
        while (right < s2.size()) {
            char c = s2[right++];
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            if (right - left == len) {
                if (valid == need.size()) {
                    return true;
                }
                c = s2[left++];
                if (need.count(c)) {
                    if (window[c] == need[c]) {
                        valid--;
                    }
                    window[c]--;
                }
            }
        }
        return false;
    }
};
```
