---
title: 242. Valid Anagram
categories: Leetcode
date: 2023-12-18 18:12:35
tags:
    - Hash Table
    - String
    - Sorting
---

[242\. Valid Anagram](https://leetcode.com/problems/valid-anagram/)

## Description

Difficulty: **Easy**

Related Topics: [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [String](https://leetcode.com/tag/https://leetcode.com/tag/string//), [Sorting](https://leetcode.com/tag/https://leetcode.com/tag/sorting//)

Given two strings `s` and `t`, return `true` _if_ `t` _is an anagram of_ `s`_, and_ `false` _otherwise_.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

**Example 1:**

```bash
Input: s = "anagram", t = "nagaram"
Output: true
```

**Example 2:**

```bash
Input: s = "rat", t = "car"
Output: false
```

**Constraints:**

* 1 <= s.length, t.length <= 5 * 10<sup>4</sup>
* `s` and `t` consist of lowercase English letters.

**Follow up:** What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

## Hints/Notes

* 2023/12/18
* array is faster than map
* [0x3F's solution](https://leetcode.cn/problems/valid-anagram/solutions/2802865/jian-dan-ti-jian-dan-zuo-pythonjavaccgoj-m89c/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool isAnagram(string s, string t) {
        int c = 0;
        array<int, 26> count{};
        for (char& c : s) {
            count[c - 'a']++;
        }
        for (char c : t) {
            count[c - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }
        return count == array<int, 26>{};
    }
};
```
