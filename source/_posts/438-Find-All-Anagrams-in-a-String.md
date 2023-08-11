---
title: 438. Find All Anagrams in a String
categories: Leetcode
date: 2023-01-18 23:41:02
tags:
    - Hash Table
    - String
    - Sliding Window
---

# [438\. Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

## Description

Difficulty: **Medium**

Related Topics: [Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

Given two strings `s` and `p`, return _an array of all the start indices of_ `p`_'s anagrams in_ `s`. You may return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

**Example 1:**

```text
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
```

**Example 2:**

```text
Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
```

**Constraints:**

* 1 <= s.length, p.length <= 3 * 10<sup>4</sup>
* `s` and `p` consist of lowercase English letters.

## Hints/Notes

* Sliding window

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        for (char c : p) need[c]++;
        int left = 0, right = 0, valid = 0, len = p.size();
        vector<int> res;
        while (right < s.size()) {
            char c = s[right++];
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            if (right - left == len) {
                if (valid == need.size()) {
                    res.push_back(left);
                }
                c = s[left++];
                if (need.count(c)) {
                    if (window[c] == need[c]) {
                        valid--;
                    }
                    window[c]--;
                }
            }
        }
        return res;
    }
};
```
